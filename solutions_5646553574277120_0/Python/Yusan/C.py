#!/usr/bin/python
# vi: set fileencoding=utf-8 :


def prod(subset, d):
    s = 0
    for i in range(len(subset)):
        s += subset[i] * d[i]
    return s


def possible(d, subset, rest):
    d = list(d)
    #print subset, d, rest
    if len(subset) == len(d):
        x = prod(d, subset)
        if x in rest:
            rest.remove(x)
        return rest
    else:
        subset2 = subset[:]
        subset2.append(0)
        rest = possible(d, subset2, rest)
        subset3 = subset[:]
        subset3.append(1)
        rest = possible(d, subset3, rest)
        return rest


def enum_denom(d, subset, V):
    if len(subset) == V:
        denom = []
        for i in range(V):
            if subset[i] == 1:
                denom.append(i + 1)
        rest0 = possible(denom, [0], range(1, V + 1))
        rest1 = possible(denom, [1], range(1, V + 1))
        r = V
        if len(rest) == 0:
            r = min(r, len(set(denom) - set(d)))
        if len(rest1) == 0:
            r = min(r, len(set(denom) - set(d)))
        return r
    else:
        subset2 = subset[:]
        subset2.append(0)
        r0 = enum_denom(d, subset2, V)
        subset3 = subset[:]
        subset3.append(1)
        r1 = enum_denom(d, subset3, V)
        return min(V, r0, r1)

def minimum_denomination(C, D, V, d):
    #r0 = enum_denom(d, [0], V)
    #r1 = enum_denom(d, [1], V)
    rest = range(1, V + 1)
    denom = [1, 2, 4, 8, 16]
    m = V
    for i in range(len(denom)):
        if denom[i] >= V:
            break
        rest0 = possible(set(d) | set(denom[:i + 1]), [0], rest)
        if len(rest0) == 0:
            m = min(m, len(set(denom[:i + 1]) - set(d)))
        rest1 = possible(set(d) | set(denom[:i + 1]), [1], rest)
        if len(rest1) == 0:
            m = min(m, len(set(denom[:i+1]) - set(d)))
    return m


T = int(raw_input())
for case_number in range(1, T + 1):
    C, D, V = map(int, raw_input().split())
    d = map(int, raw_input().split())
    print 'Case #%d: %d' % (case_number, minimum_denomination(C, D, V, d))
