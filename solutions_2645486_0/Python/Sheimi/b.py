#!/usr/bin/env python
import math

def print_result(case_no, msg):
    print "Case #%d: %s" % (case_no, msg)


def compute(v, index, E, R, c, result, rrrr):
    if len(v) == index + 1:
        result += v[index] * c;
        return result
    r = result;
    for i in range(c + 1):
        rrrrr = list(rrrr)
        rrrrr.append(i)
        cc = c
        cc -= i
        cc += R
        if cc > E:
            continue
        tmp_r = result + i * v[index]
        tmp_r = compute(v, index + 1, E, R, cc, tmp_r, rrrrr)
        r = max(tmp_r, r)
    return r


def run_case(case_no):
    E, R, N = raw_input().split()
    E, R, N = int(E), int(R), int(N)
    v = [int(i) for i in raw_input().split()]
    result = compute(v, 0, E, R, E, 0, [])
    print_result(case_no, result)


if __name__ == '__main__':
    num = int(raw_input())
    for i in xrange(num):
        run_case(i + 1)
