# Google Code Jam 2013
# Problem B. Lawnmower
# mjacquem1

import sys
import logging
import StringIO
import math
from itertools import chain

def echo(fn):
    def wrapped(*v, **k):
        name = fn.__name__
        logging.info( "Called %s(%s)" % (name, ", ".join(map(repr, chain(v, k.values())))) )
        res = fn(*v, **k)
        logging.info( "       %s(%s) returned %s" % (name, ", ".join(map(repr, chain(v, k.values()))),res) )
        return res
    return wrapped

def lawnmover(a,n,m):
    for i in xrange(n):
        for j in xrange(m):
            aij = a[i][j]
            ok1=True
            for k in xrange(n):
                ok1 = ok1 and aij>=a[k][j]
            ok2=True
            for l in xrange(m):
                ok2 = ok2 and aij>=a[i][l]
            if not (ok1 or ok2):
                return "NO"
    return "YES"

def main(data=None):
    if data is not None:
        sys.stdin = StringIO.StringIO(data)
    for tc in xrange(1, int(raw_input()) + 1):
        (n,m) = map(int,raw_input().split(' '))
        a = [map(int,raw_input().split(' ')) for i in xrange(n)]
        print 'Case #%d: %s' % (tc, lawnmover(a,n,m))
    if data is not None:
        sys.stdin = sys.__stdin__

sample="""3
3 3
2 1 2
1 1 1
2 1 2
5 5
2 2 2 2 2
2 1 1 1 2
2 1 2 1 2
2 1 1 1 2
2 2 2 2 2
1 3
1 2 1
"""


# Call main() only if run from command line, not from IDLE
if __name__ == "__main__":
    if True:
#    if '/' not in sys.argv[0] and '\\' not in sys.argv[0]:
        logging.basicConfig(level=logging.ERROR)
        sys.exit(main())
    else:
        logging.basicConfig(level=logging.INFO,format=" %(levelname)s: %(message)s")
