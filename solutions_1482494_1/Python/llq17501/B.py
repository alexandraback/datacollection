#!/usr/bin/env python
#-*- coding:utf-8 -*-

read_ints = lambda :map(int, raw_input().split(' '))
read_lines = lambda n:[raw_input().strip() for i in range(n)]
DEBUG = True

def debug(*args, **kwargs):
    if DEBUG:
        for i, v in enumerate(args):
            print i, v
        for k, v in kwargs.iteritems():
            print k, v


from collections import defaultdict
import bisect

def g(l, mapping, stars):
    for i, j in mapping[stars]:
        bisect.insort(l, (j + 1, stars, i))

def f(L):
    solved = set()
    stars = 0
    num = 0
    while stars < 2 * len(L):
        tmp = None
        num += 1
        for i, (a, b) in enumerate(L):
            if b <= stars and (i, 1) not in solved:
                if tmp is None or (1, 0, i) > tmp:
                    tmp = (1, 0, i)
            elif a <= stars and (i, 0) not in solved:
                if tmp is None or (0, b, i) > tmp:
                    tmp = (0, b, i)

        if tmp is None:
            return "Too Bad"
        else:
            j, _, i = tmp
            if j == 0 or (i, 0) in solved:
                stars += 1
            else:
                stars += 2
                solved.add((i, 0))
            solved.add((i, j))
    return num

def main():
    T = int(raw_input())
    for i in range(T):
        N = int(raw_input())
        L = []
        for j in range(N):
            a, b = read_ints()
            L.append((a, b))
        result = f(L)
        print "Case #{0}: {1}".format(i + 1, result)


if __name__ == "__main__":
    main()
