from fractions import Fraction

def commprefix(s1, s2):
    for i in xrange(min(len(s1), len(s2))):
        if s1[i] != s2[i]:
            return False
    return True

def count(c, s):
    t = 0
    for ch in s:
        if c == ch:
            t += 1
    return t

def countsubs(s1, s2):
    t = 0
    for i in xrange(len(s2)):
        if s1 == s2[i:i + len(s1)]:
            t += 1
    return t


def solve(case):
    s, keys, target = case
    if len(target) > s:
        return 0.0
    if not set(list(target)).issubset(set(list(keys))):
        return 0.0
    #otherwise sensible
    # count expected number of bananas
    ways = 1
    for c in target:
        ways *= count(c, keys)
    expected = (s - len(target)  + 1) * Fraction(ways, len(keys) ** len(target))
    # count max number of bananas
    ms = target
    while len(ms) < s:
        for i in xrange(len(ms)):
            if len(ms[i:]) < len(target) and commprefix(ms[i:], target):
                ms += target[-(len(target) - len(ms[i:])):]
                break
        ms += target
    ms = ms[:s]
    print ms
    maxbananas = countsubs(target, ms)
    print maxbananas
    ans = maxbananas - expected
    return "%.7f" % ans

f = open('b.in', 'r')
lines = f.readlines()

cases = []
for i in xrange(int(lines[0])):
    cases.append([map(int, list(lines[3*i + 1].split()))[2], lines[3*i+2].strip(), lines[3*i+3].strip()])
print cases

g = open('b.out','w')
for i in xrange(len(cases)):
    g.write('Case #' + str(i + 1) + ': ' + str(solve(cases[i])) + '\n')
g.close()
