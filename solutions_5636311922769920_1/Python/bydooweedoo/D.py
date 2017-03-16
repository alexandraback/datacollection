import sys

def getLines():
    return [line.rstrip('\n') for line in sys.stdin]

def nextSequence(base, current):
    result = ''
    repeatedG = 'G' * len(current)
    for char in base:
        result += current if char == 'L' else repeatedG
    return result

def computeSequence(sequence, C):
    result = sequence
    for index in range(1, C):
        result = nextSequence(sequence, result)
    return result

assert(computeSequence('LGL', 2) == 'LGLGGGLGL')
assert(computeSequence('LGL', 3) == 'LGLGGGLGLGGGGGGGGGLGLGGGLGL')
assert(computeSequence('GGG', 2) == 'GGGGGGGGG')
assert(computeSequence('GGL', 2) == 'GGGGGGGGL')
assert(computeSequence('GLG', 2) == 'GGGGLGGGG')
assert(computeSequence('GLL', 2) == 'GGGGLLGLL')
assert(computeSequence('LGG', 2) == 'LGGGGGGGG')
assert(computeSequence('LGL', 2) == 'LGLGGGLGL')
assert(computeSequence('LLG', 2) == 'LLGLLGGGG')
assert(computeSequence('LLL', 2) == 'LLLLLLLLL')

def solve(K, C, S):
    if S == K:
        return ' '.join([str(index + 1) for index in range(0, K)])
    elif C > 1 and S >= (K - 1):
        return ' '.join([str(index + 1) for index in range(1, K)])
    return 'IMPOSSIBLE'

lines = getLines()
nbCases = int(lines.pop(0))

for case in range(0, nbCases):
    K, C, S = map(int, lines.pop(0).split(' '))
    answer = solve(K, C, S)
    print("Case #", (case + 1), ": ", answer, sep="")
