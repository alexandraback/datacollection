import math,string,itertools,fractions,heapq,collections,re,array,bisect

t = int(input())

for i in range(1,t+1):
    j,p,s,k = list(map(int, input().split()))
    sa = []

    jp = []
    for ji in range(j):
        jp.append([0]*p)
    js = []
    for ji in range(j):
        js.append([0]*s)
    ps = []
    for pi in range(p):
        ps.append([0]*s)

    for ji in range(j):
        for pi in range(p):
            pi = (pi+ji) % p
            for si in range(s):
                si = (si+pi+ji) % s
                if jp[ji][pi] >= k:
                    continue
                if js[ji][si] >= k or ps[pi][si] >= k:
                    continue
                sa.append(" ".join(map(str, [ji+1,pi+1,si+1])))
                jp[ji][pi] += 1
                js[ji][si] += 1
                ps[pi][si] += 1

    print("Case #{0}: {1}".format(i, len(sa)))
    print("\n".join(sa))
