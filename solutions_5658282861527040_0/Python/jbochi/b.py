import sys

lines = [map(int, line.strip().split(' ')) for line in sys.stdin.readlines()]
T = lines[0][0]

for t in range(T):
    A, B, K = lines[t + 1]
    count = 0
    for i in range(A):
        for j in range(B):
            if i & j < K:
                count += 1
    solution = count
    print "Case #%d: %s" % (t + 1, solution)
