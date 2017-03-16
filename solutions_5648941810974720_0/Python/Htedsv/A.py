import sys
import numpy as np
f = open(sys.argv[1])
T = int(f.readline())
for I in range(T):
    print 'Case #%d:'%(I+1),
    counts = {}
    for i in range(26):
        counts[chr(i+ord('A'))] = 0
    s = f.readline()[:-1]
    for c in s:
        counts[c] = counts.get(c, 0) + 1
    n = [0] * 10
    n[0] = counts['Z']
    n[6] = counts['X']
    n[2] = counts['W']
    n[4] = counts['U']
    n[8] = counts['G']
    n[5] = counts['F'] - n[4]
    n[1] = counts['O'] - n[0] - n[2] - n[4]
    n[3] = counts['H'] - n[8]
    n[7] = counts['S'] - n[6]
    n[9] = (counts['N'] - n[7] - n[1]) / 2

    ans = ''
    for i in range(10):
        ans += str(i) * n[i]
    print ans



    
