#!/usr/bin/python

import sys, math

"""
1 1
2 4
3 9
11 121
22 484
101 10201
111 12321
121 14641
202 40804
212 44944
1001 1002001
1111 1234321
2002 4008004
10001 100020001
10101 102030201
10201 104060401
11011 121242121
11111 123454321
11211 125686521
20002 400080004
20102 404090404
100001 10000200001
101101 10221412201
110011 12102420121
111111 12345654321
200002 40000800004
1000001 1000002000001
1001001 1002003002001
1002001 1004006004001
1010101 1020304030201
1011101 1022325232201
1012101 1024348434201
1100011 1210024200121
1101011 1212225222121
1102011 1214428244121
1110111 1232346432321
1111111 1234567654321
2000002 4000008000004
2001002 4004009004004
"""

def ispalindrome(x):
    return tuple(str(x)) == tuple(reversed(str(x)))

def main():
    T = int(sys.stdin.readline())
    A = []
    B = []
    for t in range(T):
        a, b = sys.stdin.readline().split()
        A.append(int(a))
        B.append(int(b))
    table = []
    for i in range(1, math.sqrt(max(B)) + 1):
        if ispalindrome(i) and ispalindrome(i*i):
            table.append(i*i)
    for t in range(T):
        a = A[t]
        b = B[t]
        count = 0
        for i in table:
            if a <= i <= b:
                count += 1
        print "Case #%d: %d" % (t + 1, count)

if __name__ == '__main__':
    main()

