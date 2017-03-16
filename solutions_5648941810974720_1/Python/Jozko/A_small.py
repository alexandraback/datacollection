import sys
import numpy as np
from collections import defaultdict
T = int(sys.stdin.readline())

def subtract(word, count, N):
    if N == 0:
        return
    for c in word:
        count[c] -= N

for case in range(1, T+1):
    sys.stdout.write("Case #%d: " % case)
    line = sys.stdin.readline().strip().lower()
    counts = defaultdict(int)
    for c in line:
        counts[c] = counts.get(c, 0) + 1
    numbers = [0]*10
    numbers[0] = counts['z']
    subtract('zero', counts, numbers[0])
    numbers[2] = counts['w']
    subtract('two', counts, numbers[2])
    numbers[4] = counts['u']
    subtract('four', counts, numbers[4])
    numbers[6] = counts['x']
    subtract('six', counts, numbers[6])
    numbers[8] = counts['g']
    subtract('eight', counts, numbers[8])
    numbers[5] = counts['f']
    subtract('five', counts, numbers[5])
    numbers[7] = counts['s']
    subtract('seven', counts, numbers[7])
    numbers[1] = counts['o']
    subtract('one', counts, numbers[1])
    numbers[3] = counts['h']
    subtract('three', counts, numbers[3])
    numbers[9] = counts['i']
    for i, d in enumerate(numbers):
        assert d>=0
        if d != 0:
            sys.stdout.write(str(i)*d)
    sys.stdout.write('\n')



