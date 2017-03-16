from sys import setrecursionlimit
from collections import deque
setrecursionlimit(10**8)

def solve():
    global Q

    while Q:
        x, dist = Q[0]
        Q.popleft()

        solved[x] = True

        if x == n:
            return dist

        for y in [x+1, int(str(x)[::-1])]:
            if y >= 10*n: continue
            if not solved[y]:
                solved[y] = True
                Q.append((y, dist+1))


for _ in range(0, input()):
    n = input()
    Q = deque([(1, 1)])
    solved = [False for i in range(0, 10*n)]

    print "Case #%i: %i" % (_+1, solve())
