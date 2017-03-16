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
#from operator import itemgetter
from collections import defaultdict
#from collections import deque
#from array import array
#from bisect import bisect
#from math import sqrt

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

def construct_days_strengths(attack_days, attack_location, attack_stength):
    days_strength = defaultdict(list)
    for t in attack_days:
        for day, loc, strength in zip(attack_days[t], attack_location[t],
                                      attack_stength[t]):
            days_strength[day].append((loc, strength))
    return days_strength

EPSILON = .1

def nb_breaches(attack_days, attack_location, attack_stength):
    days_strength = construct_days_strengths(attack_days, attack_location,
                                             attack_stength)
    nb_success = 0
    wall = defaultdict(int)
    for day in sorted(days_strength):
        LOG.debug('before day: %d, wall: %s' % (day, wall))
        # count successes
        for loc, strength in days_strength[day]:
            w, e = loc
            success = False
            first = True
            for x in xrange(w, e):
                if (wall[x + EPSILON] < strength
                or (not first and wall[x - EPSILON] < strength)):
                    success = True
                    LOG.debug('success on day: %d, at pos: %d, with strength: %d'
                              % (day, x, strength))
                    break
                first = False
            if success:
                nb_success += 1
        # increase wall height
        for loc, strength in days_strength[day]:
            w, e = loc
            if wall[w + EPSILON] < strength:
                wall[w + EPSILON] = strength
            for x in xrange(w + 1, e):
                if wall[x + EPSILON] < strength:
                    wall[x + EPSILON] = strength
                if wall[x - EPSILON] < strength:
                    wall[x - EPSILON] = strength
            if wall[e - EPSILON] < strength:
                wall[e - EPSILON] = strength
    LOG.debug('wall at end: %s' % wall)
    return nb_success


def do_job(in_file, out_file=sys.stdout):
    'Do the work'
    LOG.debug('Start working with files: %s and %s'
              % (in_file.name, out_file.name))
    # first line is number of test cases
    T = int(in_file.readline())
    for testcase in xrange(T):
        N = int(in_file.readline())
        attack_days = dict()
        attack_stength = dict()
        attack_location = dict()
        for t in xrange(N):
            di, ni, wi, ei, si, d_di, d_pi, d_si = map(int,
                                                       in_file.readline().split())
            attack_days[t] = [di + d_di * n for n in xrange(ni)]
            attack_stength[t] = [si + d_si * n for n in xrange(ni)]
            attack_location[t] = [(wi + n * d_pi, ei + n * d_pi)
                                  for n in xrange(ni)]
        result = nb_breaches(attack_days, attack_location, attack_stength)
        print_output(out_file, testcase, result)

def print_output(out_file, testcase, result):
    'Formats and print result'
    print('Case #%d:' % (testcase + 1), end=' ', file=out_file)
    print(result, file=out_file)
    #print('%.6g' % result, file=out_file)


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
