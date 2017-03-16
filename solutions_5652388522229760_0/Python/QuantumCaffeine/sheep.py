# Solution to "Counting Sheep" for Google Code Jam 2016
# by Peter Mattsson (quantum.caffeine@gmail.com)
import sys

def cases(inputFile):
    with open(inputFile, 'r') as f:
        numCases = int(f.readline())
        for _ in range(numCases):
            yield int(f.readline())

def solve(n):
    if n == 0:
        return "INSOMNIA"
    digits, m = set(), 0
    while len(digits) < 10:
        m += n
        digits.update(str(m))
    return str(m)

with open(sys.argv[2], 'w') as f:
    for num, n in enumerate(cases(sys.argv[1])):
        f.write("Case #%d: %s\n"%(num+1, solve(n)))
