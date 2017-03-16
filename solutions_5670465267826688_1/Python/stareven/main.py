Q_MAP = {
    ('1', '1'): (1, '1'),
    ('1', 'i'): (1, 'i'),
    ('1', 'j'): (1, 'j'),
    ('1', 'k'): (1, 'k'),
    ('i', '1'): (1, 'i'),
    ('i', 'i'): (-1, '1'),
    ('i', 'j'): (1, 'k'),
    ('i', 'k'): (-1, 'j'),
    ('j', '1'): (1, 'j'),
    ('j', 'i'): (-1, 'k'),
    ('j', 'j'): (-1, '1'),
    ('j', 'k'): (1, 'i'),
    ('k', '1'): (1, 'k'),
    ('k', 'i'): (1, 'j'),
    ('k', 'j'): (-1, 'i'),
    ('k', 'k'): (-1, '1'),
}

def mult(sign, x, y):
    ns, res = Q_MAP[(x, y)]
    sign *= ns
    return sign, res

def ReadIn():
    t = int(input())
    for c in range(1, t + 1):
        n, m = [int(x) for x in input().split()]
        s = input().strip()
        yield c, s, m

def WalkFor(found, s, offset):
    sign, res = 1, '1'
    for i in range(offset, len(s)):
        sign, res = mult(sign, res, s[i])
        if (sign, res) == found:
            return i + 1
    return -1

def Solve(s, m):
    sign, res = 1, '1'
    for x in s:
        sign, res = mult(sign, res, x)
    # print(sign, res)
    if m % 2 == 1:
        if res != '1': return 'NO'
        if sign != -1: return 'NO'
    else:
        if res == '1': return 'NO'
        if m % 4 == 0: return 'NO'
    es = s * min(m, 8)
    # print(es)
    offset = WalkFor((1, 'i'), es, 0)
    # print(offset)
    if offset == -1: return 'NO'
    offset = WalkFor((1, 'j'), es, offset)
    # print(offset)
    if offset == -1: return 'NO'
    return 'YES'

if __name__ == '__main__':
    for c, s, m in ReadIn():
        print('Case #%d: %s' % (c, Solve(s, m)))