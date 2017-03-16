import numpy as np
file = open('b.txt', 'w')

n = input()
for i in range(0, n):
    st = raw_input().split()
    a = st[0]
    b = st[1]
    length = len(a)
    q = np.zeros([length, 10, 10], dtype = long)
    f = np.zeros([length, 10, 10, 2], dtype = long)
    prea = np.zeros([length, 10, 10, 2], dtype = object)
    preb = np.zeros([length, 10, 10, 2], dtype = object)

    for j in range(0, 10):
        for k in range(0, 10):
            if (a[length - 1] != '?') and (int(a[length - 1]) != j):
                q[length - 1][j][k] = 1
            elif (b[length - 1] != '?') and (int(b[length - 1]) != k):
                q[length - 1][j][k] = 1
            else:
                f[length - 1][j][k][0] = j - k
                f[length - 1][j][k][1] = j - k

    for j in range(length - 2, -1, -1):
        for aa in range(0, 10):
            for bb in range(0, 10):
                if (a[j] != '?') and (int(a[j]) != aa):
                    q[j][aa][bb] = 1
                elif (b[j] != '?') and (int(b[j]) != bb):
                    q[j][aa][bb] = 1
                else:
                    f[j][aa][bb][0] = 10 ** 18
                    f[j][aa][bb][1] = 0
                    for pa in range(0, 10):
                        for pb in range(0, 10):
                            if q[j + 1][pa][pb] == 0:
                                for minmax in range(0, 2):
                                    demo = f[j + 1][pa][pb][minmax] + (aa - bb) * (10 ** (length - 1 - j))
                                    if abs(demo) < abs(f[j][aa][bb][0]):
                                        f[j][aa][bb][0] = demo
                                        prea[j][aa][bb][0] = (pa, minmax)
                                        preb[j][aa][bb][0] = (pb, minmax)
                                    if abs(demo) > abs(f[j][aa][bb][1]):
                                        f[j][aa][bb][1] = demo
                                        prea[j][aa][bb][1] = (pa, minmax)
                                        preb[j][aa][bb][1] = (pb, minmax)

    max = 10 ** 18
    sta = (0, 0)
    stb = (0, 0)
    for j in range(0, 10):
        for k in range(0, 10):
            if (q[0][j][k] == 0) and (abs(f[0][j][k][0]) < abs(max)):
                max = f[0][j][k][0]
                sta = (j, 0)
                stb = (k, 0)

    ansa = ""
    ansb = ""
    for j in range(0, length):
        ansa += str(sta[0])
        ansb += str(stb[0])
        newsta = prea[j][sta[0]][stb[0]][sta[1]]
        newstb = preb[j][sta[0]][stb[0]][sta[1]]
        sta = newsta
        stb = newstb

    file.write('Case #%d: %s %s\n' % (i + 1, ansa, ansb))

file.flush()
file.close()