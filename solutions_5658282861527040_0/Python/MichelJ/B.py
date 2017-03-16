# Round 1B 2014
# Problem B. New Lottery Game
# MichelJ

import sys
import logging
import StringIO
from itertools import chain

def echo(fn):
    def wrapped(*v, **k):
        name = fn.__name__
        logging.info( "Called %s(%s)" % (name, ", ".join(map(repr, chain(v, k.values())))) )
        res = fn(*v, **k)
        logging.info( "       %s(%s) returned %s" % (name, ", ".join(map(repr, chain(v, k.values()))),res) )
        return res
    return wrapped

# brute force

def solve1(a,b,k):
    res = 0
    for x in xrange(a):
        for y in xrange(b):
            if x&y<k:
                res+=1
    return str(res)

def main(data=None):
    if data is not None:
        sys.stdin = StringIO.StringIO(data)
    for tc in xrange(1, int(raw_input()) + 1):
        a,b,k = map(int,raw_input().split(" "))
        print 'Case #%d: %s' % (tc, solve1(a,b,k))
    if data is not None:
        sys.stdin = sys.__stdin__

sample="""5
3 4 2
4 5 2
7 8 5
45 56 35
103 143 88
"""


# Call main() only if run from command line, not from IDLE
if __name__ == "__main__":
    if True:
#    if '/' not in sys.argv[0] and '\\' not in sys.argv[0]:
        logging.basicConfig(level=logging.ERROR)
        sys.exit(main())
    else:
        logging.basicConfig(level=logging.INFO,format=" %(levelname)s: %(message)s")
