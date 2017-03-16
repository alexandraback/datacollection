from collections import Counter

numbers = {}
numbers[0] = 'ZERO'
numbers[1] = 'ONE'
numbers[2] = 'TWO'
numbers[3] = 'THREE'
numbers[4] = 'FOUR'
numbers[5] = 'FIVE'
numbers[6] = 'SIX'
numbers[7] = 'SEVEN'
numbers[8] = 'EIGHT'
numbers[9] = 'NINE'

patterns = {}
patterns[5] = {'F': 1, 'I': 1, 'V': 1, 'E': 1}
patterns[7] = {'S': 1, 'E': 2, 'V': 1, 'N': 1}
patterns[3] = {'T': 1, 'H': 1, 'R': 1, 'E': 2}
patterns[9] = {'N': 2, 'I': 1, 'E': 1}
patterns[1] = {'O': 1, 'N': 1, 'E': 1}

def recalculate(c, n, f):
    for ch in numbers[n]:
        c[ch] -= f
        if c[ch] == 0:
            c.pop(ch, None)

    return c

def getSol(ip):
    c = Counter(ip)
    sol = []

    for (n, letter) in [(0, 'Z'), (2, 'W'), (4, 'U'), (6, 'X'), (8, 'G')]:
        f = c.get(letter, False)
        if f:
            sol.extend([n] * f)
            c = recalculate(c, n, f)

    c_old = dict.copy(c)
    while c:
        for (n, pattern) in [(5, patterns[5]), (7, patterns[7]), (3, patterns[3]), (9, patterns[9]), (1, patterns[1])]:
            for letter in pattern.iterkeys():
                if c.get(letter, 0) < pattern[letter]:
                    break
            else:
                sol.append(n)
                c = recalculate(c, n, 1)

            if c_old != c:
                c_old = dict.copy(c)
                break

    return sol

T = int(raw_input())

for t in xrange(1, T+1):
    ip = raw_input()
    sol = getSol(ip)
    print 'Case #%d: %s' % (t, ''.join(map(str, sorted(sol))))


# Z - 0
# N - 1, 7, 9
# W - 2
# H - 3, 8
# F - 4, 5
# X - 6
# V - 7
# G - 8