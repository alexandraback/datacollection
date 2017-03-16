# usage:  (py3 a.py < a.in) > a.out

import time, sys, inspect, math

lineno = lambda: inspect.currentframe().f_back.f_back.f_lineno
print = lambda *a, **k: __builtins__.print(str(lineno())+":", *a, file=sys.stderr, **k)
map = lambda *a: list(__builtins__.map(*a))

#---------------------------------------------

"""
is it enough to compare only sequences with one G to the all-L's one?
    so only look at GLLL, LGLL, LLGL, LLLG
        omg a lattice!!  they only become 'more golden'
    we must then 'cover' (as in the set cover problem) these sequences
    such that in at least one of the indices we have G

we definitely can't construct K^C
    small dataset is  S = K ... how does that simplify things?
    maybe all are possible? but what if C > K ?

looks very 'tree-like'
    eg GLL: we find G by branching right (L), right (L), left (G)
        or right, middle, left  or left, *, *
    one could iterate over all indices and decide whether they are in
        the GLLL, LGLL, LLGL, LLLG
        but we would have 100^100 indices

----

hmmm, having drawn sketches for n = 4 i see more clearly
    especially a simple solution for the small (S=K) case: 1..K :D
    (or any K ascending indeces.
    reason: length of original sequence, which gets copied or golded)

equivalent problem:
    we have all C-digit numbers in base K  (including those with zeros)
    can you pick S of those such that all numbers are represented?

eg for K=4 and C=2 and S=2 we can choose {01,32} which contains all numbers 0..3
    and our solution indeces are their base-10 equivalents:
        01_4 = 1, 32_4 = 14
    geez google is into converting between bases today :^)

this leads us to the following ideal choice of indeces:
    demonstrated on K=16 and C=4
        0123, 4567, 89AB, CDEF
    you get the idea

feasibility:
    input is feasible iff  S >= K / C
    follows directly from the ideal choice above

"""

def run(data):
    K, C, S = data

    if S < K / C:
        return "IMPOSSIBLE"

    ret = []
    for i in range(math.ceil(K/C)):
        # this actually goes 3210 7654...  and fills up with (K-1)'s if digits are left
        ret.append(1 + sum(min(i*C+j, K-1) * K**j for j in range(C)))

    return ' '.join([str(x) for x in ret])

#---------------------------------------------

def read_case():
    return [int(n) for n in input().split()]

for i in range(int(input())):
    outstr = "Case #"+str(i+1)+": "+str(run(read_case()))
    print(outstr, " @ t =", time.clock())
    __builtins__.print(outstr)



