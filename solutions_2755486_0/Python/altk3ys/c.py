from collections import defaultdict

def tr(xs):
    xs=map(int,xs.split())
    n = xs[1]
    ds = [xs[0]+xs[5]*i for i in range(n)]
    rs = [(xs[2]+xs[6]*i,xs[3]+xs[6]*i) for i in range(n)]
    hs = [(xs[4]+xs[7]*i) for i in range(n)]
    return dict((d, (r, h)) for d,r,h in zip(ds, rs, hs))
    
def solve(trs):
    wall = defaultdict(int)
    breech = 0
    for d in sorted(k for t in trs for k in t):
        attacks = [t[d] for t in trs if d in t]
        for (l,h), s in attacks:
            if any(wall[p]<s for p in range(l,h)): breech+=1
        for (l,h), s in attacks:
            for p in range(l,h):
                wall[p]=max(wall[p],s)
    return breech

rd=raw_input
for t in range(1,1+int(rd())):
    print 'Case #%d: %d' %(t, solve(map(tr,[rd() for _ in range(int(rd()))])))
