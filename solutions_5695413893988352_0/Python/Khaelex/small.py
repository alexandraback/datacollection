import sys

def all_possible(s):
    acc = []
    for i in range(len(s)):
        if s[i] == '?':
            start = s[:i]
            end = s[i+1:]
            nxt = all_possible(end)
            for digit in range(10):
                for n in nxt:
                    acc.append(start + str(digit) + n)
            return acc
    return [s]

def solve(c, j):
    least_value = 999999999
    least = []
    cs = [int(s1) for s1 in all_possible(c)]
    js = [int(s2) for s2 in all_possible(j)]
    for ci in cs:
        for ji in js:
            diff = abs(ci - ji)
            if diff < least_value:
                least_value = diff
                least = [(ci, ji)]
            elif diff == least_value:
                least.append((ci, ji))
    least = sorted(least)
    ce = str(least[0][0])
    ce = '0' * (len(c) - len(ce)) + ce
    je = str(least[0][1])
    je = '0' * (len(j) - len(je)) + je
    return ' '.join((ce, je))

next(sys.stdin)
case = 0
for line in sys.stdin:
    line = line.strip()
    case += 1
    c, j = line.split(' ')
    print('Case #{}: {}'.format(case, solve(c, j)))
