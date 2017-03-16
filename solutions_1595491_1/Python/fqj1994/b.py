#!/usr/bin/env python
def build_list(i, S, L):
    if i < S:
        LL = [lambda x: (x/3-1,x/3,x/3+1), \
                lambda x: (x/3-1,x/3+1,x/3+1), \
                lambda x: (x/3,x/3,x/3+2) \
        ][L[i] % 3](L[i])
        if min(LL) < 0 or max(LL) > 10:
            return build_list(i, -1, L)
        else:
            return LL
    else:
        return [lambda x: (x/3,x/3,x/3), \
                lambda x: (x/3,x/3,x/3+1), \
                lambda x: (x/3,x/3+1,x/3+1), \
        ][L[i] % 3](L[i])

def _cmp(p):
    def __cmp(a, b):
        la = max(build_list(0, -1, [a]))
        lb = max(build_list(0, -1, [b]))
        la2 = max(build_list(0,1, [a]))
        la3 = min(build_list(0, 1, [a]))
        lb2 = max(build_list(0, 1, [b]))
        lb3 = min(build_list(0, 1, [b]))
        if 10 >= la2 >= p and la < p and la3 >= 0:
            return -1
        if 10 >= lb2 >= p and lb < p and lb3 >= 0:
            return 1
        if (la3 < 0 or la > 10) and 10 >= lb3 >= 0:
            return 1
        if (lb3 < 0 or lb > 10) and 10 >= la3 >= 0:
            return -1
        return 0
    return __cmp

T = input()
for K in range(T):
    L = map(int, raw_input().split(' '))
    N, S, p = [L.pop(0) for i in range(3)]
    L.sort(cmp = _cmp(p))
    NewL = [build_list(i, S, L) for i in range(N)]
    R = sum([max(i) >= p and 1 or 0 for i in NewL])
    print "Case #%d: %d" % (K + 1, R)
