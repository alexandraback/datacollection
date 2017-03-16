# usage:  (py3 a.py < a.in) > a.out

import time, sys, inspect

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

"""

def run(data):
    s, c, k = data
    return ' '.join([str(x) for x in range(1,k+1)])

#---------------------------------------------

def read_case():
    return [int(n) for n in input().split()]

for i in range(int(input())):
    outstr = "Case #"+str(i+1)+": "+str(run(read_case()))
    print(outstr, " @ t =", time.clock())
    __builtins__.print(outstr)



