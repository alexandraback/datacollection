


T = raw_input()
T = int(T)

for i in range(T):
    line = raw_input()
    K, C, S = line.split()
    K = int(K)
    C = int(C)
    S = int(S)

    min_S = K / C
    if K % C != 0: min_S += 1
    if S < min_S:
        print("Case #%d: IMPOSSIBLE" % (i + 1))
        continue

    pos = []

    for j in range(0, K, C):
        p = 0
        for k in range(C):
            if j + k >= K: break
            p = p * K + (j + k)
        pos.append(p + 1)

    print("Case #%d: %s" % (i + 1, ' '.join([str(p) for p in pos])))



