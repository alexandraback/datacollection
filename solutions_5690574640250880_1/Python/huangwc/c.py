import sys

sys.stdin = open('C-large.in', 'r')
sys.stdout = open('c-large.out', 'w')


def solve(R, C, M):
    G = [['*'] * C for r in range(R)]
    if min(R, C) == 1 or R*C-M == 1:
        for m in range(R*C-M):
            G[m % R][m // R] = '.'
        G[0][0] = 'c'
        return G
    else:
        if R*C-M in {2, 3, 5, 7}:
            return None
        (rr, cc) = (0, 0)
        for r in range(2, R+1):
            for c in range(2, C+1):
                if r+r+c+c-4 <= R*C-M <= r*c:
                    (rr, cc) = (r, c)
                    break
            if rr:
                break
        if rr or cc:
            for r in range(rr):
                G[r][0] = G[r][1] = '.'
            for c in range(2, cc):
                G[0][c] = G[1][c] = '.'
            rem = R*C-M-rr-rr-cc-cc+4
            for r in range(2, rr):
                for c in range(2, cc):
                    if rem > 0:
                        G[r][c] = '.'
                    rem -= 1
            G[0][0] = 'c'
            return G
    return None

for t in range(int(input())):

    result = solve(*map(int, input().split()))

    print('Case #%d:' % (t+1))
    if result:
        for line in result:
            print(''.join(line))
    else:
        print('Impossible')

sys.stdin.close()
sys.stdout.close()