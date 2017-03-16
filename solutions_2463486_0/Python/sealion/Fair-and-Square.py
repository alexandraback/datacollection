import math
import sys


def is_palindrome(n):
    s = str(n)
    l = list(s)
    l.reverse()
    return list(s) == l


inp = sys.stdin

T = int(inp.readline())
for case_number in range(1, T + 1):
    A, B = map(int, inp.readline().split())
    c = 0
    for n in range(int(math.ceil(math.sqrt(A))), int(math.floor(math.sqrt(B))) + 1):
        if is_palindrome(n) and is_palindrome(n * n):
            c += 1
    print 'Case #%d: %d' % (case_number, c)
