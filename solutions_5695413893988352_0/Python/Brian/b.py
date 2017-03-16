def try_all(C, J):
    best = None
    for i in xrange(len(C)):
        if C[i] == '?':
            for j in xrange(10):
                C[i] = chr(ord('0') + j)
                curr = try_all(C, J)
                if (best is None or
                    curr[0] < best[0] or
                    (curr[0] == best[0] and curr[1] < best[1]) or
                    (curr[0] == best[0] and curr[1] == best[1] and curr[2] < best[2])):
                    best = curr
            C[i] = '?'
            return best
    for i in xrange(len(J)):
        if J[i] == '?':
            for j in xrange(10):
                J[i] = chr(ord('0') + j)
                curr = try_all(C, J)
                if (best is None or
                    curr[0] < best[0] or
                    (curr[0] == best[0] and curr[1] < best[1]) or
                    (curr[0] == best[0] and curr[1] == best[1] and curr[2] < best[2])):
                    best = curr
            J[i] = '?'
            return best
    C = "".join(C)
    J = "".join(J)
    res = abs(int(C)-int(J))
    return (res, C, J)

with open("b.in") as f:
    t = int(next(f))
    for case in xrange(t):
        C, J = next(f).split(" ")
        C = list(C.strip())
        J = list(J.strip())
        res = try_all(C, J)
        print "Case #{}: {} {}".format(case+1, res[1], res[2])
