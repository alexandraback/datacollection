import sys
import math

import heapq

T = int(sys.stdin.readline())

for case in range(1, T + 1) :
    output = "Case #" + str(case) + ": "
    line = sys.stdin.readline().strip().split(" ")
    H = int(line[0])
    N = int(line[1])
    M = int(line[2])

    C = []
    F = []
    for _ in range(N):
        line = sys.stdin.readline().strip().split(" ")
        c = [int(e) for e in line]
        C.append(c)
    for _ in range(N):
        line = sys.stdin.readline().strip().split(" ")
        f = [int(e) for e in line]
        F.append(f)

    map = []
    for _ in range(N):
        map.append([None] * M)

    queue = []
    heapq.heappush(queue, [0, (0, 0)])

    def timeWait (_from, _to, timePassed):
        level = H - timePassed * 10
        if (F[_to[0]][_to[1]] + 50     > C[_to[0]][_to[1]] or \
            F[_from[0]][_from[1]] + 50 > C[_to[0]][_to[1]] or \
            F[_to[0]][_to[1]] + 50 > C[_from[0]][_from[1]]):
            return None
        if (level + 50 <= C[_to[0]][_to[1]]):
            return 0
        else:
            return (level + 50 - C[_to[0]][_to[1]]) / 10.0

    while True:
        ele = heapq.heappop(queue)
        if (map[ele[1][0]][ele[1][1]] is not None):
            continue
        map[ele[1][0]][ele[1][1]] = ele [0]
        if(ele[1][0] == N - 1 and ele[1][1] == M - 1):
            break
        for direction in ((0, 1), (0, -1), (1, 0), (-1, 0)):
            nextLoc = (ele[1][0] + direction[0], ele[1][1] + direction[1])
            if N > nextLoc[0] >= 0 and M > nextLoc[1] >= 0:
                wait = timeWait(ele[1], nextLoc, ele[0])
                if wait is not None:
                    if ele[0] == 0 and wait == 0:
                        wait = 0
                    else:
                        wait += ele[0]
                        if H - wait * 10 - 20 >= F[ele[1][0]][ele[1][1]]:
                            wait += 1
                        else:
                            wait += 10
                    heapq.heappush(queue, [wait, nextLoc])


    print output + str(map[N -1][M - 1])
