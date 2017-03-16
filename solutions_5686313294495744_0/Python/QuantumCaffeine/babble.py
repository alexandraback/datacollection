# Solution to "Technobabble" for Google Code Jam 2016
# by Peter Mattsson (quantum.caffeine@gmail.com)
import sys
from collections import defaultdict

def cases(inputFile):
    with open(inputFile, 'r') as f:
        numCases = int(f.readline())
        for _ in range(numCases):
            numTopics = int(f.readline())
            yield [f.readline().rstrip('\n').split(' ') for x in xrange(numTopics)]

best = 0

def innerSolve(first, pos, pairs, used):
    global best
    if pos >= len(first):
        current = len(set(used))
        if current > best:
            best = current
        return
    word = first[pos]
    for second in pairs[word]:
        innerSolve(first, pos+1, pairs, used + [second])

def solve(topics):
    global best
    best = 0
    pairs = defaultdict(list)
    first = set()
    second = set()
    for a, b in topics:
        pairs[a].append(b)
        first.add(a)
        second.add(b)
    innerSolve(list(first), 0, pairs, [])
    valid = len(first) + len(second) - best
    return len(topics) - valid

with open(sys.argv[2], 'w') as f:
    for num, topics in enumerate(cases(sys.argv[1])):
        f.write("Case #%d: %d\n"%(num+1, solve(topics)))
