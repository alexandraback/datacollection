import sys
from itertools import combinations
rl = lambda: sys.stdin.readline().strip()

N, M, K = 0, 0, 0
dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]


def can_go(board, i, j, used):
    if board[i][j] != 1 and i == 0 or i == N - 1 or j == 0 or j == M - 1:
        #print i, j
        return True

    used.add((i, j))
    for d in dirs:
        ii = i + d[0]
        jj = j + d[1]
        if ii < 0 or ii >= N or jj < 0 or jj >= M:
            continue
        if board[ii][jj] == 1:
            continue
        if (ii, jj) in used:
            continue
        if can_go(board, ii, jj, used):
            return True
    return False


def is_valid(board):
    k = 0
    for i in range(N):
        for j in range(M):
            if board[i][j] == 1:
                k += 1
                continue

            if not can_go(board, i, j, set()):
                #print i, j, 'NO'
                k += 1
            #else:
                #print i, j, 'YES'

    #print k
    if k == K:
        return True
    return False


#N, M, K = 4, 5, 8
#print is_valid([[0, 1, 1, 0, 0], [1, 0, 0, 1, 0], [0, 1, 1, 0, 0], [0, 0, 0, 0, 0]])


T = int(rl())
for tcase in range(T):
    print >> sys.stderr, (tcase + 1)
    N, M, K = map(int, rl().split())
    board = [[0 for i in range(M)] for j in range(N)]
    all_coord = []
    for i in range(N):
        for j in range(M):
            all_coord.append((i, j))

    ans = 987654321
    for k in range(N * M + 1):
        for xs in combinations(all_coord, k):
            for x in xs:
                board[x[0]][x[1]] = 1

            if is_valid(board):
                ans = k
                break

            for x in xs:
                board[x[0]][x[1]] = 0

        if ans != 987654321:
            break

    print 'Case #%d: %d' % (tcase + 1, ans)
