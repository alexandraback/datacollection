from collections import defaultdict

T = int(raw_input())

for t in range(T):
    S = raw_input()
    counts = defaultdict(int)
    for c in S:
        counts[c] += 1
    digits = defaultdict(int)
    while counts['Z']:
        digits[0] += 1
        for c in 'ZERO':
            counts[c] -= 1
    while counts['X']:
        digits[6] += 1
        for c in 'SIX':
            counts[c] -= 1
    while counts['S']:
        digits[7] += 1
        for c in 'SEVEN':
            counts[c] -= 1
    while counts['G']:
        digits[8] += 1
        for c in 'EIGHT':
            counts[c] -= 1
    while counts['V']:
        digits[5] += 1
        for c in 'FIVE':
            counts[c] -= 1
    while counts['U']:
        digits[4] += 1
        for c in 'FOUR':
            counts[c] -= 1
    while counts['R']:
        digits[3] += 1
        for c in 'THREE':
            counts[c] -= 1
    while counts['W']:
        digits[2] += 1
        for c in 'TWO':
            counts[c] -= 1
    while counts['O']:
        digits[1] += 1
        for c in 'ONE':
            counts[c] -= 1
    while counts['E']:
        digits[9] += 1
        for c in 'NINE':
            counts[c] -= 1
    S = ''.join(str(k) * digits[k] for k in range(0, 10))
    print "Case #%d:" % (t + 1), S
    s = 0
