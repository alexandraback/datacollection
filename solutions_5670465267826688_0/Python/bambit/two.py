
mp = {
     '1': {'1':(1,'1'), 'i':(1,'i'), 'j':(1,'j'), 'k':(1,'k')},
     'i': {'1':(1,'i'), 'i':(-1,'1'), 'j':(1,'k'), 'k':(-1,'j')},
     'j': {'1':(1,'j'), 'i':(-1,'k'), 'j':(-1,'1'), 'k':(1,'i')},
     'k': {'1':(1,'k'), 'i':(1,'j'), 'j':(-1,'i'), 'k':(-1,'1')}
     }

def esPosibru(L, X, s):
    # Find forward product and backward product sums
    prd = [1, '1']
    fwd = {}
    for index, token in enumerate(s):
        ms, mv = mp[prd[1]][token]
        prd[0], prd[1] = prd[0]*ms, mv
        if (prd[0],prd[1]) not in fwd:
            fwd[(prd[0], prd[1])] = index

    rprd = [1, '1']
    bwd = {}
    for index, token in enumerate(reversed(s)):
        ms, mv = mp[token][rprd[1]]
        rprd[0], rprd[1] = rprd[0]*ms, mv
        if (rprd[0],rprd[1]) not in bwd:
            bwd[(rprd[0], rprd[1])] = index

    # Now both prd and rprd should be the same thing

    # Check that the grand product is ijk  = -1
    sprd = [1, '1']
    for i in range(X%4):
        ms, mv = mp[sprd[1]][prd[1]]
        sprd[0], sprd[1] = sprd[0]*prd[0]*ms, mv
    if sprd[0] != -1 or sprd[1] != '1':
        return 'NO'

    # First find the smallest i
    fi = None
    if (1,'i') in fwd:
        #Done! This is the smallest i
        fi = fwd[(1,'i')] + 1
    else:
        sprd = [1, '1']
        for i in range(4):
            ms, mv = mp[sprd[1]][prd[1]]
            sprd[0], sprd[1] = sprd[0]*prd[0]*ms, mv

            mindex = L
            for fs, fv in fwd:
                ms, mv = mp[sprd[1]][fv]
                if mv == 'i' and sprd[0]*fs*ms == 1:
                    if mindex > fwd[(fs, fv)]:
                        mindex = fwd[(fs, fv)]

            if mindex < L:
                fi = L*(i+1) + mindex + 1
                break

        if not fi:
            return 'NO'

    bi = None
    if (1,'k') in bwd:
        #Done! This is the smallest i
        bi = bwd[(1,'k')] + 1
    else:
        sprd = [1, '1']
        for i in range(4):
            ms, mv = mp[prd[1]][sprd[1]]
            sprd[0], sprd[1] = prd[0]*sprd[0]*ms, mv

            mindex = L
            for bs, bv in bwd:
                ms, mv = mp[bv][sprd[1]]
                if mv == 'k' and sprd[0]*bs*ms == 1:
                    if mindex > bwd[(bs, bv)]:
                        mindex = bwd[(bs, bv)]

            if mindex < L:
                bi = L*(i+1) + mindex + 1
                break

        if not bi:
            return 'NO'

    return 'YES' if fi + bi < L*X else 'NO'


import sys
r = open('2.test')

T = int(r.readline())
for t in range(1, T+1):
    L, X = r.readline().rstrip().split()
    s = r.readline().rstrip()
    print 'Case #%d: %s' % (t, esPosibru(int(L), int(X), s))


