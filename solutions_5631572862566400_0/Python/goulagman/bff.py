import numpy as np


def read_n_int(n):
    ints = [int(s) for s in input().split(" ")]
    if len(ints) != n:
        raise ValueError('Expected %i ints, got %i' % (n, len(ints)))
    if n == 1:
        return ints[0]
    return ints


t = read_n_int(1)
for i in range(1, t + 1):
    n = read_n_int(1)
    graph = read_n_int(n)
    # Zero index
    graph = np.asarray([j - 1 for j in graph])
    # Invert the graph
    inv = dict()
    for j in np.arange(n):
        inv[j] = np.where(graph == j)[0]
    longest = None

    # Strategy 1: one big cycle
    for j in np.unique(graph):
        if longest is not None and longest[1][j]:
            # Already explored this cycle
            continue
        cycle = np.zeros(n)
        it = j
        l = 0
        while cycle[it] == 0:
            l += 1
            cycle[it] = l
            it = graph[it]
        if longest is None or l > longest[0]:
            longest = (l - cycle[it] + 1, cycle >= cycle[it])

    if longest is not None:
        longest = longest[0]

    # Strategy 2: find 2 children cycle as roots
    roots = []
    for j in np.arange(n):
        k = graph[j]
        if graph[k] == j and k > j:
            roots.append((j, k))

    def get_longest_arm(node, exc):
        sons = inv[node].tolist()
        sons.remove(exc)
        l = 0
        while len(sons) != 0:
            l += 1
            sons_ = []
            for s in sons:
                sons_.extend(inv[s].tolist())
            sons = sons_
        return l

    # Now, for each node, we find the longest "arm"
    longs = []
    for (a, b) in roots:
        la = get_longest_arm(a, b)
        lb = get_longest_arm(b, a)
        longs.append(la + lb + 2)
    if len(longs) > 0:
        if longest is None:
            longest = np.sum(longs)
        else:
            longest = max(longest, np.sum(longs))

    print("Case #%i: %i" % (i, longest))
