#!/usr/bin/env python

dictionary = [
    1,
    4,
    9,
    121,
    484,
    10201,
    12321,
    14641,
    40804,
    44944,
    1002001,
    1234321,
    4008004,
    100020001,
    102030201,
    104060401,
    121242121,
    123454321,
    125686521,
    400080004,
    404090404,
    10000200001,
    10221412201,
    12102420121,
    12345654321,
    40000800004,
    1000002000001,
    1002003002001,
    1004006004001,
    1020304030201,
    1022325232201,
    1024348434201,
    1210024200121,
    1212225222121,
    1214428244121,
    1232346432321,
    1234567654321,
    4000008000004,
    4004009004004,
    100000020000001,
    100220141022001,
    102012040210201,
    102234363432201,
    121000242000121,
    121242363242121,
    123212464212321,
    123456787654321,
    400000080000004,
]

def print_result(case_no, msg):
        print "Case #%d: %d" % (case_no, msg)

def get_interval(a):
    for i, value in enumerate(dictionary):
        if value > a:
            return i
    return len(dictionary)
    
def run_case(case_no):
    A, B = raw_input().split(' ')
    A, B = int(A), int(B)

    start = get_interval(A)
    end = get_interval(B)
    if A in dictionary:
        print_result(case_no, end - start + 1)
    else:
        print_result(case_no, end - start)


if __name__ == '__main__':
    num = int(raw_input())
    for i in xrange(num):
        run_case(i + 1)
