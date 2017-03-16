from string import ascii_uppercase
from heapq import nlargest



def solve():
    b, m = map(int, raw_input().strip().split())
    if 1 << (b - 2) < m:
        print "IMPOSSIBLE"
        return
    print "POSSIBLE"
    bit = 0
    while (m - 1) >> bit > 0:
        bit += 1
    full = bit + 1
    graph = [['0' for _ in range(b)] for __ in range(b)]

    for fr in range(1, full + 1):
        for to in range(fr + 1, full + 1):
            graph[fr][to] = '1'
    for fr in range(full, b-1):
        graph[fr][fr+1] = '1'

    power = [2 ** i for i in reversed(range(bit))]
    power.append(1)
    for _i, p in enumerate(power):
        if m >= p:
            m -= p
            graph[0][_i + 1] = '1'
    for line in graph:
        print ''.join(line)


if __name__ == '__main__':
    n = int(raw_input())
    for i in range(n):
        print "Case #{}:".format(i+1),
        solve()