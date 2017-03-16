from collections import defaultdict

f = open('B-small-attempt6.in', 'r')
o = open('B.out', 'w')

UNKNOWN = '?'

inf = float('inf')

def diff(ss):
    if ss[0] == ss[1] == '':
        return 0
    return int(ss[0]) - int(ss[1])

def calc(c, pm):
    return chr(ord(c) + pm)

def find(c, j):
    # DP
    # last (n - i) digits (c-j greatest, |c-j| least, j-c greatest)
    i, s = len(c), (('', ''), ('', ''), ('', ''))
    u = 1
    while i > 0:
        i -= 1
        if c[i] == j[i] == UNKNOWN:
            d = diff(s[1])
            min_d = abs(d)
            # (0X, 0X)
            min_p = ('0' + s[1][0], '0' + s[1][1])
            # (0X, 1X)
            d = u - diff(s[0])
            if d < min_d:
                min_d = d
                min_p = ('0' + s[0][0], '1' + s[0][1])
            # (1X, 0X)
            d = u + diff(s[2])
            if d < min_d:
                min_d = d
                min_p = ('1' + s[2][0], '0' + s[2][1])
            s = (('9' + s[0][0], '0' + s[0][1]),
                 min_p,
                 ('0' + s[2][0], '9' + s[2][1]))
        elif c[i] == UNKNOWN:
            d = diff(s[1])
            min_d = abs(d)
            if d == u / 2 and j[i] > '0':
                min_p = (calc(j[i], -1) + s[1][0], j[i] + s[1][1])
            else:
                min_p = (j[i] + s[1][0], j[i] + s[1][1])
            if j[i] > '0':
                d = u - diff(s[0])
                if d <= min_d:
                    min_d = d
                    min_p = (calc(j[i], -1) + s[0][0], j[i] + s[0][1])
            if j[i] < '9':
                d = u + diff(s[2])
                if d < min_d:
                    min_d = d
                    min_p = (calc(j[i], +1) + s[2][0], j[i] + s[2][1])
            s = (('9' + s[0][0], j[i] + s[0][1]),
                 min_p,
                 ('0' + s[2][0], j[i] + s[2][1]))
        elif j[i] == UNKNOWN:
            d = diff(s[1])
            min_d = abs(d)
            if -d == u / 2 and c[i] > '0':
                min_p = (c[i] + s[1][0], calc(c[i], -1) + s[1][1])
            else:
                min_p = (c[i] + s[1][0], c[i] + s[1][1])
            if c[i] > '0':
                d = u + diff(s[2])
                if d <= min_d:
                    min_d = d
                    min_p = (c[i] + s[2][0], calc(c[i], -1) + s[2][1])
            if c[i] < '9':
                d = u - diff(s[0])
                if d < min_d:
                    min_d = d
                    min_p = (c[i] + s[0][0], calc(c[i], +1) + s[0][1])
            s = ((c[i] + s[0][0], '0' + s[0][1]),
                 min_p,
                 (c[i] + s[2][0], '9' + s[2][1]))
        else:
            if c[i] < j[i]:
                s_mid = (c[i] + s[0][0], j[i] + s[0][1])
            elif c[i] > j[i]:
                s_mid = (c[i] + s[2][0], j[i] + s[2][1])
            else:
                s_mid = (c[i] + s[1][0], j[i] + s[1][1])
            s = ((c[i] + s[0][0], j[i] + s[0][1]),
                 s_mid,
                 (c[i] + s[2][0], j[i] + s[2][1]))
        u *= 10
    return s[1][0] + ' ' + s[1][1]

m = int(f.readline().strip())
i = 1

while i <= m:
    c, j = next(f).strip().split()
    print('Case #{0}: {1}'.format(i, find(c, j)), file = o)
    i += 1

f.close()
o.close()
