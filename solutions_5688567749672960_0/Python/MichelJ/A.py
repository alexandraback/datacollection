# Round 1B 2015
# Problem A. Counter Culture
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

def rev(x):
    s = str(x)[::-1]
    return int(s)

def solve(N):
    a = [2000000000 for i in xrange(1000001)]
    a[1] = 1
    for i in xrange(1,N):
        a[i+1] = min(a[i+1], a[i]+1)
        ir = rev(i)
        if a[i]+1 < a[ir]:
            a[ir] = a[i]+1
#            if a[i]+1 < a[ir]:
#                a[ir] = a[i]+1
    return str(a[N])
    
def main(data=None):
    if data is not None:
        sys.stdin = StringIO.StringIO(data)
    for tc in xrange(1, int(raw_input()) + 1):
        N = int(raw_input())
        print 'Case #%d: %s' % (tc, solve(N))
    if data is not None:
        sys.stdin = sys.__stdin__

sample="""3
1
19
23
"""


# Call main() only if run from command line, not from IDLE
if __name__ == "__main__":
    if True:
#    if '/' not in sys.argv[0] and '\\' not in sys.argv[0]:
        logging.basicConfig(level=logging.INFO)
        sys.exit(main())
    else:
        logging.basicConfig(level=logging.INFO,format=" %(levelname)s: %(message)s")
