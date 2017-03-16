import time
import math
filename = 'A-small-attempt0'
with open(filename + '.in', 'r') as f:
    data_raw = f.readlines()
f.closed

starttime = time.time()

data_raw = data_raw[1:]

outputs = []

def solve(input):
    R, C, W = input
    if W == 1:
        return R * C
    if W == C:
        return R + C - 1

    mod = 0    
    if C % W == 0:
        mod = 1
    p = C/W
    
    return p * R + W - mod
    
for line in data_raw:
    line = [int(x) for x in line.strip().split(' ')]
    outputs.append(solve(line))

with open(filename + '.out', 'w') as f:
    i = 1
    outputstrings= []
    for output in outputs:
        outputstrings.append('Case #{0}: {1}'.format(i, output))
        i += 1
    f.write('\n'.join(outputstrings))
f.closed

print time.time() - starttime