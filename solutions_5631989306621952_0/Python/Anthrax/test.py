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
    #K,C,S = [int(x) for x in input().split()]
    S = input()
    ans = solve(S)
    print("Case #%d: %s" % (t+1,ans))
    
    
