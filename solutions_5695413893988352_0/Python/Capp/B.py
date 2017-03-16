#!/usr/bin/env python

from sys import stdin, stderr

def eval_str(s, val):
    val = int(val)
    qn = s.count('?')
    if val >= 10 ** qn: return None
    vs = []
    for n in range(qn):
        vs.append(str(val % 10))
        val /= 10
        pass
    vs.reverse()
    wds = s.split('?')
    res = ''
    for i in range(len(vs)): res += wds[i] + vs[i]
    res += wds[-1]
    return res

def eval(s, val): return int(eval_str(s, val))


def Solve(A, B):
    qa = A.count('?')
    qb = B.count('?')
    va = 0
    vb = 0
    min_val = abs(eval(A, 0) - eval(B, 0))
    min_a = 0
    min_b = 0
    while va < 10 ** qa and vb < 10 ** qb:
        d = abs(eval(A, va) - eval(B, vb))
        if min_val > d:
            min_val = d
            min_a = va
            min_b = vb
            pass
        if eval(A, va) < eval(B, vb):
            va += 1
        else:
            vb += 1
            pass
        pass

    return eval_str(A, min_a) + ' ' + eval_str(B, min_b)


for T in range(int(stdin.readline())):
    A, B = stdin.readline().split()

    print 'Case #%d:' % (T+1),
    print Solve(A, B)
