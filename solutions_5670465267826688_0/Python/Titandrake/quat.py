# represent by 8 x 8 table
# 0,1,2,3,4,5,6,7 = 1,i,j,k,-1,-i,-j,-k
# a * b == table[a][b]
mult = [
    [0,1,2,3,4,5,6,7],
    [1,4,3,6,5,0,7,2],
    [2,7,4,1,6,3,0,5],
    [3,2,5,4,7,6,1,0],
    [4,5,6,7,0,1,2,3],
    [5,0,7,2,1,4,3,6],
    [6,3,0,5,2,7,4,1],
    [7,6,1,0,3,2,5,4],
]

def convert(s):
    m = {'i': 1, 'j': 2, 'k': 3}
    return [m[c] for c in s]

def product(cs):
    # return product of all prefixes
    prods = [0]
    for c in cs:
        prods.append(mult[prods[-1]][c])
    return prods

def suff(cs):
    prods = [0]
    for c in cs[::-1]:
        prods.append(mult[c][prods[-1]])
    return prods

def orbit(v):
    vals = [0]
    while mult[vals[-1]][v] != 0:
        vals.append(mult[vals[-1]][v])
    return vals


def solve(s, x):
    s = convert(s)
    prods = product(s)
    suffs = suff(s)
    o = orbit(prods[-1])
    # ijk = kk = -1
    # check entire product
    if o[x % len(o)] != 4:
        return False
    # find A copies + prefix that equals i,
    # bias A as small as possible, then
    # bias prefix small
    A = 0
    pre = 0
    found_i = False
    while A < len(o) and not found_i:
        for i, c in enumerate(prods):
            if mult[o[A]][c] == 1:
                pre = i
                found_i = True
                A -= 1
                break
        A += 1
    if not found_i:
        return False
    B = 0
    suf = 0
    found_k = False
    while B < len(o) and not found_k:
        for i, c in enumerate(suffs):
            if mult[c][o[B]] == 3:
                suf = i
                found_k = True
                B -= 1
                break
        B += 1
    if not found_k:
        return False
    # verify this is doable
    # pre = number chars and suff = # of chars
    need_more = 2 if (pre + suf > len(s)) else 1
    return (A + need_more + B) <= x

t= input()
for case in xrange(1, t+1):
    l, x= map(int, raw_input().split())
    s = raw_input()
    if solve(s, x):
        print 'Case #%d: YES' % case
    else:
        print 'Case #%d: NO' % case

