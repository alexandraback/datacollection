import collections

def readints():
    return [int(X) for X in input().split(' ')]

for C in range(int(input())):
    N = readints()[0]
    F = [0]+readints()
    nodes = set(range(1,1+N))
    chained = []
    pairs = []
    best = 0
    for I in range(1, 1+N):
        if F[F[I]] == I:
            pairs.append(I)
            nodes.remove(I)
    while len(nodes):
        last = nodes.pop()
        cycle = []
        while last not in cycle:
            cycle.append(last)
            if last in nodes: nodes.remove(last)
            last = F[last]
        start = cycle.index(last)
        this = len(cycle) - start
        chained.extend(cycle[:start])
        if this > best: best = this
    chains = collections.defaultdict(int)
    for I in chained:
        chains[F[I]] = max(1 + chains[I], chains[F[I]])
    pc = len(pairs) + sum(chains[I] for I in pairs)
    print("Case #{}: {}".format(1+C, max(best, pc)))
