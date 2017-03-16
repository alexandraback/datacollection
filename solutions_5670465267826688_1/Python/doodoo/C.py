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

def mult(a, b):
    if a[0] == -1:
        val = mult((1, a[1]), b)
        return (-val[0], val[1])

    if b[0] == -1:
        val = mult(a, (1, b[1]))
        return (-val[0], val[1])

    return MUL[a[1]][b[1]]

def s_find(st, start, end, val):
    cur = (1, '1')

    rep = set()

    for i in xrange(start, end):
        if i % len(st) == 0:
            if cur in rep:
                return False
            rep.add(cur)

        cur = mult(cur, (1, st[i % len(st)]))
        if cur == val:
            return i + 1
    return -1

def pow_q(num, N):
    if N == 0:
        return (1, '1')
    if N == 1:
        return num

    val = pow_q(num, N / 2)

    ret = mult(val, val)
    if N % 2 == 1:
        ret = mult(ret, num)
    return ret

def mult_arr(st):
    cur = (1, '1')
    for c in st:
        cur = mult(cur, (1, c))
    return cur

def s_pow(st, N):
    M = mult_arr(st)
    return pow_q(M, N)

def solve(st, end):
    iidx = s_find(st, 0, end, (1, 'i'))
    if iidx == -1:
        return False

    jidx = s_find(st, iidx, end, (1, 'j'))
    if jidx == -1:
        return False

    cur = (1, '1')
    kp = -1
    for i in xrange(jidx, end):
        if i % len(st) == 0:
            kp = i
            break
        cur = mult(cur, (1, st[i % len(st)]))

    if kp > 0:
        assert (end - kp) % len(st) == 0
        p = s_pow(st, (end - kp) / len(st))
        cur = mult(cur, p)

    if cur != (1, 'k'):
        return False

    return True

T = int(raw_input())

for i in xrange(T):
    L, X = [int(x) for x in raw_input().split()]

    st = raw_input()

    ans = solve(st, L*X)
    if ans:
        print 'Case #%d: %s' % (i + 1, 'YES')
    else:
        print 'Case #%d: %s' % (i + 1, 'NO')
