import sys
from fractions import gcd


sys.stdin = open("input.txt")
sys.stdout = open("output.txt", "w+")

N = input()

for t_case in range(1, N + 1):
    A, B = map(int, raw_input().split("/"))
    if A == B:
        print "Case #%s: 0" % t_case
        continue

    d = gcd(A, B)
    A /= d
    B /= d

    B_copy = B
    while B_copy % 2 == 0:
        B_copy /= 2

    if B_copy > 1:
        print "Case #%s: impossible" % t_case
        continue

    result = 0
    D = 1
    for i in range(40):
        D *= 2
        if A >= B / D:
            result = i + 1
            break

    if result == 0:
        print "Case #%s: impossible" % t_case
    else:
        print "Case #%s: %s" % (t_case, result)
