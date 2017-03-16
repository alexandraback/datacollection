import sys, itertools
T=int(input())
for case_id in range(1,T+1):
    J,P,S,K = map(int,input().split())
    def solve():
        res = []
        jp,ps,js={},{},{}
        for j in range(J):
            for p in range(P):
                if jp.get((j,p),0)==K: continue
                for s in range(S):
                    if jp.get((j,p),0)==K: break
                    if js.get((j,s),0)==K: continue
                    if ps.get((p,s),0)==K: continue
                    res.append(' '.join(map(str,(j+1,p+1,s+1))))
                    jp[(j,p)]=jp.get((j,p),0)+1
                    js[(j,s)]=js.get((j,s),0)+1
                    ps[(p,s)]=ps.get((p,s),0)+1
        return str(len(res))+'\n'+'\n'.join(res)

    ans = solve()
    print('Case #%d: %s' % (case_id, ans))
    print('Case #%d: %s' % (case_id, ans), file=sys.stderr)
