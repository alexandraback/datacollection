from sys import stdin, stdout
from itertools import chain
from collections import defaultdict

def solve(elements):
    counts = defaultdict(int)

    for h in elements:
        counts[h] += 1

    missing = []
    for h, cnt in counts.items():
        if cnt % 2 == 1:
            missing.append(h)

    missing.sort()

    return " ".join(map(str, missing))



T = int(stdin.readline())

for t in range(T):
    N = int(stdin.readline())

    elements = []
    for _ in range(2 * N - 1):
        elements.extend(map(int, stdin.readline().strip().split()))

    result = solve(elements)

    stdout.write("Case #%d: %s\n"%(t+1, result))