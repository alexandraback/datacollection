#b search for optimum y for player i, accuracy: 10^-5
def bsearch(i):
    if check(i,0): return 0
    lo,hi = 0,1
    while (hi - lo) > 0.000000001:
        mid = (lo + hi) / 2
        if check(i, mid):
            hi = mid
        else:
            lo = mid
    return lo

#returns true if Player i can avoid elim with y frac of audience votes:
def check(i, y):
    target = S[i] + y*X
    have = X*(1-y)
    for j in range(1,N+1):
        if i == j: continue
        if S[j] < target:
            have -= (target - S[j])
        if have < 0: return True
    return False

#main code:
f = open("A-large.in",'r')
T = int(f.readline())
for t in range(T):
     S = [int(x) for x in f.readline().split()]
     N = S[0]
     X = sum(S)-N
     # number contestants from 1..N
     print("Case #"+str(t+1)+":",*[bsearch(i)*100 for i in range(1,N+1)])
