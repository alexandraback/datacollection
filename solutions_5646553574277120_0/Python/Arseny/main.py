#!/usr/bin/python
from itertools import combinations


def solve(V, Ds):
    #print V, Ds
    possible = [False for k in xrange(V + 1)]
    for m in range(len(Ds) + 1):
        for dd in combinations(Ds, m):
            s = sum(dd)
            if s <= V:
                possible[s] = True

    result = 0
    while False in possible:
        new_d = possible.index(False)
        result+= 1
        update = set()
        for s, is_possible in enumerate(possible):
            if is_possible and (s + new_d <= V):
                update.add(s + new_d)
        for s in update:
            possible[s] = True
        #print "add ", new_d, update
    return result


if __name__ == '__main__':
    T = int(raw_input())
    for t in range(T):
        c, d, v = map(int, raw_input().split())
        Ds = set(map(int, raw_input().split()))
        answer = solve(v, Ds)
        print "Case #{0}: {1}".format(t + 1, answer)
