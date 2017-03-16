import sys

def readLine():
    return [int(_) for _ in sys.stdin.readline().strip().split()]

def solve(test):
    N, M = [int(_) for _ in sys.stdin.readline().strip().split()]
    A = [readLine() for _ in range(N)]
    maxRows = [max(row) for row in A]
    maxCols = [0 for col in range(M)]

    for i in range(N):
        for j in range(M):
            if A[i][j] > maxCols[j]:
                maxCols[j] = A[i][j]

    for i in range(N):
        for j in range(M):
            if  A[i][j] < maxRows[i] and A[i][j] < maxCols[j]:
                return False

    return True

if __name__ == '__main__':
    nTests = int(sys.stdin.readline().strip())
    for test in range(1, nTests + 1):
        res = solve(test)
        ret = 'YES'
        if not res:
            ret = 'NO'
        print 'Case #{0}: {1}'.format(test, ret)
