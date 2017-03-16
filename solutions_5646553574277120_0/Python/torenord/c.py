
import sys

from itertools import *
from operator import *

T = int(sys.stdin.readline())

def gensubs(Ds):
    subsets = []
    for i in range(1, len(Ds)+1):
        subsets += list(combinations(Ds, i))
    return [reduce(add, subset) for subset in subsets if reduce(add, subset) <= V]

for i in range(T):
    C, D, V = map(int, sys.stdin.readline().strip().split(" "))
    Ds = map(int, sys.stdin.readline().strip().split(" "))

    pos = gensubs(Ds)

    count = 0
    for j in range(1, V+1):
        if j not in pos:
            Ds.append(j)
            pos = gensubs(Ds)
            count += 1

    print "Case #%s: %s" % (i+1, count)
