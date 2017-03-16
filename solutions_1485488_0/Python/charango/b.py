
def move(H, T, c1, f1, c2, f2):
    if c2 - f1 < 50 or c1 - f2 < 50:
        return None
    level = max(H - T * 10, 0)
    level_ok = c2 - 50
    if not T and level <= level_ok:
        return T

    res = T
    if level > level_ok:
        res += (level - level_ok) / 10.0
        level = level_ok
    if level - f1 >= 20:
        res += 1.0
    else:
        res += 10.0
    return res


def solve(H, N, M, C, F):
    A = []
    for i in xrange(N):
        A.append([None] * M)

    A[0][0] = 0
    unreachable = 'X'
    for i in xrange(N):
        for j in xrange(M):
            if C[i][j] - F[i][j] < 50:
                A[i][j] = unreachable

    upd = True
    while upd:
        upd = 0
        for i in xrange(N):
            for j in xrange(M):
                if A[i][j] is unreachable:
                    continue
                best = A[i][j]
                for dx, dy in ((-1,0), (1,0), (0,-1), (0,1)):
                    x, y = j + dx, i + dy
                    if x < 0 or x >= M or y < 0 or y >= N:
                        continue
                    if A[y][x] is None or A[y][x] is unreachable:
                        continue
                    time = move(H, A[y][x], C[y][x], F[y][x], C[i][j], F[i][j])
                    if time is not None and (best is None or time < best):
                        best = time
                if best != A[i][j]:
                    A[i][j] = best
                    upd += 1
    return A[N - 1][M - 1]

def main(f):
    T = int(f.readline())
    for i in xrange(T):
        H, N, M = map(int, f.readline().split(' '))
        C, F = [], []
        for j in xrange(N):
            C.append(map(int, f.readline().split(' ')))
        for j in xrange(N):
            F.append(map(int, f.readline().split(' ')))
        res = solve(H, N, M, C, F)
        print 'Case #%d: %s' % (i + 1, res)

if __name__ == '__main__':
    import sys
    main(sys.stdin)
