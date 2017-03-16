from traceback import print_exc
def mine(r, c, m):
    b = None
    if m >= r*c:
        return None
    elif m == r*c-1:
        b = ['*'*c]*r
        b[0] = 'c'+'*'*(c-1)
    elif r == 1:
        b = ['c'+'.'*(c-1-m)+'*'*m]
    elif c == 1:
        b = ['c'] + ['.']*(r-1-m) + ['*']*m
    elif r == 2 or c == 2:
        if m & 1 or r*c-m < 4:
            return None
        r2 = '.'*((r*c-m)/2)+'*'*(m/2)
        r1 = 'c'+r2[1:]
        if r == 2:
            b = [r1, r2]
        else:
            b = [x+y for x, y in zip(r1, r2)]
    else:
        e = r*c-m
        if e in [2, 3, 5, 7]:
            return None
        elif e <= 2*c+1:
            if e & 1:
                b = ['.'*((e-3)/2)+'*'*(c-(e-3)/2)]*2 + ['.'*3 + '*'*(c-3)] + ['*'*c]*(r-3)
            else:
                b = ['.'*(e/2)+'*'*(c-e/2)]*2 + ['*'*c]*(r-2)
        elif e % c == 1:
            u, v = e/c-1, c+1
            b = ['.'*c]*u + ['.'*(v-2)+'*'*(c-v+2)] + ['.'*2+'*'*(c-2)] + ['*'*c]*(r-u-2)
        else:
            u, v = e/c, e%c
            if v == 0:
                u, v = u-1, v+c
            b = ['.'*c]*u + ['.'*v+'*'*(c-v)] + ['*'*c]*(r-u-1)
        b[0] = 'c'+b[0][1:]
    return b

def check(n):
    for r in range(1, n+1):
        for c in range(1, n+1):
            for m in range(r*c):
                b = mine(r, c, m)
                try:
                    if b is None:
                        assert m >= r*c or r*c-m in [2, 3, 5, 7] or ((r==2 or c==2) and (r*c-m)&1)
                    else:
                        assert len(b) == r and set(map(len, b))==set([c])
                        v = [[0]*c for _ in range(r)]
                        cx = cy = -1
                        cm = 0
                        for i in range(r):
                            for j in range(c):
                                assert (b[i][j] in 'c.*')
                                if b[i][j] == 'c':
                                    assert(cx < 0 and cy < 0)
                                    cx, cy = i, j
                                elif b[i][j] == '*':
                                    for dx in [-1, 0, 1]:
                                        for dy in [-1, 0, 1]:
                                            if i + dx >= 0 and i+dx < r and j+dy >= 0 and j+dy < c:
                                                v[i+dx][j+dy] += 1
                                    cm += 1
                        assert(cx >= 0 and cy >= 0 and cm == m)
                        q = set()
                        if v[cx][cy] == 0:
                            q.add((cx, cy))
                        cnt = 1
                        v[cx][cy] = -1
                        while len(q) > 0:
                            x, y = q.pop()
                            for dx in [-1, 0, 1]:
                                for dy in [-1, 0, 1]:
                                    if x + dx >= 0 and x+dx < r and y+dy >= 0 and y+dy < c and v[x+dx][y+dy] >= 0:
                                        if v[x+dx][y+dy] == 0:
                                            q.add((x+dx, y+dy))
                                        cnt += 1
                                        v[x+dx][y+dy] = -1
                        assert m + cnt == r*c
                except AssertionError, e:
                    print r, c, m
                    print '\n'.join(b)
                    print_exc()
                    raise SystemExit
    print 'check ok!'

#check(15)
t = int(raw_input())
for iCase in range(1, t+1):
    r, c, m = map(int, raw_input().split())
    b = mine(r, c, m)
    print 'Case #%d:' % iCase
    if b is None:
        print 'Impossible'
    else:
        print '\n'.join(b)
