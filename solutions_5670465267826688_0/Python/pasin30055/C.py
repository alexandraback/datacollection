MAP = {'1':1, 'i': 2, 'j': 3, 'k': 4}
REV = ['1', 'i', 'j', 'k']
MULT = [
    [1, 2, 3, 4],
    [2, -1, 4, -3],
    [3, -4, -1, 2],
    [4, 3, -2, -1],
]

def mult(a, b):
    s = False
    if a[0] == '-':
        s ^= True
    if b[0] == '-':
        s ^= True
    aa = MAP[a[-1]] - 1
    bb = MAP[b[-1]] - 1
    cc = MULT[aa][bb]
    if s:
        cc *= -1
    ret = REV[abs(cc) - 1]
    if cc < 0:
        ret = '-' + ret
    return ret

for test in xrange(int(raw_input().strip())):
    l, x = map(int, raw_input().strip().split())
    s = raw_input() * x
    a = '1'
    g = 0
    for c in s:
        if g == 0 and a == 'i':
            g += 1
            a = '1'
        if g == 1 and a == 'j':
            g += 1
            a = '1'
        a = mult(a, c)
    ans = 'NO'
    if g == 2 and a == 'k':
        ans = 'YES'
    print "Case #%d: %s" % (test + 1, ans)
