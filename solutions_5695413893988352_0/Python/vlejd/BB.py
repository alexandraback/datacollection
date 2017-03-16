import numpy as np
import sys
from itertools import product


def expand(q):
    sint = map(str, range(10))
    ans = []
    for c in product(sint, repeat=len(q)):
        ok = True
        for w,e in zip(q,c):
            if not(w=="?" or w==e):
                ok=False
                break
        if ok:
            ans.append(int("".join(c)))
    return ans

def form(q,w):
    return ("0"*len(w) + str(q))[-len(w):]

def solve(t):
    print "Case #%d:"%(t+1),
    q,w = raw_input().split()
    ans = [999999, 999999, 99999]
    for (x,y) in product (expand(q), expand(w)):
        nc = [abs(x-y),x,y]
        if nc<ans:
            ans = nc
    
    print form(ans[1], q), form(ans[2],q)
    
    
def main():
    T = input()
    for i in xrange(T):
        solve(i)
    
if __name__=="__main__":
    main()