def ff0(x, y, n, m, t, c, f, h):
    adv = [[0, 1], [1, 0], [0, -1], [-1, 0]]
    for i in adv:
        tx = x + i[0]
        ty = y + i[1]
        if tx >=0 and tx < n and ty >= 0 and ty < m:
            th = c[tx][ty] - 50
            if h <= th and f[x][y] <= th and f[tx][ty] <= th and f[tx][ty] <= c[x][y] - 50:
                # can advance
                if t[tx][ty] != 0:
                    t[tx][ty] = 0
                    ff0(tx, ty, n, m, t, c, f, h)
    return
    
def ff(x, y, n, m, t, c, f, h):
    adv = [[0, 1], [1, 0], [0, -1], [-1, 0]]
    hnow = h - t[x][y] * 10
    for i in adv:
        tx = x + i[0]
        ty = y + i[1]
        if tx >= 0 and tx < n and ty >= 0 and ty < m:
            th = c[tx][ty] - 50
            if f[x][y] <= th and f[tx][ty] <= th and f[tx][ty] <= c[x][y] - 50:
                # can advance
                if hnow <= th:
                    tt = 0
                else:
                    tt = (hnow - th) / 10
                if hnow - tt * 10 - 20 >= f[x][y] and t[x][y] + 1 + tt < t[tx][ty]:
                    t[tx][ty] = t[x][y] + 1 + tt
                    ff(tx, ty, n, m, t, c, f, h)
                elif t[x][y] + 10 + tt < t[tx][ty]:
                    t[tx][ty] = t[x][y] + 10 + tt
                    ff(tx, ty, n, m, t, c, f, h)
    return

T = int(input())
INF = 99999999

for tx in range(T):
    h, n, m = list(map(int, input().split()))
    c = []
    f = []
    for i in range(n):
        tmp = list(map(int, input().split()))
        c += [tmp]
    for i in range(n):
        tmp = list(map(int, input().split()))
        f += [tmp]
    t = [[INF for i in range(m)] for j in range(n)]
    t[0][0] = 0
    ff0(0, 0, n, m, t, c, f, h)
    for i in range(n):
        for j in range(m):
            ff(i, j, n, m, t, c, f, h)
    print("Case #%d: %f"%(tx + 1, t[n - 1][m - 1]))
    
    

