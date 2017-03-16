def fac(N):
    r = 1
    for i in range(2,N+1):
        r *= i
    return r

def max(N):
    ret = 1
    n = N-2
    for r in range(1,N-1):
        ret += fac(n) / fac(r) / fac(n-r)

    return ret    

def solve():
    J, P, S, K = [int(i) for i in raw_input().split()]
   
    rep = {}
    for j in range(1,J+1):
        for p in range(1,P+1):
            for s in range(1, S+1):
                rep[(-1,p,s)] = 0
                rep[(j,-1,s)] = 0
                rep[(j,p,-1)] = 0


    comb = []
    for j in range(1,J+1):
        for p in range(1,P+1):
            for s in range(1, S+1):
                if rep[(-1,p,s)] >= K:
                    continue
                if rep[(j,-1,s)] >= K:
                    continue
                if rep[(j,p,-1)] >= K:
                    continue
                comb.append((str(j),str(p),str(s)))

                rep[(-1,p,s)] += 1
                rep[(j,-1,s)] += 1
                rep[(j,p,-1)] += 1

    return str(len(comb)) + "\n" + '\n'.join([' '.join(c) for c in comb]) 

T = int(raw_input())
for t in range(1,T+1):
    print("Case #%d: %s" % (t,solve()))
