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
#from collections import defaultdict
import math

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

def is_palindrome(value):
    test = str(value)
    return test == ''.join(reversed(test))

def get_squares(A, B):
    first_root = int(math.ceil(math.sqrt(A)))
    last_root = int(math.floor(math.sqrt(B)))
    return [nb**2 for nb in xrange(first_root, last_root + 1)]

def find_fair_squares(A, B):
    squares = get_squares(A, B)
    LOG.debug('nb squares: %d' % len(squares))
    result = 0
    for square in squares:
        if not is_palindrome(square):
            continue
        root = int(math.sqrt(square))
        if is_palindrome(root):
            result += 1
    return result

def construct_fair_squares(largest_nb):
    fair_squares = {}
    cur_squares = set()
    for n in xrange(1, largest_nb + 1):
        square = n**2
        if is_palindrome(square) and is_palindrome(n):
            cur_squares = cur_squares.union([square])
        fair_squares[n] = cur_squares
    return fair_squares

def count_fair_squares(largest_nb):
    cur_nb = 1
    n = 1
    cur_square = n**2
    fair_squares = {0: 0, 1: 1}
    while cur_square <= largest_nb:
        n += 1
        cur_square = n**2
        if is_palindrome(cur_square) and is_palindrome(n):
            cur_nb += 1
        fair_squares[cur_square] = cur_nb
    return fair_squares

def do_job(in_file, out_file=sys.stdout):
    'Do the work'
    LOG.debug('Start working with files: %s and %s'
              % (in_file.name, out_file.name))
    # first line is number of test cases
    T = int(in_file.readline())
    #largest_nb = int(1000)
    largest_nb = int(1e14)
    #root = int(math.floor(math.sqrt(largest_nb))) + 1
    nb_fair_squares = count_fair_squares(largest_nb)
    keys = nb_fair_squares.keys()
    LOG.debug('squares found: %s' % keys)
    #LOG.debug('max squares found: %s' % nb_fair_squares)
    #LOG.debug('max squares found: %d' % len(nb_fair_squares[root]))
    #LOG.debug('squares found for %d: %s' % (root, nb_fair_squares[root]))
    for testcase in xrange(T):
        A, B = map(int, in_file.readline().split())
        assert A <= B
        #result = find_fair_squares(A, B)
        start = int(math.floor(math.sqrt(A)))**2
        if start == A:
            start = (int(math.floor(math.sqrt(A))) - 1)**2
        end = int(math.floor(math.sqrt(B)))**2
        LOG.debug('A, B: %d, %d' % (A, B))
        LOG.debug('start, end: %d, %d' % (start, end))
#        to_remove = 0
#        for square in nb_fair_squares[end]:
#            if square < A:
#                to_remove += 1
        result = nb_fair_squares[end] - nb_fair_squares[start]
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
