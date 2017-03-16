#!/usr/bin/env python
# vim: set fileencoding=utf-8 :
'''Module docstring
Template version: 1.0

Problem

Do you ever become frustrated with television because you keep seeing the same
things, recycled over and over again? Well I personally don't care about
television, but I do sometimes feel that way about numbers.

Let's say a pair of distinct positive integers (n, m) is recycled if you can
obtain m by moving some digits from the back of n to the front without changing
their order. For example, (12345, 34512) is a recycled pair since you can
obtain 34512 by moving 345 from the end of 12345 to the front. Note that n and
m must have the same number of digits (excluding leading zeros) in order to be
a recycled pair.

Given integers A and B with the same number of digits, how many distinct
recycled pairs (n, m) are there with A ≤ n < m ≤ B?

Input

The first line of the input gives the number of test cases, T. T test cases
follow. Each test case consists of a single line containing the integers A and
B.

Output

For each test case, output one line containing "Case #x: y", where x is the
case number (starting from 1), and y is the number of recycled pairs (n, m)
with A ≤ n < m ≤ B.

Limits

1 ≤ T ≤ 50.
A and B have the same number of digits.
Small dataset

1 ≤ A ≤ B ≤ 1000.
Large dataset

1 ≤ A ≤ B ≤ 2000000.
Sample

Input

4
1 9
10 40
100 500
1111 2222

Output

Case #1: 0
Case #2: 3
Case #3: 156
Case #4: 287

'''

from __future__ import division, print_function
from optparse import OptionParser
import sys
import os
import functools
import logging

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

def switch_digit(n, i):
    '''Return a string with the i last digits of n in front
    >>> switch_digit(12345, 0)
    '12345'
    >>> switch_digit(12345, 1)
    '51234'
    >>> switch_digit(12345, 2)
    '45123'
    >>> switch_digit(12345, 3)
    '34512'
    >>> switch_digit(12345, 4)
    '23451'
    >>> switch_digit(12345, 5)
    '54321'
    '''
    n_str = str(n)
    if i == 0:
        return n_str
    if i == len(n_str):
        return ''.join(reversed(n_str))
    return (n_str[-i:] + n_str[:len(n_str) - i]).lstrip('0')

def is_recycled_pair(n, m):
    '''Indicate if a pair is recycled
    >>> is_recycled_pair(12345, 34512)
    True
    '''
    if n == m:
        return True
    for i in xrange(n):
        if switch_digit(n, i) == str(m):
            return True
    return False

def get_recycled_pairs(n):
    '''Return the list of possible recycled pairs
    >>> get_recycled_pairs(10)
    []
    >>> get_recycled_pairs(11)
    []
    >>> get_recycled_pairs(12)
    [21]
    >>> get_recycled_pairs(102)
    [210]
    >>> get_recycled_pairs(103)
    [310]
    >>> get_recycled_pairs(12345)
    [51234, 45123, 34512, 23451]
    '''
    result = []
    n_len = len(str(n))
    for i in xrange(1, n_len):
        possible_pair = switch_digit(n, i)
        if len(possible_pair) == n_len:
            result.append(int(possible_pair))
    if n in result:
        result.remove(n)
    return result

def get_nb_recycled_pairs(A, B):
    '''Return the nb of recycled pairs
    >>> get_nb_recycled_pairs(1, 9)
    0
    >>> get_nb_recycled_pairs(10, 40)
    3
    >>> get_nb_recycled_pairs(100, 500)
    156
    >>> get_nb_recycled_pairs(1111, 2222)
    287
    '''
    result = set()
    for n in xrange(A, B + 1):
        recycled_pairs = get_recycled_pairs(n)
        for pair_nb in recycled_pairs:
            if pair_nb <= B and pair_nb > n:
                result.add((n, pair_nb))
    return len(result)

def do_job(in_file, out_file=sys.stdout):
    'Do the work'
    LOG.debug('Start working with files: %s and %s'
              % (in_file.name, out_file.name))
    # first line is number of test cases
    T = int(in_file.readline())
    for testcase in xrange(T):
        #N = int(in_file.readline())
        # for integer input
        A, B = map(int, in_file.readline().split())
        # for other inputs
#        values = in_file.readline().rstrip('\n')
        assert len(str(A)) == len(str(B))
        result = get_nb_recycled_pairs(A, B)
        print_output(out_file, testcase, result)

def print_output(out_file, testcase, result):
    'Formats and print result'
    print('Case #%d:' % (testcase + 1), end=' ', file=out_file)
    print(result, file=out_file)

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
        parser.error('only input file accepted')
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
