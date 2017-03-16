#!/usr/bin/env python
# vim: set fileencoding=utf-8 :
'''Module docstring
Template version: 1.0
'''

from __future__ import division, print_function
from optparse import OptionParser
import sys
import os
import functools
import logging
#import heapq
from operator import mul #itemgetter
#from collections import defaultdict

# for interactive call: do not add multiple times the handler
if 'LOG' not in locals():
    LOG = None
LOG_LEVEL = logging.INFO
FORMATER_STRING = ('%(asctime)s - %(filename)s:%(lineno)d - '
                   '%(levelname)s - %(message)s')

def configure_log(level=LOG_LEVEL, log_file=None):
    'Configure logger'
    if LOG:
        LOG.setLevel(level)
        return LOG
    log = logging.getLogger('%s log' % os.path.basename(__file__))
    if log_file:
        handler = logging.FileHandler(filename=log_file)
    else:
        handler = logging.StreamHandler(sys.stderr)
    log_formatter = logging.Formatter(FORMATER_STRING)
    handler.setFormatter(log_formatter)
    log.addHandler(handler)
    log.setLevel(level)
    return log

LOG = configure_log()

class memoized(object):
    '''Decorator that caches a function's return value each time it is called.
    If called later with the same arguments, the cached value is returned, and
    not re-evaluated.
    '''
    def __init__(self, func):
        self.func = func
        self.cache = {}
    def __call__(self, *args):
        try:
            return self.cache[args]
        except KeyError:
            value = self.func(*args)
            self.cache[args] = value
            return value
        except TypeError:
            # uncachable -- for instance, passing a list as an argument.
            # Better to not cache than to blow up entirely.
            return self.func(*args)
    def __repr__(self):
        '''Return the function's docstring.'''
        return self.func.__doc__
    def __get__(self, obj, objtype):
        '''Support instance methods.'''
        return functools.partial(self.__call__, obj)

class CommentedFile:
    'Implements comments skip for file'
    def __init__(self, f, commentstring='#'):
        self.f = f
        self.commentstring = commentstring
    def next(self):
        'The next line but skips comments'
        line = self.f.next()
        while line.startswith(self.commentstring):
            line = self.f.next()
        return line
    def __iter__(self):
        return self

def compute_percentages(s, N, X):
    '''Return the percentages of votes for each contestant to be qualified
    '''
    X = sum(s)
    return [2. / N - ji / X for ji in s]
    #return [(x if x > 0 else 0) for x in tmp_res]

def other_computation(s, N, X, results):
    '''Eliminate negative results
    '''
    nb_playing = 0
    X_playing = 0
    for i, value in enumerate(results):
        if value > 0:
            nb_playing += 1
            X_playing += s[i]
    A = (X_playing + X) / nb_playing
    new_results = []
    for i, ji in enumerate(s):
        if results[i] == 0:
            new_results.append(0)
        else:
            new_results.append((A - ji) / X)
    return new_results

def do_job(in_file, out_file=sys.stdout):
    'Do the work'
    LOG.debug('Start working with files: %s and %s'
              % (in_file.name, out_file.name))
    # first line is number of test cases
    T = int(in_file.readline())
    for testcase in xrange(T):
        LOG.debug('testcase: %d' % (testcase + 1))
        values = in_file.readline().strip().split()
        N = int(values[0])
        s = map(int, values[1:])
        assert len(s) == N
        X = sum(s)
        results = compute_percentages(s, N, X)
        final_values = [ji + X * yi for yi, ji in zip(results, s)]
        LOG.debug('first results %s' % results)
        LOG.debug('first final values obtained %s' % final_values)
        new_results = []
        for yi, fi in zip(results, final_values):
            if yi > 0:
                new_results.append(yi)
            else:
                new_results.append(0)
        if sum(new_results) - 1 > 1e-12:
            #cur_sum = sum(new_results)
            #final_results = [x / cur_sum for x in new_results]
            final_results = other_computation(s, N, X, new_results)
        else:
            final_results = new_results
        LOG.debug('final results %s' % final_results)
        new_final_values = [ji + X * yi for yi, ji in zip(final_results, s)]
        LOG.debug('final values obtained %s' % new_final_values)
        assert sum(final_results) - 1 <= 1e-12, sum(final_results)
        assert all([(x >= 0 and x <= 1) for x in final_results])
        print_output(out_file, testcase, final_results)

def print_output(out_file, testcase, results):
    'Formats and print result'
    print('Case #%d:' % (testcase + 1), end=' ', file=out_file)
    print(' '.join(['%.6f' % (100 * x) for x in results]), file=out_file)

def main(argv=None):
    'Program wrapper'
    if argv is None:
        argv = sys.argv[1:]
    usage = '%prog [-v] [-w out_file] [-t] in_file'
    parser = OptionParser(usage=usage)
    parser.add_option('-t', dest='template', action='store_true', default=False,
                      help=('template name for construct'
                            'out file name as in_file.out (default False)'))
    parser.add_option('-w', dest='out_file',
            help=('output file or stdout if FILE is - (default case)'
                  'or TEMPLATE.out (default if template is given)'))
    parser.add_option('-v', '--verbose', dest='verbose',
            action='store_true', default=False,
            help = 'run as verbose mode')
    (options, args) = parser.parse_args(argv)
    if len(args) != 1:
        parser.error('only one input file accepted')
    if options.verbose:
        LOG.setLevel(logging.DEBUG)
#    # unset verbose for easy option check
#    options.verbose = False
#    if not any(options.__dict__.values()):
#        parser.error('Must provide at least one option')
    if args[0] == '-':
        in_file = sys.stdin
    else:
        try:
            in_file = open(args[0], 'r')
        except IOError:
            parser.error('File, %s, does not exist.' % args[0])
    if options.template and not options.out_file:
        options.out_file = ''.join((args[0], '.out'))
    if not options.out_file or options.out_file == '-':
        out_file = sys.stdout
    else:
        try:
            out_file = open(options.out_file, 'w')
        except IOError:
            parser.error('Problem opening file: %s' % options.out_file)
    sys.setrecursionlimit(2**30-1)
    do_job(in_file, out_file)
    return 0

if __name__ == '__main__':
    import doctest
    doctest.testmod()
    sys.exit(main())
