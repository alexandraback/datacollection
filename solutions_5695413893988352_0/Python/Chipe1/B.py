t=int(input())

def enum(s):
    if s is '':
        return ['']
    if s[0] is not '?':
        return [s[0]+suf for suf in enum(s[1:])]
    else:
        en=enum(s[1:])
        return [c+suf for suf in en for c in '1234567890']

for tsdgdgsdf in range(t):
    s1,s2=input().split()
    n=len(s1)
    diff=0
    L1=list(map(int,enum(s1)))
    L2=list(map(int,enum(s2)))
    L1.sort(reverse=True)
    L2.sort(reverse=True)
    ans1=0
    ans2=0
    bdiff=100000
    for a in L1:
        for b in L2:
            diff = abs(a-b)
            if bdiff>=diff:
                bdiff=diff
                ans1=a
                ans2=b
    print("Case #{}: {}{} {}{}".format(tsdgdgsdf+1,'0'*(n-len(str(ans1))), ans1,'0'*(n-len(str(ans2))), ans2))
