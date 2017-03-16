import sys
from random import randint

from collections import Counter,deque
from itertools import combinations
import itertools


IS_LOCAL = False
try:
    import os
    IS_LOCAL = os.getenv("AGLAE") == "nondual" and os.getenv("SIDONIE") == "improbable"
except:
    pass

def read_ints(inp = sys.stdin):
    return list(map(int,next(inp).strip().split()))

def gen_primes(memo=[], D={}, last=[2]):
    for p in memo:
        yield p
    q = last[0]
    while True:
        if q not in D:
            memo.append(q)
            D[q * q] = [q]
            last[0]=q+1
            yield q
        else:
            for p in D[q]:
                D.setdefault(p + q, []).append(p)
            del D[q]
        q += 1

def get_divisor(x):
    for p in gen_primes():
        if x%p == 0:
            return p
        if p*p>x:
            return 1

def sol1(N,J):
    res = []
    cand = 2**N - 1
    # modu = 8*9*5*7
    # found = False
    while len(res)<J:
        cstr = bin(cand)[2:]
        # print(cand,cstr)
        xs = [cand] + [int(cstr,b) for b in range(3,11)]
        cert=[]
        for x in xs:
            p = get_divisor(x)
            if p>1:
                cert.append(p)
            else:
                break
        else:
            res.append(" ".join([cstr] + list(map(str,cert))))
        # if found:
        #     cand -= modu
        # else:
        #     cand -= 2
        cand -= 2

    return res

if IS_LOCAL:
    inp = iter(map(str,[1,"16 50"]))
    # inp = sys.stdin
    # inp = open("A-small-attempt0.in")
else:
    inp = sys.stdin

T ,= read_ints(inp)
# T=1
mm = 0
for t in range(T):
    N,J =read_ints(inp)
    res = sol1(N,J)
    # if i>=mm:
    #     print(N,i,x)
    #     mm=i
    print("Case #%d:" % (t+1,) )
    print("\n".join(res))
