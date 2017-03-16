import string
T = int(raw_input())
for C in xrange(1, T+1):
    a = list(raw_input())
    d = {}
    for c in string.uppercase: d[c] = 0
    no = [0]*10
    ans = ""
    for c in a: d[c] += 1
    no[6] = d['X']
    for c in 'SIX': d[c] -= no[6]
    no[0] = d['Z']
    for c in 'ZERO': d[c] -= no[0]
    no[8] = d['G']
    for c in 'EIGHT': d[c] -= no[8]
    no[4] = d['U']
    for c in 'FOUR': d[c] -= no[4]
    no[5] = d['F']
    for c in 'FIVE': d[c] -= no[5]
    no[7] = d['V']
    for c in 'SEVEN': d[c] -= no[7]
    no[2] = d['W']
    for c in 'TWO': d[c] -= no[2]
    no[3] = d['H']
    for c in 'THREE': d[c] -= no[3]
    no[1] = d['O']
    for c in 'ONE': d[c] -= no[1]
    no[9] = d['I']
    for c in 'NINE': d[c] -= no[9]
    assert all(d[x] == 0 for x in string.uppercase)
    ans = ''.join(chr(x + ord('0'))*no[x] for x in xrange(10))
    print "Case #%d: %s" % (C, ans)
