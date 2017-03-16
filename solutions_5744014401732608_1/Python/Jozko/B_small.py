import sys
import numpy as np
T = int(sys.stdin.readline())
for case in range(1, T+1):
    sys.stdout.write("Case #%d: " % case)
    B, M = map(int, sys.stdin.readline().split())
    #print B, M
    possible = 1 if B <= 2 else 2**(B-2)
    if possible < M:
        sys.stdout.write('IMPOSSIBLE\n')
        continue
    bits = bin(M)[2:]
    bits = '0'*(B-1-len(bits)) + bits
    grid = np.zeros((B, B))
    for i in range(1, B):
        for j in range(i+1, B):
            grid[i, j] = 1
    if bits[0] == '1':
        grid[0, :] = 1
        grid[0, 0] = 0
    else:
        for i, bit in enumerate(bits[::-1]):
            if bit == '1':
                if i == 0:
                    grid[0, B-1] = 1
                    continue
                if i == 1 and bits[-1] == '0':
                        grid[0, B-1] = 1
                        grid[0, B-2] = 1
                        continue
                grid[0, B-1-1-i] = 1
    sys.stdout.write('POSSIBLE\n')
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            sys.stdout.write('%d' % grid[i, j])
        sys.stdout.write('\n')

            
            
        


