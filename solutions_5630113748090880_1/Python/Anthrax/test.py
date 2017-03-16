import sys
sys.setrecursionlimit(100000000)

answer = ""

def solve(S,bans="",eans=""):
    if S=="":
        return bans+eans
    
    maxi = None
    maxv = '\0'
    for i,s in enumerate(S):
        if ord(s)>=ord(maxv):
            maxv = s
            maxi = i

    b = S[:maxi]
    e = S[maxi+1:]

    #print(b,bans+maxv,eans+e)

    return solve(b,bans+maxv,e+eans)
    
T = int(input())

for t in range(T):
    N = int(input())

    L = []
    for i in range(2*N-1):
        L.append((int(x) for x in input().split()))

    D = {}
    for l in L:
        for h in l:
            if h in D:
                D[h] += 1
            else:
                D[h] = 1
    
    a = [k for k,v in D.items() if v%2==1]

    print("Case #%d:" % (t+1), end="")
    for e in sorted(a):
        print(" %d" % (e),end="")
    print()

