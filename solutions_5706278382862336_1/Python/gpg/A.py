

po = [2**x for x in range(44)]
pp = [2**x for x in range(40)]
pp.reverse()
def find(j):
    r = 0
    for p in po[1:]:
        if j%p != 0:
            return r
        r+=1
    return None 

def do():
    P, Q = [int(x) for x in raw_input().split('/')]
    q2 = find(Q)
    qother = Q/(2**q2)
    if P%qother != 0:
        return "impossible"
    Q /= qother
    P /= qother 
    for i, m in enumerate(po):
        if P < m:
            return str(q2 - i + 1)

N = int(raw_input())
for n in range(1, N+1):
    print("Case #%d: %s" % (n, do()))
