'''
Created on 12/04/2014

@author: david
'''
from lib2to3.fixer_util import p1
from _hashlib import new

#f=open("exampleA.txt")
f=open("A-small-attempt1.in")
#f=open("A-large.in")

T=int(f.readline())
P=[]
for i in range(T):
    P.append(int(f.readline()))

def solve(p):
    old = {1:1}
    new = {}
    seen = set()
    seen.add(1)
    while p not in old:
        for k,v in old.items():      
            k1 = k+1
            if k1 not in seen:
                seen.add(k1)
                new[k1] = v+1
                if k>11:
                    k2 = str(k)
                    k2 = list(k2)
                    k2.reverse()
                    k2 = int(''.join(k2))
                    if k2>k:
                        #print(k,k2)
                        seen.add(k2)
                        new[k2] = v+1
        old = new
        new = {}
    return old[p]
       
fRes = open("res.txt", "w")
case=0
for p in P:
    #print(p)
    case+=1
    sol = solve(p)
    print("Case #{}: {}".format(case,sol))
    fRes.write("Case #{}: {}\n".format(case,sol))
        
fRes.close()