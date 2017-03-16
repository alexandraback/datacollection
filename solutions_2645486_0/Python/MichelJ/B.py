# Google Code Jam 2013 Round 1A
# Problem B. Manage your energy
# mjacquem1

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

def manage1(E,maxE,R,N,v):
    if N==1:
        return v[0]*E
    return max((v[0]*spend + manage1(min(maxE,E+R-spend),maxE,R,N-1,v[1:])) for spend in xrange(0,E+1))

def main(data=None):
    if data is not None:
        sys.stdin = StringIO.StringIO(data)
    for tc in xrange(1, int(raw_input()) + 1):
        (E,R,N) =  map(int,raw_input().split(' '))
        v = map(int,raw_input().split(' '))
        print 'Case #%d: %s' % (tc, manage1(E,E,R,N,v))
    if data is not None:
        sys.stdin = sys.__stdin__

sample="""3
5 2 2
2 1
5 2 2
1 2
3 3 4
4 1 3 5
"""


# Call main() only if run from command line, not from IDLE
if __name__ == "__main__":
    if True:
#    if '/' not in sys.argv[0] and '\\' not in sys.argv[0]:
        logging.basicConfig(level=logging.ERROR)
        sys.exit(main())
    else:
        logging.basicConfig(level=logging.INFO,format=" %(levelname)s: %(message)s")
