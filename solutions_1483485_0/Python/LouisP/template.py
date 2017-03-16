#!/usr/bin/env python
# vim: set fileencoding=utf-8 :
'''Module docstring
Template version: 1.0
Problem

We have come up with the best possible language here at Google, called
Googlerese. To translate text into Googlerese, we take any message and replace
each English letter with another English letter. This mapping is one-to-one and
onto, which means that the same input letter always gets replaced with the same
output letter, and different input letters always get replaced with different
output letters. A letter may be replaced by itself. Spaces are left as-is.

For example (and here is a hint!), our awesome translation algorithm includes
the following three mappings: 'a' -> 'y', 'o' -> 'e', and 'z' -> 'q'. This
means that "a zoo" will become "y qee".

Googlerese is based on the best possible replacement mapping, and we will never
change it. It will always be the same. In every test case. We will not tell you
the rest of our mapping because that would make the problem too easy, but there
are a few examples below that may help.

Given some text in Googlerese, can you translate it to back to normal text?
Solving this problem

Usually, Google Code Jam problems have 1 Small input and 1 Large input. This
problem has only 1 Small input. Once you have solved the Small input, you have
finished solving this problem.  Input

The first line of the input gives the number of test cases, T. T test cases
follow, one per line.

Each line consists of a string G in Googlerese, made up of one or more words
containing the letters 'a' - 'z'. There will be exactly one space (' ')
character between consecutive words and no spaces at the beginning or at the
end of any line.  Output

For each test case, output one line containing "Case #X: S" where X is the case
number and S is the string that becomes G in Googlerese.  Limits

1 ≤ T ≤ 30.
G contains at most 100 characters.
None of the text is guaranteed to be valid English.
Sample Input

3
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv


Output

Case #1: our language is impossible to understand
Case #2: there are twenty six factorial possibilities
Case #3: so it is okay if you want to just give up

'''

from __future__ import division, print_function
from optparse import OptionParser
import sys
import os
import functools
import logging
import string

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

TRANSLATION = {'a': 'y', 'o': 'e', 'z': 'q',
               'y': 'a', 'e': 'o', 'q': 'z'}

INPUT = ['ejp mysljylc kd kxveddknmc re jsicpdrysi',
         'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd',
         'de kr kd eoya kw aej tysr re ujdr lkgc jv']

OUTPUT = ['our language is impossible to understand',
          'there are twenty six factorial possibilities',
          'so it is okay if you want to just give up']

def fill_translation():
    for in_line, out_line in zip(INPUT, OUTPUT):
        assert len(in_line) == len(out_line)
        for in_letter, out_letter in zip(in_line, out_line):
            TRANSLATION[in_letter] = out_letter
    LOG.debug(TRANSLATION)
    assert len(TRANSLATION) == 27
    in_string = ''.join(TRANSLATION.keys())
    out_string = ''.join(TRANSLATION.values())
    return string.maketrans(in_string, out_string)

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


def do_job(in_file, out_file=sys.stdout):
    'Do the work'
    translation = fill_translation()
    LOG.debug('Start working with files: %s and %s'
              % (in_file.name, out_file.name))
    # first line is number of test cases
    T = int(in_file.readline())
    for testcase in xrange(T):
        #N = int(in_file.readline())
        # for integer input
        #values = map(int, in_file.readline().split())
        # for other inputs
        values = in_file.readline().rstrip('\n')
        #assert len(values) == N
        result = values.translate(translation)
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
    #sys.setrecursionlimit(2**31-1)
    do_job(in_file, out_file)
    return 0

if __name__ == '__main__':
    import doctest
    doctest.testmod()
    sys.exit(main())
