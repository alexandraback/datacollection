# Qualification Round 2014
# Problem D. Deceitful War
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

def solve(naomi, ken):
    l = len(naomi)
    res2 = 0
    ken2 = ken[:]
    for n in naomi:
        kmin = 1.0
        for k in ken2:
            if k>n and k<kmin:
                kmin=k
        if kmin==1.0:
            res2 += 1
            kmin = min(ken2)
        ken2.remove(kmin)
    res1 = 0
    naomi2 = naomi[:]
    for k in ken:
        nmin = 1.0
        for n in naomi2:
            if n>k and n<nmin:
                nmin=n
        if nmin==1.0:
            res1 += 1
            nmin = min(naomi2)
        naomi2.remove(nmin)
        
    return l-res1, res2
    
def main(data=None):
    if data is not None:
        sys.stdin = StringIO.StringIO(data)
    for tc in xrange(1, int(raw_input()) + 1):
        n = int(raw_input())
        naomi = map(float,raw_input().split(' '))
        ken = map(float,raw_input().split(' '))
        (res1,res2) = solve(naomi, ken)
        print 'Case #%d: %d %d' % (tc, res1, res2)
    if data is not None:
        sys.stdin = sys.__stdin__

sample="""4
1
0.5
0.6
2
0.7 0.2
0.8 0.3
3
0.5 0.1 0.9
0.6 0.4 0.3
9
0.186 0.389 0.907 0.832 0.959 0.557 0.300 0.992 0.899
0.916 0.728 0.271 0.520 0.700 0.521 0.215 0.341 0.458

"""


# Call main() only if run from command line, not from IDLE
if __name__ == "__main__":
    if True:
#    if '/' not in sys.argv[0] and '\\' not in sys.argv[0]:
        logging.basicConfig(level=logging.ERROR)
        sys.exit(main())
    else:
        logging.basicConfig(level=logging.INFO,format=" %(levelname)s: %(message)s")
