def f(n, k):
    nc = n[:]
    kc = k[:]
    nscore = 0
    while len(nc) > 0 and len(kc) > 0:
        while len(nc) > 0 and nc[-1] > kc[-1]:
            nc.pop()
            nscore += 1
        if len(nc) > 0 and len(kc) > 0:
            nc.pop()
            kc.pop()
    return nscore

for t in range(input()):
    input()
    n = sorted(map(float, raw_input().split()))
    k = sorted(map(float, raw_input().split()))

    print "Case #{}: {} {}".format(t + 1, len(n) - f(k, n), f(n, k))
