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
    res = []
    start = int(A ** .5) if int(A ** .5) ** 2 == A else int(A ** .5) + 1
    end = int(B ** .5) + 1 if int(B ** .5) ** 2 == B else int(B ** .5)
    for i in range(start, end):
        if fair_and_squrare(i ** 2):
            res.append(i**2)
    return res

def main():
    L = solve(1, 10**14)
    T = int(sys.stdin.readline())
    for t in range(T):
        A, B = sys.stdin.readline().split()
        A = int(A)
        B = int(B)
        res = len([x for x in L if x >= A and x <= B])
        print "Case #%d: %s" % (t + 1, res)

if __name__ == '__main__':
    main()
