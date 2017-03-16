#/usr/local/bin/python

import sys

T = int(sys.stdin.readline())

psquares = [ ]

n = 1

while n < 10000000:
    sstr = str(n*n)
    pstr = str(n)

    if sstr == sstr[::-1] and pstr == pstr[::-1]:
        psquares.append(n*n)

    n += 1

for caseno in xrange(T):
    A, B = sys.stdin.readline().split()
    A = int(A)
    B = int(B)

    ans = 0

    for ps in psquares:
        if A <= ps and B >= ps:
            ans += 1
        if ps > B:
            break

    print "Case #%d: %d" % (caseno + 1, ans)


