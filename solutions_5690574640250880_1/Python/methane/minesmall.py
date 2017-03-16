from __future__ import print_function
import sys


def solve_r1(C, M):
    L = '.' * (C-M) + '*' * M
    return [L]

def solve_r2(C, M):
    if M % 2 == 1:
        # M = 2*C-1 case is handled before.
        return None
    s = C - M//2
    return ['.'*s + '*'*(M//2)] * 2

def solve_r3(C, M):
    m = M // 3
    mm = M % 3
    s = 3 * C - M
    if s in (5, 7):
        return None
    if mm == 0:
        return ['.' * (C-m) + '*' * m] * 3
    if mm == 1:
        return ['.' * (C-m) + '*' * m] * 2 + ['.' * (C-m-1) + '*' * (m+1)]
    return ['.' * (C-m) + '*' * m] * 2 + ['.' * (C-m-2) + '*' * (m+2)]

def solve_rn(R, C, M):
    S = R * C - M
    if S in (0, 2, 3, 5, 7):
        return None

    rr = R
    cc = C
    mm = M
    while True:
        if rr < cc:
            if mm >= rr:
                cc -= 1
                mm -= rr
            else:
                break
        if mm >= cc:
            rr -= 1
            mm -= cc
        else:
            break

    ret = [['.'] * cc for _ in range(rr)]
    for i in range(min(cc-2, mm)):
        ret[-1][-1-i] = '*'
    for i in range(mm - (cc-2)):
        ret[-2-i][-1] = '*'

    ret = [''.join(L) + '*' * (C - cc) for L in ret]
    ret += ["*" * C] * (R - rr)
    return ret


def solve(R, C, M):
    # special cases
    if M == 0:
        return ['.'*C]*R  # (0,0) is overwritten to 'c'
    if M+1 == R*C:
        return ['*'*C]*R  # (0,0) is overwritten to 'c'
    if M == R*C:
        return None
    if R>1 and C>1 and M > (R*C-4):
        return None

    invert = False
    if R > C:
        R, C = C, R
        invert = True

    ret = None
    if R == 1:
        ret = solve_r1(C, M)
    elif R == 2:
        ret = solve_r2(C, M)
    elif M < (C - 1):  # Special case.
        ret = ['.' * C] * (R-1) + ['.' * (C-M) + '*' * M]
    elif R == 3:
        ret = solve_r3(C, M)
    else:
        ret = solve_rn(R, C, M)

    if ret is None:
        return None
    if invert:
        ret = [''.join(x) for x in zip(*ret)]
    return ret


def main():
    T = int(sys.stdin.readline())
    for t in range(1, T+1):
        r, c, m = map(int, sys.stdin.readline().split())
        ret = solve(r, c, m)
        print("Case #{}:".format(t))
        if ret is None:
            print("Impossible")
        else:
            ret[0] = 'c' + ret[0][1:]
            for L in ret:
                print(L)


def test():
    for r in range(2, 6):
        for c in range(r-1, 8):
            for m in range(0, r*c+1):
                print("Case", r, c, m)
                ret = solve(r, c, m)
                if ret is None:
                    print("Impossible")
                else:
                    ret[0] = 'c' + ret[0][1:]
                    for L in ret:
                        print(L)

main()
#test()
