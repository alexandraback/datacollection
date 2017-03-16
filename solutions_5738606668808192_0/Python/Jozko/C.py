import sys
import numpy as np

def findDivs(vals):
    divs = []
    for val in vals[2:]:
        found = False
        for div in xrange(2, int(np.sqrt(val)+1)):
            if val % div == 0:
                divs.append(div)
                found = True
                break
        if not found:
            return []
    return divs

T = int(sys.stdin.readline())
for case in range(1, T+1):
    sys.stdout.write("Case #%d:\n" % case)
    N, J = sys.stdin.readline().split()
    N, J = int(N), int(J)
    powers = [[1] for _ in range(11)]
    found = []
    current = [1] + [0] * (N-2) + [1]
    for i in range(2, 11):
        for j in range(N-1):
            powers[i].append(powers[i][j]*i)
    vals = map(lambda xs: xs[0] + xs[-1], powers)
    while len(found) != J:
        divs = findDivs(vals)
        if len(divs) == 9 and current not in found:
            print ''.join(map(str, reversed(current))), ' '.join(map(str,divs))
            found.append(current[:])
            sys.stderr.write("%d\n" % len(found))
        posToChange = np.random.randint(N-2) + 1
        sign = 1 - 2*current[posToChange]
        current[posToChange] = 1 - current[posToChange]
        for i in range(2, len(vals)):
            vals[i] += sign*powers[i][posToChange]
            
