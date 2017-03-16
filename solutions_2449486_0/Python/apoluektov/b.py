from collections import defaultdict
import sys

def solve(patterns, m, n):
    def p(i,j):
        return patterns[i][j]

    def row(i):
        return (p(i,x) for x in range(n))

    def column(j):
        return (p(x,j) for x in range(m))

    g = defaultdict(set)
    for x in range(m):
        maxx = max(row(x))
        for y in range(n):
            if p(x,y) < maxx:
                g[('r', x)].add(('c',y))

    for y in range(n):
        maxy = max(column(y))
        for x in range(m):
            if p(x,y) < maxy:
                g[('c', y)].add(('r', x))

    for n,deps in g.items():
        for n2 in deps:
            if n in g[n2]:
                return "NO"

    return "YES"


def line():
    return sys.stdin.readline().strip()

def ints(s):
    return [int(t) for t in s.split()]

def main():
    tc = int(line())
    for i in range(1, tc+1):
        m, n = ints(line())
        p = []
        for x in range(m):
            p.append(ints(line()))
        print 'Case #%s: %s' % (i, solve(p,m,n))

main()

        
