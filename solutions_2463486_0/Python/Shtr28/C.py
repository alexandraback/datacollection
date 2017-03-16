#!/usr/bin/env python
# -*- coding: utf-8 -*

from math import sqrt

def is_palindlome(num_str) :
    if len(num_str) == 1:
        return True
    first, last = 0, len(num_str)-1
    while first != len(num_str)  :
        if num_str[first] != num_str[last]:
            return False
        first += 1
        last -= 1
    return True

memo = [0, 1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004]

def solve():
    A_B  = map(int, raw_input().split())
    A, B = A_B[0], A_B[1]
    ans = 0
    for i in memo:
        if i < A:
           continue
        if B < i:
            break
        ans += 1
    return ans

# def upper_bound(key, begin, end):
#     lb, ub = begin - 1, end
#     while ub - lb > 1:
#         mid = (lb + ub) / 2
#         if memo[mid] <= key:
#             lb = mid
#         else :
#             ub = mid
#     return lb
    

# def lower_bound(key, begin, end):
#     lb, ub = begin - 1, end
#     while ub - lb > 1:
#         mid = (lb + ub) / 2
#         if memo[mid] >= key:
#             ub = mid
#         else :
#             lb = mid
#     return ub


def main():
    # for i in xrange(10**7 + 1):
    #     ii = i ** 2
    #     if is_palindlome(str(ii)) and is_palindlome(str(i)):
    #         memo.append(ii)
    #         print i, is_palindlome(str(i)), ii, is_palindlome(str(ii))
    # print memo
    T = input()
    for i in range(T):
        print "Case #%d: %d" % (i+1, solve())
    
if __name__ == '__main__':
    main()


    
