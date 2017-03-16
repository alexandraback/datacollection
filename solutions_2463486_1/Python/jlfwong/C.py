import sys
from math import sqrt

small_palindromes = []

MAXB = 10 ** 14
# MAXB = 1000
# MAXB = 10 ** 24
sqrtMAXB = sqrt(MAXB)

i = 0
while True:
    ii = int(str(i) + ''.join(reversed(str(i))))
    i1i = int(str(i) + ''.join(reversed(str(i)))[1:])

    if i1i <= sqrtMAXB:
        small_palindromes.append(i1i)
    else:
        break

    if ii <= sqrtMAXB:
        small_palindromes.append(ii)

    i += 1

squares_of_palindromes = [p * p for p in small_palindromes]

def ispalindrome(n):
    strn = str(n)
    lenn = len(strn)

    return strn[0:lenn/2] == ''.join(reversed(strn))[0:lenn/2]

fair_and_square = set([sp for sp in squares_of_palindromes if ispalindrome(sp)])

casenum = 1
def doit(case):
    global casenum

    A, B = [int(x) for x in case.split(' ')]

    print 'Case #%d: %d' % (casenum, len([x for x in fair_and_square if A <= x <= B]))
    casenum += 1

raw = [x.strip() for x in sys.stdin.readlines()]
ZZZ = int(raw[0])
data = raw[1:]
for case in range(ZZZ):
    doit(data[case])
