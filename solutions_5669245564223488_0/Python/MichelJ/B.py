# Round 1C 2014
# Problem B. Reordering Train Cars
# MichelJ

import sys
import logging
import StringIO
from itertools import *
from math import factorial
from collections import *

def echo(fn):
    def wrapped(*v, **k):
        name = fn.__name__
        logging.info( "Called %s(%s)" % (name, ", ".join(map(repr, chain(v, k.values())))) )
        res = fn(*v, **k)
        logging.info( "       %s(%s) returned %s" % (name, ", ".join(map(repr, chain(v, k.values()))),res) )
        return res
    return wrapped

def reduce_string(s):
    res = [s[0]]
    for c in s[1:]:
        if res[-1]!=c:
            res.append(c)
    return "".join(res)

def check(s):
    s2 = reduce_string(s)
    for c in s2:
        if s2.count(c)>1:
            return False
    return True

# brute-force
def solvebf(ls):
    res=0
    for ls2 in permutations(ls):
        s = "".join(ls2)
        if check(s):
            res += 1
    return res

def solve(ls):
    l = len(ls)
    ls = map(reduce_string,ls)
    for i in xrange(l):
        if not check(ls[i]):
            return 0
        for c in ls[i][1:-1]:
            for j in xrange(l):
                if j!=i:
                    if c in ls[j]:
                        return 0
    cc = {s:i for i,s in enumerate(ls)}
    for i,s1 in enumerate(ls):
        for j,s2 in enumerate(ls):
            if i!=j:
                if s1[-1]==s2[0]:
                    minc = min(cc[s1],cc[s2])
                    maxc = max(cc[s1],cc[s2])
                    cc[s1] = minc
                    cc[s2] = minc
                    for k in cc.keys():
                        if cc[k]==maxc:
                            cc[k]=minc
#    print cc
    cc2 = defaultdict(list)
    for k,v in cc.items():
        for i in xrange(ls.count(k)):
            cc2[v].append(k)
#    print cc2
    res = 1
    for ls2 in cc2.values():
        res *= solvebf(ls2)
    res *= factorial(len(cc2))
    res = res%1000000007
    return str(res)
            

def main(data=None):
    if data is not None:
        sys.stdin = StringIO.StringIO(data)
    for tc in xrange(1, int(raw_input()) + 1):
        ll = int(raw_input())
        ls = raw_input().split(" ")
        print 'Case #%d: %s' % (tc, solve(ls))
    if data is not None:
        sys.stdin = sys.__stdin__

sample="""4
8
zzzzzzzzzzllll jjjjjjjjjkkkkkkkk vvvvvvvvvvv bbbzz vvvrrrrjj kkkkkiiiiiccc cccccbbbbb pv
3
ab bbbc cd
4
aa aa bc c
2
abc bcd
"""


# Call main() only if run from command line, not from IDLE
if __name__ == "__main__":
    if True:
#    if '/' not in sys.argv[0] and '\\' not in sys.argv[0]:
        logging.basicConfig(level=logging.ERROR)
        sys.exit(main())
    else:
        logging.basicConfig(level=logging.INFO,format=" %(levelname)s: %(message)s")
