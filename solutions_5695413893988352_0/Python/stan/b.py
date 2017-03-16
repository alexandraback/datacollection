import sys

nt = int(sys.stdin.readline())

def fits(n, pat):
    n = pretty(len(pat), n)
    if len(n) > pat:
        return False
    for i, j in zip(n, pat):
        if i != j and j != '?':
            return False
    return True

def is_better(cc, cj, ansc, ansj):
    if ansc == -1:
        return True
    if abs(cc - cj) < abs(ansc - ansj):
        return True
    if abs(cc - cj) > abs(ansc - ansj):
        return False
    if cc < ansc:
        return True
    if cc > ansc:
        return False
    return cj < ansj

def pretty(n, x):
    x = str(x)
    while len(x) < n:
        x = '0' + x
    return x

for t in xrange(1, nt + 1):
    c, j = sys.stdin.readline().strip().split()
    ansc, ansj = -1, -1
    sign = 0

    def update(cc, cj):
        global ansc, ansj
        if is_better(int(cc), int(cj), ansc, ansj):
            ansc, ansj = int(cc), int(cj)
    def complete(i, sign, cc, cj):
        if i == len(c):
            update(cc, cj)
            return
        if c[i] == '?':
            if j[i] == '?':
                if sign < 0:
                    cc += '9'
                    cj += '0'
                elif sign > 0:
                    cc += '0'
                    cj += '9'
                else:
                    complete(i + 1, -1, cc + '0', cj + '1')
                    complete(i + 1, 1, cc + '1', cj + '0')
                    cc += '0'
                    cj += '0'
            else:
                if sign == 0:
                    if j[i] > '0':
                        complete(i + 1, -1, cc + chr(ord(j[i]) - 1), cj + j[i])
                    if j[i] < '9':
                        complete(i + 1, 1, cc + chr(ord(j[i]) + 1), cj + j[i])
                    cc += j[i]
                elif sign < 0:
                    cc += '9'
                else:
                    cc += '0'
                cj += j[i]
        else:
            if j[i] == '?':
                if sign == 0:
                    if c[i] > '0':
                        complete(i + 1, 1, cc + c[i], cj + chr(ord(c[i]) - 1))
                    if c[i] < '9':
                        complete(i + 1, -1, cc + c[i], cj + chr(ord(c[i]) + 1))
                    cj += c[i]
                elif sign < 0:
                    cj += '0'
                else:
                    cj += '9'
                cc += c[i]
            else:
                if sign == 0:
                    if c[i] < j[i]:
                        sign = -1
                    elif c[i] > j[i]:
                        sign = 1
                cj += j[i]
                cc += c[i]
        complete(i + 1, sign, cc, cj)
    complete(0, 0, "", "")
    print "Case #%d:" % t, pretty(len(c), ansc), pretty(len(c), ansj)
    print >> sys.stderr, t
