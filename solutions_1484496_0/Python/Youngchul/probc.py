#!/usr/bin/env python
"""
Problem C. Equal Sums
Round 1B 2012, Google Code Jam

5 May 2012

"""
import itertools
import logging
import sys


def setup_parser():
    from optparse import OptionParser
    usage = 'usage: %prog [options] <input file>'
    parser = OptionParser(usage=usage)
    parser.add_option('-v', '--verbose', dest='verbose', action='count',
                      help='increase verbosity')
    return parser


def setup_logging(options):
    log_level = logging.WARNING
    if options.verbose == 1:
        log_level = logging.INFO
    elif options.verbose >= 2:
        log_level = logging.DEBUG
    logging.basicConfig(level=log_level)


def compute(n, integers):
    result = []
    sums = {}
    for i in xrange(1, n):
        for combi in itertools.combinations(integers, i):
            s = sum(combi)
            if s in sums:
                return True, set(combi), sums[s]
            else:
                sums[s] = set(combi)
    return False, 'impossible', 'impossible'

def main(argv=None):
    if argv is None:
        argv = sys.argv

    parser = setup_parser()
    options, args = parser.parse_args()
    setup_logging(options)

    if len(args) < 1:
        parser.print_help()
        return 2

    try:
        with open(args[0], 'r') as f:
            lines = [line.strip() for line in f.readlines()]
    except IOError, err:
        print >>sys.stderr, err
        return 1

    t = int(lines.pop(0))
    for i in xrange(t):
        line = [int(x) for x in lines[i].split()]
        print 'Case #%d:' % (i + 1,)
        possible, set1, set2 = compute(line[0], line[1:])
        if possible:
            print ' '.join([str(i) for i in set1])
            print ' '.join([str(i) for i in set2])
        else:
            print set1

    return 0


if __name__ == '__main__':
    sys.exit(main())
