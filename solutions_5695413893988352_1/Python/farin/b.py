#!/usr/bin/env python3

def mx(c, j):
    cr = []
    jr = []
    for i in range(len(c)):
        if c[i] == '?':
            cr.append('9')
        else:
            cr.append(c[i])
        if j[i] == '?':
            jr.append('0')
        else:
            jr.append(j[i])
    return ''.join(cr), ''.join(jr)

def up(c, j):
    c, j = c[::-1], j[::-1]
    cr = []
    jr = []
    hit = False
    wild = False
    for i in range(len(c)):
        #print(hit, c[i], j[i])
        if hit:
            if c[i] != '?':
                cr.append(c[i])
                jr.append(c[i])
            elif j[i] != '?':
                cr.append(j[i])
                jr.append(j[i])
            else:
                cr.append('0')
                jr.append('0')
        else:
            if (c[i] == '?' and j[i] == '?'):
                cr.append('?')
                jr.append('?')
                wild = True
            elif c[i] == '0' or j[i] == '9':
                if wild:
                    cr[i-1] = '1'
                    jr[i-1] = '0'
                    hit = True
                    if c[i] != '?':
                        cr.append(c[i])
                        jr.append(c[i])
                    elif j[i] != '?':
                        cr.append(j[i])
                        jr.append(j[i])
                else:
                    cr.append('0')
                    jr.append('9')
            else:
                if c[i] != '?':
                    cr.append(c[i])
                    jr.append(str(int(c[i])-1))
                elif j[i] != '?':
                    cr.append(str(int(j[i])+1))
                    jr.append(j[i])
                else:
                    cr.append('1')
                    jr.append('0')
                hit = True
    #print(hit, cr, jr)
    if hit:
        cr = ['0' if c == '?' else c for c in cr]
        jr = ['9' if c == '?' else c for c in jr]
    else:
        search = True
        for i in range(len(cr)):
            if search:
                if cr[i] == '?' and jr[i] == '?':
                    cr[i] = '1'
                    jr[i] = '0'
                    search = False
            else:
                if cr[i] == '?' and jr[i] == '?':
                    cr[i] = '0'
                    jr[i] = '9'
    return ''.join(cr[::-1]), ''.join(jr[::-1])


def eq(c, j):
    cr = []
    jr = []
    for i in range(len(c)):
        if c[i] != '?':
            cr.append(c[i])
            jr.append(c[i])
        elif j[i] != '?':
            cr.append(j[i])
            jr.append(j[i])
        else:
            cr.append('0')
            jr.append('0')
    return ''.join(cr), ''.join(jr)

def solve(c, j):
    idx = None
    for i in range(len(c)):
        if c[i] != j[i] and c[i] != '?' and j[i] != '?':
            idx = i
            break
    if idx is None:
        cr, jr = eq(c, j)
        return cr + ' ' + jr

    # sol 1
    swap = False
    if int(j[idx]) < int(c[idx]):
        swap = True
        c, j = j, c

    cr, jr = eq(c[:idx], j[:idx])
    ct, jt = mx(c[idx+1:], j[idx+1:])
    c1 = cr + c[idx] + ct
    j1 = jr + j[idx] + jt

    #print(c, j)
    cr, jr = up(c[:idx], j[:idx])
    jt, ct = mx(j[idx+1:], c[idx+1:])
    c2 = cr + c[idx] + ct
    j2 = jr + j[idx] + jt

    if swap:
        c1, j1 = j1, c1
        c2, j2 = j2, c2

    c1n = int(c1)
    j1n = int(j1)
    c2n = int(c2)
    j2n = int(j2)
    d1 = abs(c1n - j1n)
    d2 = abs(c2n - j2n)

    if d1 < d2:
        cx = c1
        jx = j1
    elif d2 < d1:
        cx = c2
        jx = j2
    else:
        if c1n < c2n:
            cx = c1
            jx = j1
        else:
            if j1n < j2n:
                cx = c1
                jx = j1
            else:
                cx = c2
                jx = j2

    return cx + ' ' + jx


testcases = int(input())

for case_n in range(1, testcases+1):
    #case_data = map(int, input().split())
    case_data = input().split()
    print("Case #%i: %s" % (case_n, solve(*case_data)))
