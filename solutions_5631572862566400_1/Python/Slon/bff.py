import sys

T=int(sys.stdin.readline().strip())

for t in range(1, T + 1):
    N=int(sys.stdin.readline().strip())
    F=list(map(lambda x: int(x) - 1, sys.stdin.readline().strip().split()))

    max_loop=0
    visited=set()
    for start in range(N):
        if start in visited:
            continue

        i=0
        loop={start: 0}
        while True:
            if F[start] in loop:
                loop_size = i - loop[F[start]] + 1
                if max_loop is None or loop_size > max_loop:
                    max_loop = loop_size
                break
            else:
                start = F[start]
                loop[start] = i + 1
                i += 1

        visited.update(set(loop.keys()))

    sustained=set()
    for start in range(N):
        a = F[F[start]]
        if a == start:
            sustained.add((min(start, F[start]), max(start, F[start])))

    R=[[] for _ in range(N)]
    for i in range(N):
        R[F[i]].append(i)

    def get_longest(x, bad):
        m = 0
        for n in R[x]:
            if n == bad:
                continue
            m = max(m, get_longest(n, bad) + 1)
        return m

    sus=0
    for a, b in sustained:
        co = 2 + get_longest(a, b) + get_longest(b, a)
        sus += co

    print("Case #%d: %d" % (t, max(sus, max_loop)))
