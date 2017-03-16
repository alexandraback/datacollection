import sys

T = int(sys.stdin.readline())

for n in range(1, T+1):
    parts = sys.stdin.readline().split()
    s_max = int(parts[0])
    counts = [int(d) for d in parts[1]]

    answer = 0
    total = 0
    for (i, c) in enumerate(counts):
        if total < i:
            answer += i - total
            total = i + c
        else:
            total += c

    print "Case #{}: {}".format(n, answer)

