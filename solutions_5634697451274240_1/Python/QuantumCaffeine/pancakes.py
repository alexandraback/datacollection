# Solution to "Revenge of the Pancakes" for Google Code Jam 2016
# by Peter Mattsson (quantum.caffeine@gmail.com)
import sys

def cases(inputFile):
    with open(inputFile, 'r') as f:
        numCases = int(f.readline())
        for _ in range(numCases):
            yield f.readline().rstrip('\n')

def flip(target):
    return '-' if target == '+' else '+'

def solve(stack, pos, target):
    while pos >= 0 and stack[pos] == target:
        pos -= 1
    if pos < 0: return 0
    return solve(stack, pos, flip(target)) + 1

with open(sys.argv[2], 'w') as f:
    for num, stack in enumerate(cases(sys.argv[1])):
        f.write("Case #%d: %d\n"%(num+1, solve(stack, len(stack)-1, '+')))
