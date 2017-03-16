from collections import Counter
from collections import defaultdict
import sys
import re

sys.setrecursionlimit(100000)

def check(a, b):
    for i in range(len(a)):
        if a[i] != '?':
            if a[i] != b[i]:
                return False
    return True

with open('input.txt', 'r') as input, open('output.txt', 'w') as output:
    tt = int(next(input))
    for test in range(tt):
        print (test)
        a, b = next(input).split()
        n = len(a)
        x1, y1 = a.replace('?', '0'), b.replace('?', '0')
        best = abs(int(x1) - int(y1))
        for i in range(10**n):
            for j in range(10**n):
                if best > abs(i - j):
                    x, y = str(i).zfill(n), str(j).zfill(n)
                    if check(a, x) and check(b, y):
                        best = abs(i - j)
                        x1, y1 = x, y

        ans = [x1, y1]
        output.write('Case #{}: {}\n'.format(test + 1, ' '.join(ans)))
