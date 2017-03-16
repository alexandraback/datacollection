import sys

inp=sys.argv[1]
outp="%s.out" % inp.split(".")[0]

cache = {}

def reverse(n):
    return int("".join(reversed("%s" % n)))

def neighs(n):
    return set([n+1, reverse(n)])

def solve(N):
    if N in cache: return cache[N]
    visited = set()
    to_visit = [(1, 1)]
    tv = set([1])
    while True:
        todo, says = to_visit.pop(0)
        if todo == N:
            cache[N] = says
            return says
        visited.add(todo)
        for n in neighs(todo):
            if n not in visited and n not in tv:
                to_visit.append((n, says+1))
                tv.add(n)

with open(inp, 'r') as f, open(outp, 'w') as out:
    cases = int(f.readline())
    for c in range(cases):
        n = int(f.readline()[:-1])
        out.write("Case #%s: %s\n" % (c+1,solve(n)))

