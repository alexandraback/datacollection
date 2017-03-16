import sys

def visit(l, G, visited):
    if l in visited:
        return True
    visited.add(l)
    for c in G[l]:
        if visit(c, G, visited):
            return True
    return False

C = int(sys.stdin.readline())
for c in range(C):
    N = int(sys.stdin.readline())
    G = []
    leaves = set(range(N))
    for n in range(N):
        parents = map(lambda p: int(p) - 1, sys.stdin.readline().split()[1:])
        G.append(parents)
        for p in parents:
            if p in leaves:
                leaves.remove(p)
    diamond_found = False
    for l in leaves:
        visited = set()
        if visit(l, G, visited):
            diamond_found = True
            break
    print "Case #%d: %s" % (c + 1, "Yes" if diamond_found else "No")