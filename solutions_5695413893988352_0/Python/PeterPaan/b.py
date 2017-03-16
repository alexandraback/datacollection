#!/usr/bin/python3
import sys

def minidiff(tc, C, J):
    C1, J1 = minirec(list(C), list(J))
    print('Case #{}: {} {}'.format(tc, list_to_string(C1), list_to_string(J1)))

def list_to_string(l):
    s = ''
    for c in l:
        s += c
    return s

def list_replace(l, f, to):
    return [c if c != f else to for c in l]

def minchr0(n):
    if n == '0':
        return '0'
    else:
        return chr(ord(n) - 1)

def maxchr9(n):
    if n == '9':
        return '9'
    else:
        return chr(ord(n) + 1)

def list_diff(c1, c2):
    return abs(int(list_to_string(c1)) - int(list_to_string(c2)))

def minirec(C, J):
    if len(C) == 0:
        return C, J
    else:
        c0 = C[0]
        j0 = J[0]
        if c0 != '?' and j0 != '?':
            if c0 > j0:
                return list_replace(C, '?', '0'), list_replace(J, '?', '9')
            elif c0 < j0:
                return list_replace(C, '?', '9'), list_replace(J, '?', '0')
            else: # c0 == j0
                if len(C) == 1:
                    return list(c0), list(j0)
                else:
                    c1, j1 = minirec(C[1:], J[1:])
                    c1.insert(0, c0)
                    j1.insert(0, j0)
                    return c1, j1
        elif c0 == '?' and j0 != '?':
            # try c0 = j0 - 1, j0, j0 + 1
            c_0 = list(C)
            c_0[0] = minchr0(j0)
            j_0 = list(J)
            c_0, j_0 = minirec(c_0, j_0)
            diff_0 = list_diff(c_0, j_0)

            c_01 = list(C)
            c_01[0] = j0
            j_01 = list(J)
            c_01, j_01 = minirec(c_01, j_01)
            diff_01 = list_diff(c_01, j_01)

            c_10 = list(C)
            c_10[0] = maxchr9(j0)
            j_10 = list(J)
            c_10, j_10 = minirec(c_10, j_10)
            diff_10 = list_diff(c_10, j_10)

            if diff_0 <= diff_01 and diff_0 <= diff_10:
                return c_0, j_0
            elif diff_01 < diff_0 and diff_01 <= diff_10:
                return c_01, j_01
            else:
                return c_10, j_10
        elif c0 != '?' and j0 == '?':
            c_0 = list(C)
            j_0 = list(J)
            j_0[0] = minchr0(c0)
            c_0, j_0 = minirec(c_0, j_0)
            diff_0 = list_diff(c_0, j_0)

            c_01 = list(C)
            j_01 = list(J)
            j_01[0] = c0
            c_01, j_01 = minirec(c_01, j_01)
            diff_01 = list_diff(c_01, j_01)

            c_10 = list(C)
            j_10 = list(J)
            j_10[0] = maxchr9(c0)
            c_10, j_10 = minirec(c_10, j_10)
            diff_10 = list_diff(c_10, j_10)

            if diff_0 <= diff_01 and diff_0 <= diff_10:
                return c_0, j_0
            elif diff_01 < diff_0 and diff_01 <= diff_10:
                return c_01, j_01
            else:
                return c_10, j_10
        else: # c0 == j0 == '?'
            c_0 = list(C)
            c_0[0] = '0'
            j_0 = list(J)
            j_0[0] = '0'
            c_0, j_0 = minirec(c_0, j_0)
            diff_0 = list_diff(c_0, j_0)

            c_01 = list(C)
            c_01[0] = '0'
            j_01 = list(J)
            j_01[0] = '1'
            c_01, j_01 = minirec(c_01, j_01)
            diff_01 = list_diff(c_01, j_01)

            c_10 = list(C)
            c_10[0] = '1'
            j_10 = list(J)
            j_10[0] = '0'
            c_10, j_10 = minirec(c_10, j_10)
            diff_10 = list_diff(c_10, j_10)

            if diff_0 <= diff_01 and diff_0 <= diff_10:
                return c_0, j_0
            elif diff_01 < diff_0 and diff_01 <= diff_10:
                return c_01, j_01
            else:
                return c_10, j_10


def main():
    nbtc = sys.stdin.readline()
    for it,line in enumerate(sys.stdin.readlines()):
        tc = it + 1
        C, J = line.strip().split(' ')[0:2]
        minidiff(tc, C, J)
main()
