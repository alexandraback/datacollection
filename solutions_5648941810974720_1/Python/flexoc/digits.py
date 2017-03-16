from collections import Counter
digits = ['ZERO', 'ONE', 'TWO', 'THREE', 'FOUR', 'FIVE', 'SIX', 'SEVEN', 'EIGHT', 'NINE']

T = int(input())
for t in range(T):
    s = input()
    c = Counter(s)
    dig = [0 for i in range(10)]
    dig[0] = c['Z']
    for x in digits[0]: c[x] -= dig[0]
    dig[2] = c['W']
    for x in digits[2]: c[x] -= dig[2]
    dig[6] = c['X']
    for x in digits[6]: c[x] -= dig[6]
    dig[8] = c['G']
    for x in digits[8]: c[x] -= dig[8]
    dig[4] = c['U']
    for x in digits[4]: c[x] -= dig[4]
    dig[7] = c['S']
    for x in digits[7]: c[x] -= dig[7]
    dig[5] = c['V']
    for x in digits[5]: c[x] -= dig[5]
    dig[9] = c['I']
    for x in digits[9]: c[x] -= dig[9]
    dig[1] = c['N']
    for x in digits[1]: c[x] -= dig[1]
    dig[3] = c['R']
    for x in digits[3]: c[x] -= dig[3]

    print("Case #%d: %s" % (t+1, "".join(str(i) * dig[i] for i in range(10))))


