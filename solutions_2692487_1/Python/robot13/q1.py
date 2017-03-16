import math

def func(x, L):
    if(len(L) == 0):
        return 0
    if(x == 1):
        return len(L)
    if(x <= L[0]):
        #print(x, "xxx", len(L))
        return min(len(L), 1+func(x+x-1, L))
    else:
        #print(x, "yyy", L)
        return func(x+L[0], L[1:])
        
t = int(input())

for CASE in range(1, t+1):
    x = input().split()
    A = int(x[0])
    N = int(x[1])
    x = input().split()
    motes = []
    for i in range(N):
        motes.append(int(x[i]))
    
    motes.sort()
    
        
    print("Case #%d: %d"%(CASE, func(A, motes)))