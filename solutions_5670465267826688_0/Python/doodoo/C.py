MUL = {
    '1': {'1': (1, '1'),
          'i': (1, 'i'),
          'j': (1, 'j'),
          'k': (1, 'k')},
    'i': {'1': (1, 'i'),
          'i': (-1, '1'),
          'j': (1, 'k'),
          'k': (-1, 'j')},
    'j': {'1': (1, 'j'),
          'i': (-1, 'k'),
          'j': (-1, '1'),
          'k': (1, 'i')},
    'k': {'1': (1, 'k'),
          'i': (1, 'j'),
          'j': (-1, 'i'),
          'k': (-1, '1')},
    }

def multi(a, b):
    if a[0] == -1:
        val = multi((1, a[1]), b)
        return (-val[0], val[1])

    if b[0] == -1:
        val = multi(a, (1, b[1]))
        return (-val[0], val[1])

    return MUL[a[1]][b[1]]

def solve(st):
    cur = (1, '1')

    iidx = -1
    for i in xrange(len(st)):
        cur = multi(cur, (1, st[i]))
        if cur == (1, 'i'):
            iidx = i
            break
    if iidx == -1:
        return False

    cur = (1, '1')
    jidx = -1
    for i in xrange(iidx + 1, len(st)):
        cur = multi(cur, (1, st[i]))
        if cur == (1, 'j'):
            jidx = i
            break
    if jidx == -1:
        return False

    cur = (1, '1')
    for i in xrange(jidx + 1, len(st)):
        cur = multi(cur, (1, st[i]))

    if cur != (1, 'k'):
        return False

    return True

T = int(raw_input())

for i in xrange(T):
    L, X = [int(x) for x in raw_input().split()]

    s = raw_input()
    st = s * X

    ans = solve(st)
    if ans:
        print 'Case #%d: %s' % (i + 1, 'YES')
    else:
        print 'Case #%d: %s' % (i + 1, 'NO')
