cyc = {'ij':'k', 'jk':'i', 'ki':'j'}
l = ['1', 'i', 'j', 'k']
qprod = {}
for a in l:
    for b in l:
        if a == '1': cur = b
        elif b == '1': cur = a
        elif a+b in cyc: cur = cyc[a+b]
        elif b+a in cyc: cur = '-'+cyc[b+a]
        else:
            assert a == b
            cur = '-1'
        assert (cur[0] != '-' and len(cur) == 1) or len(cur) == 2
        ncur = cur[1] if cur[0] == '-' else '-'+cur
        qprod[(a,b)] = cur
        qprod[('-'+a,b)] = ncur
        qprod[(a,'-'+b)] = ncur
        qprod[('-'+a,'-'+b)] = cur

def find(x, s):
    assert x in 'ijk'
    prod = '1'
    for i in range(len(s)):
        prod = qprod[(prod, s[i])]
        if prod == x: return i+1
    return 0

def solve():
    L, X = [int(x) for x in raw_input().split()]
    S = raw_input()
    assert len(S) == L
    assert all(c in 'ijk' for c in S)

    prod = '1'
    for c in S: prod = qprod[(prod, c)]
    if prod == '1': return False
    elif prod == '-1':
        if (X % 2) != 1: return False
    else:
        if (X % 4) != 2: return False

    ipos = find('i', S*4)
    if not ipos: return False
    jpos = find('j', (S[ipos:]+S[:ipos])*4)
    if not jpos: return False
    assert ipos + jpos != L * X
    return ipos + jpos < L * X

for i in range(int(raw_input())):
    print "Case #%d: %s"%(i+1, "YES" if solve() else "NO")
