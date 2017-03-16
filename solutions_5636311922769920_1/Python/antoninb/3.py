with open("in") as f:
    T = int(f.readline())
    for t in xrange(T):
        K, C, S = f.readline().split()
        K = int(K)
        C = int(C)
        S = int(S)
        positions = []
        depth = 1
        max_depth = C
        max_width = K**(max_depth - 1)
        curr_width = max_width
        acc = 1
        for k in xrange(1, K + 1):
            done = False
            # print "Adding", (k - 1) * curr_width, "to", acc
            acc += (k - 1) * curr_width
            if depth == C:
                done = True
                positions.append(acc)
                depth = 1
                curr_width = max_width
                acc = 1
                continue
            curr_width /= K
            depth += 1
            # print k, acc, curr_width, depth
        if not done:
            positions.append(acc)
        required = len(positions)
        if (required > S):
            r = "IMPOSSIBLE"
        else:
            r = " ".join([str(p) for p in positions])
        print "Case #{}: {}".format(t + 1, r)
