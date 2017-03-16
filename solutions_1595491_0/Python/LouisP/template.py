#!/usr/bin/env python
# vim: set fileencoding=utf-8 :
'''Module docstring
Template version: 1.0
Problem

You're watching a show where Googlers (employees of Google) dance, and then
each dancer is given a triplet of scores by three judges. Each triplet of
scores consists of three integer scores from 0 to 10 inclusive. The judges have
very similar standards, so it's surprising if a triplet of scores contains two
scores that are 2 apart. No triplet of scores contains scores that are more
than 2 apart.

For example: (8, 8, 8) and (7, 8, 7) are not surprising. (6, 7, 8) and (6, 8,
8) are surprising. (7, 6, 9) will never happen.

The total points for a Googler is the sum of the three scores in that Googler's
triplet of scores. The best result for a Googler is the maximum of the three
scores in that Googler's triplet of scores. Given the total points for each
Googler, as well as the number of surprising triplets of scores, what is the
maximum number of Googlers that could have had a best result of at least p?

For example, suppose there were 6 Googlers, and they had the following total
points: 29, 20, 8, 18, 18, 21. You remember that there were 2 surprising
triplets of scores, and you want to know how many Googlers could have gotten a
best result of 8 or better.

With those total points, and knowing that two of the triplets were surprising,
the triplets of scores could have been:

10 9 10
6 6 8 (*)
2 3 3
6 6 6
6 6 6
6 7 8 (*)

The cases marked with a (*) are the surprising cases. This gives us 3 Googlers
who got at least one score of 8 or better. There's no series of triplets of
scores that would give us a higher number than 3, so the answer is 3.

Input

The first line of the input gives the number of test cases, T. T test cases
follow. Each test case consists of a single line containing integers separated
by single spaces. The first integer will be N, the number of Googlers, and the
second integer will be S, the number of surprising triplets of scores. The
third integer will be p, as described above. Next will be N integers ti: the
total points of the Googlers.  Output

For each test case, output one line containing "Case #x: y", where x is the
case number (starting from 1) and y is the maximum number of Googlers who could
have had a best result of greater than or equal to p.  Limits

1 ≤ T ≤ 100.
0 ≤ S ≤ N.
0 ≤ p ≤ 10.
0 ≤ ti ≤ 30.
At least S of the ti values will be between 2 and 28, inclusive.
Small dataset

1 ≤ N ≤ 3.
Large dataset

1 ≤ N ≤ 100.
Sample

Input
4
3 1 5 15 13 11
3 0 8 23 22 21
2 1 1 8 0
6 2 8 29 20 8 18 18 21

Output

Case #1: 3
Case #2: 2
Case #3: 1
Case #4: 3
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

def get_best_score(score, surprising=False):
    '''Return the best possible score
    >>> get_best_score(23, False)
    8
    >>> get_best_score(22, False)
    8
    >>> get_best_score(21, False)
    7
    >>> get_best_score(0, False)
    0
    >>> get_best_score(0, True)
    0
    >>> get_best_score(1, False)
    1
    >>> get_best_score(1, True)
    1
    >>> get_best_score(2, False)
    1
    >>> get_best_score(2, True)
    2
    >>> get_best_score(3, False)
    1
    >>> get_best_score(3, True)
    2
    '''
    if score == 0:
        return 0
    if score == 1:
        return 1
    if surprising:
        offset = 2
    else:
        offset = 0
    for i in range(3):
        if (score + offset + i) > 30:
            return -1
        if (score + offset + i) % 3 == 0:
            return (score + offset + i) // 3
    else:
        return -1

def get_nb_better_result(S, p, scores):
    '''Return the nb of people that could have had a better score than p
    >>> get_nb_better_result(1, 5, [15, 13, 11])
    3
    >>> get_nb_better_result(0, 8, [23, 22, 21])
    2
    >>> get_nb_better_result(1, 1, [8, 0])
    1
    >>> get_nb_better_result(2, 8, [29, 20, 8, 18, 18, 21])
    3
    '''
    nb_better_results = 0
    for score in sorted(scores):
        if get_best_score(score, surprising=False) >= p:
            nb_better_results += 1
        elif S > 0 and get_best_score(score, surprising=True) >= p:
            nb_better_results += 1
            S -= 1
    return nb_better_results

def do_job(in_file, out_file=sys.stdout):
    'Do the work'
    LOG.debug('Start working with files: %s and %s'
              % (in_file.name, out_file.name))
    # first line is number of test cases
    T = int(in_file.readline())
    for testcase in xrange(T):
        values = map(int, in_file.readline().split())
        N = values[0]
        S = values[1]
        p = values[2]
        scores = values[3:]
        # for integer input
        # for other inputs
#        values = in_file.readline().rstrip('\n')
        assert len(scores) == N
        result = get_nb_better_result(S, p, scores)
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
    sys.setrecursionlimit(2**30-2)
    do_job(in_file, out_file)
    return 0

if __name__ == '__main__':
    import doctest
    doctest.testmod()
    sys.exit(main())
