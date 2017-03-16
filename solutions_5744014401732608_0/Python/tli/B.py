from heapq import *

t = input()

for i in xrange(t):
    b, m = map(int, raw_input().split(" "))

    m = m - 1
    binary = []

    for j in xrange(b-2):
        binary.append(m % 2)
        m /= 2

    if m > 0:
        print "Case #" + str(i + 1) + ": IMPOSSIBLE"
        continue

    print "Case #" + str(i + 1) + ": POSSIBLE"
    print "0" + "1" * (b - 1)
    for j in xrange(b - 2):
        print "0" * (j + 2) + "1" * (b - j - 3 + binary[j]) + "0" * (1 - binary[j])
    print "0" * b