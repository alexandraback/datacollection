import sys
from collections import defaultdict

digits = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

d_freq = {}
for digit in range(len(digits)):
    d_freq[digit] = defaultdict(int)
    for c in digits[digit]:
        d_freq[digit][c] += 1

def done(freq):
    return sum(freq.values()) == 0

def back(d, start):
    if done(d):
        return defaultdict(int)
    for digit in (7, 5, 9, 1, 3):
        if digit in (0, 6, 8):
            continue
        good = True
        for c, f in d_freq[digit].items():
            if d[c] < f:
                good = False
                break
        if not good:
            continue

        for c, f in d_freq[digit].items():
            d[c] -= f
        sol = back(d, digit)
        if sol is not None:
            sol[digit] += 1
            return sol
        for c, f in d_freq[digit].items():
            d[c] += f
    return None

def solve(s):
    d = defaultdict(int)

    z = 0
    x = 0
    g = 0
    w = 0
    u = 0
    for c in s:
        if c == 'Z':
            z += 1
        if c == 'G':
            g += 1
        if c == 'X':
            x += 1
        if c == 'W':
            w += 1
        if c == 'U':
            u += 1

        d[c] += 1

    for c in digits[0]:
        d[c] -= z
    for c in digits[6]:
        d[c] -= x
    for c in digits[8]:
        d[c] -= g
    for c in digits[2]:
        d[c] -= w
    for c in digits[4]:
        d[c] -= u
    sol = back(d, 1)
    sol[0] += z
    sol[6] += x
    sol[8] += g
    sol[4] += u
    sol[2] += w
    phone = ''
    for i in range(10):
        phone += str(i) * sol[i]
    return phone

next(sys.stdin)
case = 0
for line in sys.stdin:
    line = line.strip()
    case += 1
    print('Case #{}: {}'.format(case, solve(line)))
