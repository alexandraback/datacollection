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

def check(l, x, s):
    acc = '1'
    for i in xrange(l):
        acc = mul(acc, s[i])
    if acc == '1':
        return False
    elif acc == '-1':
        return (x % 2 == 1)
    elif acc in ['i', 'j', 'k', '-i', '-j', '-k']:
        return (x % 4 == 2)
    else:
        assert 0, 'You messed up'

def fastsolve(l, x, s):
    new_s = s * 8
    acc = '1'
    target = 'i'
    ret = False
    for i in xrange(l * 8):
        acc = mul(acc, new_s[i])
        if acc == target:
            if target == 'i':
                target = 'k'
            elif target == 'k':
                target = None
                ret = True

    return 'YES' if (ret and check(l, x, s)) else 'NO'

t = int(raw_input())
test_cases = []

for i in xrange(t):
    l, x = map(int, raw_input().split(' '))
    s = raw_input()
    test_cases.append((l, x, s))

for i in xrange(t):
    l, x, s = test_cases[i]
    if x < 8:
        solution = solve(l, x, s)
    else:
        solution = fastsolve(l, x, s)
    print 'Case #%d: %s' % (i + 1, solution)
