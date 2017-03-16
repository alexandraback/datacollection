import sys

n = [] 
n.append([])
n.append([[(0, 0)]])
n.append([[(0, 0), (0, 1)]])
n.append([[(0, 0), (0, 1), (0, 2)], [(0, 0), (0, 1), (1, 0)]])
n.append([[(0, 0), (0, 1), (1, 0), (1, 1)], [(0, 0), (0, 1), (1, 0), (2, 0)],
    [(0, 0), (1, 0), (1, 1), (2, 0)], [(0, 0), (1, 0), (1, 1), (2, 1)],
    [(0, 0), (1, 0), (2, 0), (3, 0)]])

def solvee(l, X, R, C):
    for piece in l:
        M = []
        for r in range(R):
            M.append([0 for i in range(C)])

        for p in piece:
            if p[0] >= R or p[1] >= C:
                return 'RICHARD'

            M[p[0]][p[1]] = 1

        count = 0
        for i in range(R):
            for j in range(C):
                if M[i][j] == 0:
                    count += 1

        if count % X != 0:
            return 'RICHARD'

    return 'GABRIEL'

def solve(instance):
    X, R, C = instance
    if X > max(R, C):
        print('RICHARD')
        return

    l = n[X]

    t1 = solvee(l, X, R, C)
    if t1 == 'GABRIEL':
        print('GABRIEL')
    else:
        t2 = solvee(l, X, C, R)
        print(t2)

if __name__ == '__main__':
    T = int(sys.stdin.readline().strip())
    IL = []
    for i in range(T):
        line = sys.stdin.readline().strip().split()
        line = [int(i) for i in line]
        IL.append(line)

    for i in range(T):
        print('Case #'+str(i+1)+': ', end='')
        solve(IL[i])

