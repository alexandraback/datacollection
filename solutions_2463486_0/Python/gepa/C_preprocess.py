import sys
import math


fairsquares = set()


def make_palindrome(n, d):
    a = n
    b = n / d
    while (b > 0):
        a = 10 * a + b % 10
        b /= 10
    return a


def add_if_palindrome(n):
    global fairsquares
    n2 = n * n
    s = str(n2)
    if s == s[::-1]:
        fairsquares.add(n2)


for i in xrange(1, 100000):
    add_if_palindrome(make_palindrome(i, 1))
    add_if_palindrome(make_palindrome(i, 10))
for i in xrange(2 ** 27):
    b = bin(i)
    num_bits = b.count('1')
    if num_bits > 5:
        continue
    if num_bits == 1:
        print b
    add_if_palindrome(make_palindrome(int(b[2:]), 1))
    add_if_palindrome(make_palindrome(int(b[2:]), 10))
    add_if_palindrome(make_palindrome(int(b[2:] + '2'), 10))
    add_if_palindrome(make_palindrome(int('2' + b[3:]), 1))
    add_if_palindrome(make_palindrome(int('2' + b[3:]), 10))

fairsquares = sorted(fairsquares)

f = open('fairsquares.txt', 'w')
for i in xrange(len(fairsquares)):
    f.write("%d\n" % fairsquares[i])
f.close()
print len(fairsquares)
