T = input()
s = []
n = 0

def inv(x):
    if x == '1':
        return '0'
    if x == '0':
        return '1'
    if x == 'i':
        return 'I'
    if x == 'I':
        return 'i'
    if x == 'j':
        return 'J'
    if x == 'J':
        return 'j'
    if x == 'k':
        return 'K'
    if x == 'K':
        return 'k'

def mul(x, y):
    if x == '1':
        return y
    if y == '1':
        return x
    if x == '0':
        return inv(y)
    if y == '0':
        return inv(x)
    if x == y:
        return '0'
    if inv(x) == y:
        return '1'
    c = 0
    if x == 'I' or x == 'J' or x == 'K':
        c += 1
        x = inv(x)
    if y == 'I' or y == 'J' or y == 'K':
        c += 1
        y = inv(y)
    if x > y:
        c += 1
        x, y = y, x
    if x == 'i' and y == 'j':
        return 'k' if c % 2 == 0 else 'K'
    if x == 'i' and y == 'k':
        return 'J' if c % 2 == 0 else 'j'
    if x == 'j' and y == 'k':
        return 'i' if c % 2 == 0 else 'I'

def calc(l, r):
    if r - l == 1:
        return s[l]
    elif l == r:
        return '1'
    else:
        return mul(calc(l, (l + r) / 2), calc((l + r) / 2, r))

for t in range(T):
    l = raw_input().split(' ')
    n = int(l[0])
    m = int(l[1])
    s = raw_input()
    s = s * m
    n *= m
    flag = 0
    l = [0] * (n + 1)
    r = [0] * (n + 1)
    x = -1
    y = -1
    c = '1'
    for i in range(n + 1):
        l[i] = c
        if i < n:
            c = mul(c, s[i])
    for i in range(n + 1):
        r[i] = c
        if i < n:
            c = mul(inv(s[i]), c)
        if x == -1 and l[i] == 'i' and r[i] == 'i':
            x = i
        if r[i] == 'k':
            y = i
    '''
    for i in range(n + 1):
        if calc(0, i) == 'i':
            for j in range(i, n + 1):
                if calc(i, j) == 'j' and calc(j, n) == 'k':
                    flag = 1
                    break
            if flag == 1:
                break
        if flag == 1:
            break
    '''
    print 'Case #%d: %s' % (t + 1, 'YES' if x < y and x != -1 and y != -1 else 'NO')
