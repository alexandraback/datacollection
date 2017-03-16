import sys
import collections


def concat(z, i):
    if i is Ellipsis:
        return Ellipsis
    return int(str(z) + str(i))


for case_no in xrange(1, input() + 1):
    print "Case #%s:" % (case_no,),
    N, M = map(int, raw_input().split())
    zips = [input() for i in xrange(N)]

    flights = collections.defaultdict(set)
    for a, b in [map(int, raw_input().split()) for _ in xrange(M)]:
        flights[a-1].add( b-1 )
        flights[b-1].add( a-1 )


    mem = collections.defaultdict(dict)
    def solve(bt, todo):
        k1 = tuple(bt)
        k2 = tuple(todo)
        if mem[k1].get(k2): return mem[k1][k2]

        if not todo:
            return ''
        vmin = Ellipsis
        for z, n in sorted((zips[n], n) for n in todo & flights[bt[-1]]):
            todo2 = todo - set((n,))
            bt = bt[:]
            bt.append( n )
            for i in range(1, len(bt)+1):
                vmin = min(vmin, concat(z, solve(bt[:i], todo2)))
            if vmin is not Ellipsis:
                return vmin
        mem[k1][k2] = vmin
        return vmin

    print min(concat(zips[i], solve([i], set(xrange(N))-set((i,)))) for i in xrange(N))
