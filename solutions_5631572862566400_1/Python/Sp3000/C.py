from collections import defaultdict, deque

def solve(N, F):
    reverse_graph = defaultdict(set)

    for i, k in enumerate(F, start=1):
        reverse_graph[k].add(i)

    # Find the cycles naively
    # Solution either max cycle length or sum of max paths from 2 cycle
    m = 0
    for n in range(1, N+1):
        seen = set()
        to_see = deque()
        to_see.append((n, 0))

        while to_see:
            x, k = to_see.pop()

            if x in seen:
                if x == n:
                    m = max(m, k)
                continue

            seen.add(x)

            for child in reverse_graph[x]:
                to_see.append((child, k+1))

    two_cycles = []
    two_cycle_nodes = []
    for a in range(1, N+1):
        for b in range(a+1, N+1):
            if a in reverse_graph[b] and b in reverse_graph[a]:
                two_cycles.append((a, b))
                two_cycle_nodes.extend([a, b])

    g = 0
    for a, b in two_cycles:
        def f(x, t):
            if set(reverse_graph[x]) - {t}:
                return max(f(c,t)+1 for c in set(reverse_graph[x]) - {t})
            return 0

        g += f(a,b)+f(b,a)+2

    return max(m, g)

def solve2(N, F):
    import itertools

    for c in range(N, 0, -1):
        for x in itertools.permutations(list(range(1, N+1)), c):
            valid = True

            for i in range(len(x)):
                if F[x[i]-1] in {x[(i-1)%len(x)], x[(i+1)%len(x)]}:
                    continue
                valid = False

            if valid:
                return c
    
# 2 1 2 2 4 3

##while True:
##    import random
##    x = list(range(1, 9))
##    random.shuffle(x)
##
##    a = solve(len(x), x)
##    b = solve2(len(x), x)
##
##    if a != b:
##        print(a, b, x)

with open("C-large.in") as infile:
    with open("C.out", "w") as outfile:
        T = int(next(infile))

        for case in range(1, T+1):
            N = int(next(infile))
            F = list(map(int, next(infile).split()))

            m = solve(N, F)

            print("Case #{}: {}".format(case, m), file=outfile)
