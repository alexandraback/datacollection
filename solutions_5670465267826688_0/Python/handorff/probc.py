MUL = {}
MUL['1'] = {'1': '1', 'i': 'i', 'j': 'j', 'k': 'k'}
MUL['i'] = {'1': 'i', 'i': '-1', 'j': 'k', 'k': '-j'}
MUL['j'] = {'1': 'j', 'i': '-k', 'j': '-1', 'k': 'i'}
MUL['k'] = {'1': 'k', 'i': 'j', 'j': '-i', 'k': '-1'}

def mul(x, y):
    negs = 0
    if x[0] == '-':
        negs += 1
        x = x[1:]
    if y[0] == '-':
        negs += 1
        y = y[1:]
    m = MUL[x][y]
    if m[0] == '-':
        negs += 1
        m = m[1:]
    if negs % 2 == 0:
        return m
    else:
        return '-' + m

def solve(l, x, s):
    s = s * x
    acc = '1'
    target = 'i'
    ret = False
    for i in xrange(l * x):
        acc = mul(acc, s[i])
        if acc == target:
            if target == 'i':
                target = 'k'
            elif target == 'k':
                target = None
                ret = True

    return 'YES' if (ret and acc == '-1') else 'NO'


t = int(raw_input())
test_cases = []

for i in xrange(t):
    l, x = map(int, raw_input().split(' '))
    s = raw_input()
    test_cases.append((l, x, s))

for i in xrange(t):
    l, x, s = test_cases[i]
    print 'Case #%d: %s' % (i + 1, solve(l, x, s))
