import sys


def line():
    return sys.stdin.readline().strip()

def ints(s):
    return [int(t) for t in s.split()]

def is_palindrome(i):
    return str(i) == str(i)[::-1]

table = [
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
    400000080000004
]


def solve(a,b):
    res = 0
    for v in table:
        if a <= v and b >= v:
            res += 1
    return res


def main():
    tc = int(line())
    for i in range(1,tc+1):
        a,b = ints(line())
        print 'Case #%s: %s' % (i, solve(a,b))


main()


# def palindroms():
#     i = 0
#     while True:
#         try:
#             i += 1
#             if is_palindrome(i) and is_palindrome(i**2):
#                 print i**2, i
#         except KeyboardInterrupt:
#             print 'Processed so far: %.1e (%d)' % (i**2,i**2) 
#             pass

# palindroms()
