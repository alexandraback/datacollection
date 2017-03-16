# -*- coding:utf-8 -*-

import sys


def palindrome(x):
    L = str(x)
    return L == L[::-1]

def square(x):
    return int(x**.5)**2 == x

def fair_and_squrare(x):
    return square(x) and palindrome(x) and palindrome(int(x ** .5))

def solve(A, B):
    res = 0
    for i in range(A, B + 1):
        if fair_and_squrare(i):
            res += 1
    return res

def main():
    T = int(sys.stdin.readline())
    for t in range(T):
        A, B = sys.stdin.readline().split()
        A = int(A)
        B = int(B)
        print "Case #%d: %s" % (t + 1, solve(A, B))

if __name__ == '__main__':
    main()
