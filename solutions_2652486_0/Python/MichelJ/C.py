# Google Code Jam 2013 Round 1A
# Problem C. Good luck
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

sol3 = { (0,0,0,0):"222", (0,0,0,1):"555", (0,0,0,2):"555",
         (0,0,1,0):"333", (0,0,1,1):"335", (0,0,1,2):"355",
         (0,0,2,0):"333", (0,0,2,1):"335",
         (0,1,0,0):"222", (0,1,0,1):"225", (0,1,0,2):"255",
         (0,1,1,0):"223", (0,1,1,1):"235",
         (0,1,2,0):"233", (0,1,0,2):"255",
         (0,2,0,0):"444", (0,2,0,1):"445", (0,2,0,2):"455",
         (0,2,1,0):"344", (0,2,1,1):"345",
         (0,2,2,0):"334",
         (0,3,0,0):"222", (0,3,0,1):"245",
         (0,3,1,0):"234",
         (0,4,0,0):"224", (0,4,0,1):"445", (0,4,1,0):"344",
         (0,0,2,0):"333", (0,0,2,1):"335",
         (1,1,0,0):"222", (1,1,0,1):"225", (1,1,0,2):"255",
         (1,1,1,0):"223", (1,1,1,1):"235",
         (1,1,2,0):"233", (1,1,0,2):"255",
         (1,2,0,0):"224", (1,2,0,1):"245",
         (1,2,1,0):"234",
         (1,3,0,0):"222", (1,3,0,1):"245",
         (1,3,1,0):"234",
         (1,4,0,0):"224"
}

def solve1(p):
    n3=0
    n5=0
    n2=0
    n2s=0
    for v in p:
        if v%125==0:
            return "555"
        if v%25==0:
            n5=2
        elif v%5==0:
            n5=max(n5,1)
        if v%27==0:
            return "333"
        if v%9==0:
            n3=2
        elif v%3==0:
            n3=max(n3,1)
        if v%64==0:
            return "444"
        if v%32==0:
            return "244"
        if v%16==0:
            n2=4
        elif v%8==0:
            n2=max(n2,3)
            n2s=1
        elif v%4==0:
            n2=max(n2,2)
        elif v%2==0:
            n2s=1
            n2=max(n2,1)
    return sol3[(n2s,n2,n3,n5)]
    
def main(data=None):
    if data is not None:
        sys.stdin = StringIO.StringIO(data)
    for tc in xrange(1, int(raw_input()) + 1):
        print 'Case #%d:' % tc
        (R,N,M,K) =  map(int,raw_input().split(' '))
        for r in xrange(R):
            p = map(int,raw_input().split(' '))
            print solve1(p)
    if data is not None:
        sys.stdin = sys.__stdin__

sample="""1
2 3 4 4
9 4 36 1
1 1 1 1
"""


# Call main() only if run from command line, not from IDLE
if __name__ == "__main__":
    if True:
#    if '/' not in sys.argv[0] and '\\' not in sys.argv[0]:
        logging.basicConfig(level=logging.ERROR)
        sys.exit(main())
    else:
        logging.basicConfig(level=logging.INFO,format=" %(levelname)s: %(message)s")
