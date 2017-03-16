# Solution to "Fractiles" for Google Code Jam 2016
# by Peter Mattsson (quantum.caffeine@gmail.com)
import sys

def cases(inputFile):
    with open(inputFile, 'r') as f:
        numCases = int(f.readline())
        for _ in range(numCases):
            yield [int(x) for x in f.readline().split()]

def findTarget(start, end, k, c):
    target = start
    for pos in range(start+1, end+1):
        target = (target-1)*k + pos
    residual = c - (end - start + 1)
    for pos in range(residual):
        target = (target-1)*k + 1
    return target

def solve(k, c, s):
    required = k/c + (k%c != 0)
    if required > s:
        return 'IMPOSSIBLE'
    results = []
    for pos in range(1, k+1, c):
        results.append(findTarget(pos, min(pos+c-1, k), k, c))
    return ' '.join(str(x) for x in results)


with open(sys.argv[2], 'w') as f:
    for num, args in enumerate(cases(sys.argv[1])):
        f.write("Case #%d: %s\n"%(num+1, solve(*args)))
