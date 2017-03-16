T = int(raw_input())

for t in range(1,T+1):
    K, C, S = map(int, raw_input().split())
    if C*S < K:
        print "Case #%d: IMPOSSIBLE" % t
    else:
        C = min(C, K)
        poses = []
        first = 0
        done = False
        while not done:
            if first + C >= K:
                first = K - C
                done = True
            pos = 0
            for i, p in zip(range(first, first + C), range(C-1, -1, -1)):
                pos += i * (K ** p)
            poses.append(pos+1)
            first += C
        print "Case #%d: %s" % (t, " ".join(map(str, poses)))
