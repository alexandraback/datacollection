from __future__ import print_function
import sys
import fractions

f = sys.stdin

if len(sys.argv) > 1:
    f = open(sys.argv[1], "rt")


T = int(f.readline().strip())

for case_id in range(1, T+1):
    P, Q = map(long, f.readline().strip().split('/'))
    #~ print(P, Q)
    fr = fractions.Fraction(P, Q)
    P, Q = fr.numerator, fr.denominator
    #~ print(P, Q)

    r = -1

    # Check.
    q = Q
    while q % 2 == 0:
        q = q // 2
    if q != 1:
        r = 'impossible'
    else:
        r = 1
        while True:
            Q = Q // 2
            if P >= Q:
                break
            r += 1

    print(str.format('Case #{0}: {1}', case_id, r))
