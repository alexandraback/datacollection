#!/usr/bin/env python

import sys

def is_palindrome(n):
  k = str(n)
  return k == k[::-1]


def main():
      
#    # Build list of values.
#    l = []
#    for i in xrange(1, 10**7+1):
#        if is_palindrome(i) and is_palindrome(i**2):
#            l.append(i**2)
#
#    l = list(set(l))
#    print l

    l = [1234567654321, 1, 1020304030201, 400080004, 1000002000001, 9, 1004006004001, 4000008000004, 44944, 1234321, 121, 10201, 1002003002001, 4, 4004009004004, 12321, 404090404, 12345654321, 40000800004, 123454321, 12102420121, 14641, 121242121, 1214428244121, 1210024200121, 1232346432321, 10000200001, 4008004, 100020001, 1022325232201, 102030201, 40804, 484, 1002001, 10221412201, 1024348434201, 104060401, 1212225222121, 125686521]


    T = input()
    for x in range(1, T+1):
        a,b = map(int,raw_input().split())
        count = 0
        for v in l:
            if a <= v and v <= b:
                count = count+1
        print "Case #" + str(x) + ": " + str(count)


if __name__ == "__main__":
    main()
