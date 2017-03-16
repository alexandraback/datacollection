#!/usr/bin/python

import sys

def solve_trivial(C, J):
    n = len(C)
    ans = list(C)
    for i in range(n):
        if ans[i] == '?':
            ans[i] = J[i] if J[i] != '?' else '0'
    return ans, ans

def better(sol1, sol2):
    if sol1 is None:
        return sol2
    elif sol2 is None:
        return sol1

    c1, j1 = sol1
    c2, j2 = sol2
    c1, j1 = int(''.join(c1)), int(''.join(j1))
    c2, j2 = int(''.join(c2)), int(''.join(j2))

    if abs(c1 - j1) < abs(c2 - j2):
        return sol1
    elif abs(c1 - j1) > abs(c2 - j2):
        return sol2
    else:
        if c1 < c2:
            return sol1
        elif c1 > c2:
            return sol2
        else:
            if j1 < j2:
                return sol1
            else:
                return sol2

def fill(s, c):
    s = list(s)
    for i in range(len(s)):
        if s[i] == '?':
            s[i] = c
    return s

def solve_lt(C, J, i):
    def solve_lt1(C, J, i):
        n = len(C)
        c, j = list(C), list(J)
        cp, jp = solve_trivial(C[:i], J[:i])
        c[:i], j[:i] = cp, jp
        c[i:], j[i:] = fill(c[i:], '9'), fill(j[i:], '0')
        return c, j

    def solve_lt2(C, J, i):
        n = len(C)
        c, j = list(C), list(J)

        ok = False
        for k in range(i - 1, -1, -1):
            if c[k] == '?' and j[k] == '?':
                c[k], j[k] = '1', '0'
                ok = True
                break
            elif c[k] == '?' and j[k] != '?':
                if j[k] != '9':
                    c[k] = str(int(j[k]) + 1)
                    ok = True
                    break
            elif c[k] != '?' and j[k] == '?':
                if c[k] != '0':
                    j[k] = str(int(c[k]) - 1)
                    ok = True
                    break
        if ok:
            c[:k], j[:k] = solve_trivial(c[:k], j[:k])
            c[k:], j[k:] = fill(c[k:], '0'), fill(j[k:], '9')
            return c, j
        else:
            return None
    return better(solve_lt1(C, J, i), solve_lt2(C, J, i))

def solve_gt(C, J, i):
    def solve_gt1(C, J, i):
        n = len(C)
        c, j = list(C), list(J)
        cp, jp = solve_trivial(C[:i], J[:i])
        c[:i], j[:i] = cp, jp
        c[i:], j[i:] = fill(c[i:], '0'), fill(j[i:], '9')
        return c, j

    def solve_gt2(C, J, i):
        n = len(C)
        c, j = list(C), list(J)

        ok = False
        for k in range(i - 1, -1, -1):
            if c[k] == '?' and j[k] == '?':
                c[k], j[k] = '0', '1'
                ok = True
                break
            elif c[k] == '?' and j[k] != '?':
                if j[k] != '0':
                    c[k] = str(int(j[k]) - 1)
                    ok = True
                    break
            elif c[k] != '?' and j[k] == '?':
                if c[k] != '9':
                    j[k] = str(int(c[k]) + 1)
                    ok = True
                    break
        if ok:
            c[:k], j[:k] = solve_trivial(c[:k], j[:k])
            c[k:], j[k:] = fill(c[k:], '9'), fill(j[k:], '0')
            return c, j
        else:
            return None

    def solve_gt3(C, J, i):
        n = len(C)
        c, j = list(C), list(J)

        for k in range(i - 1, -1, -1):
            if j[k] != '?' and j[k] != '0':
                c[k] = str(int(j[k]) - 1)
                c[:k], j[:k] = solve_trivial(c[:k], j[:k])
                c[k:], j[k:] = fill(c[k:], '9'), fill(j[k:], '0')
                return c, j

        ok = False
        for k in range(i - 1, -1, -1):
            if c[k] == '?' and j[k] == '?':
                c[k], j[k] = '0', '1'
                ok = True
                break
            elif c[k] == '?' and j[k] != '?':
                if j[k] != '0':
                    c[k] = str(int(j[k]) - 1)
                    ok = True
                    break
            elif c[k] != '?' and j[k] == '?':
                if c[k] != '9':
                    j[k] = str(int(c[k]) + 1)
                    ok = True
                    break
        if ok:
            c[:k], j[:k] = solve_trivial(c[:k], j[:k])
            c[k:], j[k:] = fill(c[k:], '9'), fill(j[k:], '0')
            return c, j
        else:
            return None

    def solve_gt4(C, J, i):
        n = len(C)
        c, j = list(C), list(J)

        for k in range(i - 1, -1, -1):
            if c[k] != '?' and c[k] != '9':
                j[k] = str(int(c[k]) + 1)
                c[:k], j[:k] = solve_trivial(c[:k], j[:k])
                c[k:], j[k:] = fill(c[k:], '9'), fill(j[k:], '0')
                return c, j

        ok = False
        for k in range(i - 1, -1, -1):
            if c[k] == '?' and j[k] == '?':
                c[k], j[k] = '0', '1'
                ok = True
                break
            elif c[k] == '?' and j[k] != '?':
                if j[k] != '0':
                    c[k] = str(int(j[k]) - 1)
                    ok = True
                    break
            elif c[k] != '?' and j[k] == '?':
                if c[k] != '9':
                    j[k] = str(int(c[k]) + 1)
                    ok = True
                    break
        if ok:
            c[:k], j[:k] = solve_trivial(c[:k], j[:k])
            c[k:], j[k:] = fill(c[k:], '9'), fill(j[k:], '0')
            return c, j
        else:
            return None
    sol = better(solve_gt1(C, J, i), solve_gt2(C, J, i))
    sol = better(sol, solve_gt3(C, J, i))
    sol = better(sol, solve_gt4(C, J, i))
    return sol

def solve_eq(C, J, i):
    n = len(C)
    c, j = list(C), list(J)
    c[:i], j[:i] = solve_trivial(c[:i], j[:i])
    c[i + 1:], j[i + 1:] = solve(c[i + 1:], j[i + 1:])
    return c, j

def solve(C, J):
    n = len(C)
    found = None
    for i in range(n):
        if C[i] != '?' and J[i] != '?':
            found = i
            break
    if found is None:
        return solve_trivial(C, J)
    elif C[i] < J[i]:
        return solve_lt(C, J, i)
    elif C[i] > J[i]:
        return solve_gt(C, J, i)
    else:
        return solve_eq(C, J, i)

T = int(input())
for t in range(T):
    S = input()
    C, J = S.split()
    c, j = solve(list(C), list(J))
    c, j = ''.join(c), ''.join(j)
    ans = ' '.join([c, j])
    print('Case #{}: {}'.format(t + 1,  ans))

