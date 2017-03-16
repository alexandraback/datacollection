from fractions import *

T = int(raw_input())
for t in range(T):
    r = Fraction(raw_input())
    found = False
    for i in range(40):
        if r.denominator == 2 ** (i + 1):
            found = True
            break
    if not found:
        print "Case #" + str(t + 1) + ": " + "impossible"
        continue

    found = False
    for i in range(40):
        if r >= Fraction(1, 2 ** (i + 1)):
            print "Case #" + str(t + 1) + ": " + str(i + 1)
            found = True
            break

    if not found:
        print "Case #" + str(t + 1) + ": " + "impossible"

