
def solve(N, L, S, P):
    C0 = sorted([k for k in xrange(N) if not L[k]], key=lambda k: P[k])
    C1 = sorted([k for k in xrange(N) if L[k]], key=lambda k: P[k])
    T = 0

    def collides(i, j):
        pmin = min(P[i], P[j])
        pmax = max(P[i], P[j])
        return pmin + 5 > pmax

    while True:
        # calculate distance
        minA, minB = None, None
        carA, carB = None, None
        #print T, C0, C1

        for i in xrange(N):
            ahead_0 = [k for k in C0 if P[k] > P[i]]
            ahead_1 = [k for k in C1 if P[k] > P[i]]
            if i in C0:
                ahead_same, ahead_diff = ahead_0, ahead_1
            else:
                ahead_same, ahead_diff = ahead_1, ahead_0

            if ahead_same:
                nc = ahead_same[0]
                if S[i] > S[nc]:
                    distA = float(P[nc] - P[i] - 5) / (S[i] - S[nc])
                    if minA is None or distA < minA:
                        minA, carA = distA, i

        # case 1
        if minA is not None:
            for i in xrange(N):
                P[i] += minA * S[i]
            T += minA

            cc = carA
            lane_same, lane_diff = (C0, C1) if cc in C0 else (C1, C0)
            if any(collides(cc, i) for i in lane_diff):
                return T

            L[i] = 1 - L[i]
            lane_same.remove(cc)
            ahead = [k for k in lane_diff if P[k] > P[cc]]
            if ahead:
                if P[ahead[0]] == P[carA] + 5:
                    return T
                pos = lane_diff.index(ahead[0])
                lane_diff.insert(pos, cc)
            else:
                lane_diff.append(cc)
        else:
            return None
        
def main(f):
    T = int(f.readline())
    for i in xrange(T):
        N = int(f.readline())
        L, S, P = [], [], []
        for j in xrange(N):
            x = f.readline().split(' ')
            L.append(1 if x[0] == 'L' else 0)
            S.append(int(x[1]))
            P.append(int(x[2]))
        res = solve(N, L, S, P)
        print 'Case #%d: %s' % (i + 1, res if res is not None else 'Possible')

if __name__ == '__main__':
    import sys
    main(sys.stdin)
