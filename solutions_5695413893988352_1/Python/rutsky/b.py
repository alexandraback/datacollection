# B
import sys

#sys.stdin = open("small.in", "rt")
#sys.stdout = open("small.out", "wt")
#sys.stdin = open("B-small-attempt0.in", "rt")
#sys.stdout = open("B-small-attempt0.out", "wt")
sys.stdin = open("B-large.in", "rt")
sys.stdout = open("B-large.out", "wt")


def solve_impl(C, J):
    if not C:
        return 0, '', ''

    for i in range(len(C)):
        if C[i] == '?' or J[i] == '?':
            break
    else:
        return abs(int(C) - int(J)), C, J

    c1 = int(C[:i] or 0)
    j1 = int(J[:i] or 0)

    if c1 != j1:
        if c1 < j1:
            CC = C.replace('?', '9')
            JJ = J.replace('?', '0')
        else:
            CC = C.replace('?', '0')
            JJ = J.replace('?', '9')
        return abs(int(CC) - int(JJ)), CC, JJ

    if C[i] != '?':
        assert J[i] == '?'
        res1 = solve_impl(C[i:], C[i] + J[i + 1:])
        res2 = solve_impl(C[i:], str(((int(C[i]) + 1) % 10)) + J[i + 1:])
        res3 = solve_impl(C[i:], str(((int(C[i]) + 9) % 10)) + J[i + 1:])

        diff, CC, JJ = sorted([res1, res2, res3])[0]
        return diff, C[:i] + CC, J[:i] + JJ

    elif J[i] != '?':
        assert C[i] == '?'
        res1 = solve_impl(J[i] + C[i + 1:], J[i:])
        res2 = solve_impl(str(((int(J[i]) + 1) % 10)) + C[i + 1:], J[i:])
        res3 = solve_impl(str(((int(J[i]) + 9) % 10)) + C[i + 1:], J[i:])

        diff, CC, JJ = sorted([res1, res2, res3])[0]
        return diff, C[:i] + CC, J[:i] + JJ

    else:
        assert C[i] == '?' and J[i] == '?'

        res1 = solve_impl('0' + C[i + 1:], '0' + J[i + 1:])
        res2 = solve_impl('0' + C[i + 1:], '1' + J[i + 1:])
        res3 = solve_impl('1' + C[i + 1:], '0' + J[i + 1:])

        diff, CC, JJ = sorted([res1, res2, res3])[0]
        return diff, C[:i] + CC, J[:i] + JJ


def solve(C, J):
    return solve_impl(C, J)[1:]

if False:
    C, J = solve('?' * 18, '?' * 18)
    assert C == '0' * 18
    assert J == '0' * 18
    C, J = solve('?1?', '?9?')
    assert C == '110'
    assert J == '099'

else:
    cases = int(input())
    for case_idx in range(cases):
        C, J = input().split()
        print("Case #{}: {} {}".format(case_idx + 1, *solve(C, J)))
