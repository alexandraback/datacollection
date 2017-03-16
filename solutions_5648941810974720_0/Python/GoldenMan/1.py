def delt(s, t):
    for i in t:
        s[i] -= 1

t = int(raw_input())

for case in range(t):
    print 'Case #' + str(case + 1) + ':',
    s = raw_input()

    counts = {}
    dig = 10 * [0]

    counts['Z'] = 0
    counts['X'] = 0
    counts['G'] = 0
    counts['W'] = 0
    counts['U'] = 0
    counts['R'] = 0
    counts['F'] = 0
    counts['V'] = 0
    counts['I'] = 0
    counts['N'] = 0

    for i in s:
        if not (i in counts):
            counts[i] = 0;
        counts[i] += 1

    while (counts['Z'] > 0):
        delt(counts, 'ZERO')
        dig[0] += 1


    while (counts['X'] > 0):
        delt(counts, 'SIX')
        dig[6] += 1


    while (counts['G'] > 0):
        delt(counts, 'EIGHT')
        dig[8] += 1


    while (counts['W'] > 0):
        delt(counts, 'TWO')
        dig[2] += 1


    while (counts['U'] > 0):
        delt(counts, 'FOUR')
        dig[4] += 1


    while (counts['R'] > 0):
        delt(counts, 'THREE')
        dig[3] += 1


    while (counts['F'] > 0):
        delt(counts, 'FIVE')
        dig[5] += 1


    while (counts['V'] > 0):
        delt(counts, 'SEVEN')
        dig[7] += 1


    while (counts['I'] > 0):
        delt(counts, 'NINE')
        dig[9] += 1


    while (counts['N'] > 0):
        delt(counts, 'ONE')
        dig[1] += 1


    ans = ""
    for i in range(10):
        for j in range(dig[i]):
            ans += str(i)

    print ans
