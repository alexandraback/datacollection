import numpy as np
import sys
import string

def solve(K,C,S):
    if C*S<K:
        return []
    else:
        lst=[]
        for i in range(0,K,C):
            curr=[]
            for j in range(C):
                if i+j<K:
                    curr.append(i+j)
                else:
                    curr.append(0)
            lst.append(curr)
        ans=[]
        for ele in lst:
            s = 0
            for e in ele:
                s=s*K+e
            s=s+1
            ans.append(s)
        return ans

f=open(sys.argv[1])
f.readline()
for e,ln in enumerate(f):
    K,C,S = [int(ele) for ele in string.split(ln)]
    print "Case #"+str(e+1)+":", 
    ans=solve(K,C,S)
    if len(ans)==0:
        print "IMPOSSIBLE",
    else:
        for ele in ans:
            print ele,
    print
        
        
