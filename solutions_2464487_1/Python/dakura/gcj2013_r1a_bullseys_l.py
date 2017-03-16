#! /usr/bin/env python
# -*- coding:utf-8 -*-
import sys

def calc_paint(n):
    return 2*n-1

def calc_paint_delta(r, m):
    return 2*r*m + ((4*m+2)*m)/2

def doit(r, t):
    max_ans = 200000000000000000
    answer = 0
    r_paint = calc_paint(r+1)

    win = max_ans
    prev_win = win
    step = win/2
    while win > 0:
        need = calc_paint_delta(r+1, step)
        if t < need:
            step -= win/4
        elif t == need:
            return answer
        else:
            step += win/4
        prev_win = win
        win /= 2

    answer = max(0, step-1000)
    while True:
        delta = calc_paint_delta(r+1, answer)
        if t < delta+r_paint:
            break
        answer += 1
    return answer

if __name__ == '__main__':
    f = open(sys.argv[1])

    num_of_case = int(f.readline())
    for i in range(num_of_case):
        (r, t) = map(int, f.readline().rstrip().split())
        answer = doit(r, t)
        print "Case #%d: %d" % (i+1, answer)

# sort by key
# for k,v in sorted(d.items())
# sort by value
# for k,v in sorted(d.items(), key=lambda x:x[1])
# items() return tapple, tapple[0] is k, tapple[1] is v
#
# import copy
# copy.copy()
# copy.deepcopy()
#
# a = [0]*100
#
# for tc in xrange(1, int(sys.stdin.readline())+1):
#   A, B = [int(w) for w in sys.stdin.readline().split()]
#   p = [float(w) for w in sys.stdin.readline().split()]
#
# array = [[0 for j in range(m)] for i in range(n)]

