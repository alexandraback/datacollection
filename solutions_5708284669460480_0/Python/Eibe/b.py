from itertools import product

def occ(pat, wd):
    cnt = 0
    i = 0
    while i < len(wd):
        j = wd.find(pat, i)
        if j == -1:
            break
        cnt += 1
        i = j+1
    return cnt

def solve(k, l, s, ks, targ):
    words = product(*([ks] * s))
    cnt = 0
    mx = 0
    ns = 0
    for wd in words:
        w = "".join(wd)
        ns += 1
        oc = occ(targ, w)
        cnt += oc
        mx = max(mx, oc)
    av = 1.0 * cnt / ns
    return mx - av
        
    
t = int(raw_input())
for case in range(1, t+1):
    k, l, s = map(int, raw_input().split())
    ks = raw_input()
    targ = raw_input()
    print "Case #%i: %.9f" %(case, solve(k, l, s, ks, targ))

