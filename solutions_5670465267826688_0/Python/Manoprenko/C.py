def mul(a, b):
    res = ''
    if a[0] == '-' and b[0] != '-' or a[0] != '-' and b[0] == '-':
        res = '-'
    a1 = a[-1]
    b1 = b[-1]
    an = ['1', 'i', 'j', 'k'].index(a1)
    bn = ['1', 'i', 'j', 'k'].index(b1)
    res1 = [
        ['1', 'i', 'j', 'k'],
        ['i', '-1', 'k', '-j'],
        ['j', '-k', '-1', 'i'],
        ['k', 'j', '-i', '-1']
    ][an][bn]
    if res == '-' and res1[0] == '-':
        res1 = res1[-1]
    elif res == '-':
        res1 = '-' + res1
    return res1

fin = open("c.in", "r")
fout = open("c.txt", "w")

t = int(fin.readline())
for ii in range(t):
    L, x = map(int, fin.readline().split())
    s = fin.readline().rstrip()
    s = s * x
    i = 0
    cur_mul = '1'
    while i < len(s) and cur_mul != 'i':
        cur_mul = mul(cur_mul, s[i])
        i += 1
    if cur_mul != 'i':
        print('Case #%d: NO' % (ii + 1), file=fout)
        continue
    cur_mul = '1'

    while i < len(s) and cur_mul != 'j':
        cur_mul = mul(cur_mul, s[i])
        i += 1
    if cur_mul != 'j':
        print('Case #%d: NO' % (ii + 1), file=fout)
        continue

    cur_mul = '1'
    while i < len(s):
        cur_mul = mul(cur_mul, s[i])
        i += 1
    if cur_mul != 'k':
        print('Case #%d: NO' % (ii + 1), file=fout)
    else:
        print('Case #%d: YES' % (ii + 1), file=fout)

fin.close()
fout.close()