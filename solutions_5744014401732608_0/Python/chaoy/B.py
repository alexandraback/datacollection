
def go(A, M, i, j):
    if i == len(A) - 1:
        w = [0] * len(A)
        w[0] = 1
        for i in range(1, len(w), 1):
            for j in range(i):
                w[i] += w[j] * A[j][i]
        # print(A, w[-1], M)
        if w[-1] == M:
            return A
        return None
    ii, jj = i, j + 1
    if jj >= len(A):
        ii += 1
        jj = ii + 1
    A[i][j] = 0
    r = go(A, M, ii, jj)
    if r is not None:
        return r
    A[i][j] = 1
    return go(A, M, ii, jj)


def run(B, M):
    A = [[0] * B for _ in range(B)]
    return go(A, M, 0, 1)


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        B, M = map(int, input().split(' '))
        r = run(B, M)
        if r:
            print('Case #{}: POSSIBLE'.format(t + 1))
            for a in r:
                print(''.join(map(str, a)))
        else:
            print('Case #{}: IMPOSSIBLE'.format(t + 1))
