def moo(a, b):
    sgn = a[0] * b[0]
    if a[1] == '1': val = b[1]
    elif b[1] == '1': val = a[1]
    elif a[1] == b[1]:
        val = '1'
        sgn *= -1
    elif a[1] != 'k' and b[1] != 'k':
        val = 'k'
        if a[1] == 'j': sgn *= -1
    elif a[1] != 'i' and b[1] != 'i':
        val = 'i'
        if a[1] == 'k': sgn *= -1
    elif a[1] != 'j' and b[1] != 'j':
        val = 'j'
        if a[1] == 'i': sgn *= -1
    return (sgn, val)

def pwr(x, p):
    if p == 0:
        return (1, 1)
    elif p == 1:
        return x
    elif p % 2 == 0:
        v = pwr(x, p / 2)
        return moo(v, v)
    return moo(pwr(x, p - 1), x)

for t in range(int(raw_input())):
    a, b = [int(x) for x in raw_input().split()]
    s = raw_input()

    can = False
    one = (1, '1')
    for l in s:
        one = moo(one, (1, l))

    total = pwr(one, b)
    if total == (-1, '1'):
        l = -1
        r = -1
        pre = (1, '1')
        post = (1, '1')
        for i in range(4 * len(s)):
            pre = moo(pre, (1, s[i % len(s)]))
            if pre == (1, 'i'):
                l = i
                break
        for j in range(4 * len(s)):
            post = moo((1, s[(len(s) * 4 - j - 1) % len(s)]), post)
            if post == (1, 'k'):
                r = j
                break
        if l != -1 and r != -1 and l < len(s) * b - j:
            can = True


    print "Case #%d: %s" % (t + 1, "YES" if can else "NO")

