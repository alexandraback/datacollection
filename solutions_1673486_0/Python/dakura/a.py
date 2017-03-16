#! /usr/bin/env python
# -*- coding:utf-8 -*-
import sys

sys.setrecursionlimit(1100)
#sys.maxint
#-sys.maxint-1

def solveit(A, B, Ps):
    # enter
    answer = 1.0*(1+B+1)

    # calculate n backspaces case
    p_allright = 1.0
    for i in range(1, A+1):
        tmp_p_allright = p_allright*Ps[i-1]
        expected = tmp_p_allright*((A-i)+(B-i)+1) + (1.0-tmp_p_allright)*((A-i)+(B-i)+1+B+1)
        if answer:
            answer = min(answer, expected)
        else:
            answer = expected
        p_allright = tmp_p_allright

    # keep typing
    expected = p_allright*(B-A+1) + (1.0-p_allright)*(B-A+1+B+1)
    return min(answer, expected)

if __name__ == '__main__':
    f = open(sys.argv[1])

    num_of_case = int(f.readline())
    for i in range(num_of_case):
        params = map(int, f.readline().rstrip().split())
        A = params[0]
        B = params[1]
        Ps = map(float, f.readline().rstrip().split())
        answer = solveit(A, B, Ps)
        print "Case #%d: %f" % (i+1, answer)

