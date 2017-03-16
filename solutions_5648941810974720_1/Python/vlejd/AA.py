import numpy as np
import sys
sys.setrecursionlimit(999999)
words = ("ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE")

def emp():
    return np.array([0]*26)

def code(i):
    q = [0]*26
    for x in i:
        q[ord(x)-ord('A')]+=1
    return np.array(q)

cowrds = map(code, words)

def o(x):
    return ord(x)-ord('A')


def solve(t):
    print "Case #%d:"%(t+1),
    s = raw_input()
    cs = code(s)
    ans = []
    
    for (q,w) in [(0,"Z"),(2,"W"),(6,"X"),(8,"G"),(3, "H"), (7,"S"), (5,"V"), (9,"I"), (1,"E"), (4,"F") ]:
        r  =cs[o(w)]
        ans+= [q]*r
        cs = cs - (cowrds[q]*r)
        
    
    print "".join(map(str,sorted(ans)))
    
    
def main():
    T = input()
    for i in xrange(T):
        solve(i)
    
if __name__=="__main__":
    main()