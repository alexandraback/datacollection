#!/usr/bin/python

#
# O(n^2) for small case (should finish!?)
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

# fill inverse table
invtable = dict()
for sa, a in product([-1, 1], range(4)):
    for sb, b in product([-1, 1], range(4)):
        sc, c = quatmul((sa, a), (sb, b))
        key = ((sc, c), (sa, a))
        if invtable.has_key(key):
            raise Error()
        else:
            invtable[key] = (sb, b)

def inverse(a, c):
    """
    Return b such that a * b == c
    """
    if invtable.has_key((c, a)):
        return invtable[(c, a)]
    raise Error()

def printList(p):
    def v((s, v)):
        return ("-" if s == -1 else "") + "1ijk"[v]
    return "".join(map(v, p))

T = N()[0]
for t in range(1, T + 1):
    L, X = N()
    L = raw_input()
    S = L * X
    #print "S", S

    psum = (1, Q(S[0]))
    iprefix = []
    prefixsum = [psum]
    ipos = 0
    for s in S[1:]:
        if psum == (1, Q("i")):
            iprefix.append(ipos)
        ipos += 1
        psum = quatmul(psum, (1, Q(s)))
        prefixsum.append(psum)
    
    #print "iprefix", iprefix
    #print "prefixsum", printList(prefixsum)

    psum = (1, Q(S[-1]))
    kpos = len(S) - 1
    kprefix = []
    while kpos > 1:
        if psum == (1, Q("k")):
            kprefix.append(kpos)
        kpos -= 1
        psum = quatmul((1, Q(S[kpos])), psum)

    if len(kprefix) > 0:
        assert kprefix[0] >= kprefix[-1]
    if len(iprefix) > 0:
        assert iprefix[0] <= iprefix[-1]

    canSplit = False
    for ipos in iprefix:
        for kpos in kprefix:
            if ipos + 1 >= kpos:
                break
            gapprod = inverse(prefixsum[ipos], prefixsum[kpos-1])
            assert ipos + 2 <= kpos
            if gapprod == (1, Q("j")):
                canSplit = True
                break

        if canSplit:
            break

    if canSplit:
        s = (1, Q(S[0]))
        for i in range(1, ipos+1):
            s = quatmul(s, (1, Q(S[i])))
        assert s == (1, Q("i"))
        i = ipos + 1
        s = (1, Q(S[i]))
        while i < kpos - 1:
            i += 1
            s = quatmul(s, (1, Q(S[i])))

        i += 1
        assert s == (1, Q("j"))
        s = (1, Q(S[i]))
        while i < len(S) - 1:
            i += 1
            s = quatmul(s, (1, Q(S[i])))

        assert s == (1, Q("k"))

    print "Case #%d: %s" % (t, "YES" if canSplit else "NO")

