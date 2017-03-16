from collections import defaultdict

f = open('A-large.in', 'r')
o = open('A.out', 'w')

# 0 2 8 6
def find(s):
    d = defaultdict(int)
    for c in s:
        d[c] += 1
    r = [0 for _ in range(10)]
    # ZERO
    r[0] = d['Z']
    d['Z'] = 0
    d['E'] -= r[0]
    d['R'] -= r[0]
    d['O'] -= r[0]
    # TWO
    r[2] = d['W']
    d['T'] -= r[2]
    d['W'] = 0
    d['O'] -= r[2]
    # EIGHT
    r[8] = d['G']
    d['E'] -= r[8]
    d['I'] -= r[8]
    d['G'] = 0
    d['H'] -= r[8]
    d['T'] -= r[8]
    # SIX
    r[6] = d['X']
    d['S'] -= r[6]
    d['I'] -= r[6]
    d['X'] = 0
    # THREE
    r[3] = d['H']
    d['T'] -= r[3]
    d['H'] = 0
    d['R'] -= r[3]
    d['E'] -= 2 * r[3]
    # FOUR
    r[4] = d['U']
    d['F'] -= r[4]
    d['O'] -= r[4]
    d['U'] = 0
    d['R'] -= r[4]
    # ONE
    r[1] = d['O']
    d['O'] = 0
    d['N'] -= r[1]
    d['E'] -= r[1]
    # FIVE
    r[5] = d['F']
    d['F'] = 0
    d['I'] -= r[5]
    d['V'] -= r[5]
    d['E'] -= r[5]
    # SEVEN
    r[7] = d['S']
    d['S'] = 0
    d['E'] -= 2 * r[7]
    d['V'] -= r[7]
    d['N'] -= r[7]
    # NINE
    r[9] = d['E']
    d['N'] -= 2 * r[9]
    d['I'] -= r[9]
    d['E'] = 0
    assert sum(d.values()) == 0, d
    s = ''
    for i, n in enumerate(r):
        s += str(i) * n
    return s

m = int(f.readline().strip())
i = 1

while i <= m:
    s = next(f).strip()
    print('Case #{0}: {1}'.format(i, find(s)), file = o)
    i += 1

f.close()
o.close()
