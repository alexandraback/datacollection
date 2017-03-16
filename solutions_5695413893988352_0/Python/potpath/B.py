from itertools import product

T = int(input())
sr = tuple(str(x) for x in range(10))
for t in range(1, T + 1):
    C, J = input().split()
    cs = ['']
    for c in C:
        if c == '?':
            ncs = sr
        else:
            ncs = (c,)
        cs = [''.join(x) for x in product(cs, ncs)]
    js = ['']
    for j in J:
        if j == '?':
            njs = sr
        else:
            njs = (j,)
        js = [''.join(x) for x in product(js, njs)]
    ac = aj = mindiff = 1e19
    for cc, jj in product(cs, js):
        cc = int(cc)
        jj = int(jj)
        diff = abs(int(cc) - int(jj))
        if diff < mindiff or (diff == mindiff and ((cc < ac) or (cc == ac and jj < aj))):
            mindiff = diff
            ac = cc
            aj = jj
    cpad = '0' * (len(C) - len(str(ac)))
    jpad = '0' * (len(J) - len(str(aj)))
    print('Case #%d: %s%d %s%d' % (t, cpad, ac, jpad, aj))
