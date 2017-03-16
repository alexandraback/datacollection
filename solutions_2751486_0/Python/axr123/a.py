import sys

vowels = 'aeiou'

def concons(str):
    maxN = 0
    n = 0
    for l in str:
        if l in vowels:
            if n > maxN: maxN = n
            n = 0
        else:
            n += 1
    if n > maxN: maxN = n
    return maxN

def solve(name, n):
    count = 0
    for s in range(len(name)):
        for e in range(s+1, len(name)+1):
            if concons(name[s:e]) >= n: count += 1
    return count

numcases = int(sys.stdin.readline())
for c in range(numcases):
    name, n = sys.stdin.readline().split()
    print("Case #%d: %d" % (c+1, solve(name, int(n))))
