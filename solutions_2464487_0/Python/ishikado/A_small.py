import math

def solve(r,t):
    ub=t
    lb=0
    while(ub-lb>1):
        mid=(ub+lb)/2
        val=2*mid*mid+(2*r-1)*mid
        if val<=t:
            lb=mid
        else:
            ub=mid
    return lb

n=int(raw_input())
for i in range(0,n):
    r,t=map(int,raw_input().split(' '))
    print "Case #"+str(i+1)+": "+str(solve(r,t))
    
    
