T = int(raw_input())

def gcm(a, b):
    if b==0: return a
    return gcm(b, a % b)

for t in range(T):
    P, Q = [int(x) for x in raw_input().split("/")]
    g = gcm(P, Q)
    P /= g
    Q /= g
    ans = 0
    while Q % 2 == 0:
        if P < Q: ans += 1
        Q /= 2
    if Q == 1:
        print "Case #{0}: {1}".format(t + 1, ans)
    else:
        print "Case #{0}: impossible".format(t + 1)
