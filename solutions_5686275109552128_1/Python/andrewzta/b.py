import sys

sys.stdin = open("B-large.in", "r")
sys.stdout = open("B-large.out", "w")

tn = int(input())
for test in range(tn):
    n = int(input())
    a = list(map(int, input().split()))
    L = 0
    R = max(a)
    while L < R - 1:
        M = (L + R) // 2
        can = False
        for t in range(M):
            v = M - t
            moves = 0
            for x in a:
                d = (x - 1) // v
                moves += d
            if moves <= t:
                can = True
                break
        if can:
            R = M
        else:
            L = M
    print("Case #%d: %d" % (test + 1, R))

