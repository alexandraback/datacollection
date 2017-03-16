#! /usr/bin/env python

from sys import stdin
from bisect import bisect_left, bisect_right

def possibile(fine, cifre):
    inizio = int('{}'.format(fine+10**cifre)[:0:-1])

    fine2 = fine**2 % 10**cifre
    inizio2 = int('{}'.format(fine2+10**cifre)[:0:-1])

    a, b = int('{}'.format(inizio**2)[:cifre]), int('{}'.format((inizio+1)**2-1)[:cifre])
    if b < a:
        b *= 10

    return a <= inizio2 <= b

def palindromo(n):
    s = '{}'.format(n)
    if s == s[::-1]:
        return True
    return False

finali_possibili = [1, 2, 3]

fs = []

for i in finali_possibili:
    f = '{}'.format(i+10)[1:]
    a = int(f[::-1]+f)**2
    b = int(f[:0:-1]+f)**2
    if palindromo(a):
        fs.append(a)
    if palindromo(b):
        fs.append(b)

for cifre in xrange(2,5):
    n_fine = [j*10**(cifre-1)+i for j in range(10) for i in finali_possibili]
    finali_possibili = [i for i in n_fine if possibile(i, cifre)]
    for i in finali_possibili:
        f = '{}'.format(i+10**cifre)[1:]
        a = int(f[::-1]+f)**2
        b = int(f[:0:-1]+f)**2
        if palindromo(a):
            fs.append(a)
        if palindromo(b):
            fs.append(b)

fs.sort()

ntest = input()

for test in xrange(ntest):
    a, b = [int(i) for i in stdin.readline().strip().split(' ')]
    result = bisect_right(fs, b) - bisect_left(fs, a)
    print "Case #{}: {}".format(test+1, result)
