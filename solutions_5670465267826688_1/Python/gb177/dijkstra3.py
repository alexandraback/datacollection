#!/usr/bin/python

#
# Take 2.
# Just need to find first i and last k, and check that
# ijk = -1

#
# Passes small tests
#
from itertools import product

def N(): return tuple(map(int, raw_input().split()))

def Q(v):
    return "1ijk".find(v)
#
#
multable = [
    [ Q("1"), Q("i"), Q("j"), Q("k") ],
    [ Q("i"), Q("1"), Q("k"), Q("j") ],
    [ Q("j"), Q("k"), Q("1"), Q("i") ],
    [ Q("k"), Q("j"), Q("i"), Q("1") ]
]

signtable = [
    [ 1, 1, 1, 1 ],
    [ 1,-1, 1,-1 ],
    [ 1,-1,-1, 1 ],
    [ 1, 1,-1,-1 ],
]

#
def quatmul((sign1, index1), (sign2, index2)):
    return (sign1 * sign2 * signtable[index1][index2], multable[index1][index2])

def v((s, v)):
    return ("-" if s == -1 else "") + "1ijk"[v]

def printList(p):
    return "".join(map(v, p))

def exp0((s, v), n):
    if n == 0:
        return 1, Q("1")
    r = (s, v)
    for k in range(n-1):
        r = quatmul(r, (s, v))
    return r

def exp((s, v), n):
    n = n % 4
    if n == 0:
        return 1, Q("1")

    r = (s, v)
    for _i in range(n-1):
        r = quatmul(r, (s, v))
    return r

for s in [-1, 1]:
    for c in "1ijk":
        i = s, Q(c)
        for k in range(20):
            assert exp(i, k) == exp0(i, k)

T = N()[0]
for t in range(1, T + 1):
    L, X = N()
    L = raw_input()

    total = (1, Q(L[0]))
    for s in L[1:]:
        total = quatmul(total, (1, Q(s)))

    def nextIC():
        while True:
            for i, c in enumerate(L):
                yield i, (1, Q(c))

    def prevIC():
        while True:
            i = len(L) - 1
            while i >= 0:
                yield i, (1, Q(L[i]))
                i -= 1

    total = exp(total, X)
    canSplit = False
    if total == (-1, Q("1")):
        # go multiply until you either find a i or a period
        seen = set()
        g = nextIC()
        ipos, psum = g.next()
        assert ipos == 0
        while True:
            if psum == (1, Q("i")):
                break
            i, c = g.next()
            ipos += 1
            psum = quatmul(psum, c)
            if (psum, i, c) in seen:
                break
            seen.add((psum, i, c))

        if psum == (1, Q("i")):
            rseen = set()
            rg = prevIC()
            kpos, psum = rg.next()
            kpos = X * len(L) - 1
            while True:
                if psum == (1, Q("k")):
                    #print "found kpos", kpos
                    if kpos > ipos + 1:
                        canSplit = True
                    break

                i, c = rg.next()
                kpos -= 1
                psum = quatmul(c, psum)
                if (psum, i, c) in rseen:
                    break

                rseen.add((psum, i, c))


    print "Case #%d: %s" % (t, "YES" if canSplit else "NO")

