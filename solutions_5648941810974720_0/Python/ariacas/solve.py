import sys
import numpy
import random

digs = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
A = numpy.zeros((26, 26))
for i in range(0, 10):
    for ch in digs[i]:
        A[ord(ch) - ord('A')][i] += 1

for i in range(10, 26):
    for j in range(0, 26):
        A[j][i] = random.randint(0, 5)
#print A

T = int(sys.stdin.readline())
for test in range(1, T+1):
    sys.stdout.write("Case #%d: " % test)
    s = sys.stdin.readline()
    c = numpy.zeros(26)
    for ch in s[:-1]:
        c[ord(ch)-ord('A')] += 1
    x = numpy.linalg.solve(A, c)
    for i in range(0, 10):
        t = int(round(x[i]))
        for j in range(0, t):
            sys.stdout.write("%d" % i)
    sys.stdout.write("\n")
