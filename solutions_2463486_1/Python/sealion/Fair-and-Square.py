import math
import sys


def is_palindrome(n):
    s = str(n)
    l = list(s)
    l.reverse()
    return list(s) == l


def find_numbers(A, B):
    ns = range(int(math.ceil(math.sqrt(A))), int(math.floor(math.sqrt(B))) + 1)
    for n in ns:
        n2 = n * n
        if is_palindrome(n) and is_palindrome(n2):
            yield n2


inp = sys.stdin

T = int(inp.readline())
numbers = list(find_numbers(1, 10 ** 14))
for case_number in range(1, T + 1):
    A, B = map(int, inp.readline().split())
    c = sum(1 for n in numbers if A <= n <= B)
    print 'Case #%d: %d' % (case_number, c)
