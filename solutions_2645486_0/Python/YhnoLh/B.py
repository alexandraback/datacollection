E = 0
R = 0
N = 0
v = []

def dfs(k, e, value):
    global E, R, N, v, ans

    if k == N:
        if value > ans:
            ans = value
    else:
        for i in range(e + 1):
            orig = e
            value += i * v[k]
            e = e - i + R
            if e > E:
                e = E
            dfs(k + 1, e, value)
            e = orig
            value -= i * v[k]

    return


fi = open('B-small-attempt0.in', 'r')
fo = open('B.out', 'w')

ans = 0

T = int(fi.readline())
for case_i in range(T):
    line = fi.readline().split()
    E = int(line[0])
    R = int(line[1])
    N = int(line[2])

    v = []
    ans = 0
    line = fi.readline().split()
    for i in range(N):
        v.append(int(line[i]))

    # Small Version

    dfs(0, E, 0)

    fo.write('Case #%d: %d\n' % (case_i + 1, ans))

fi.close()
fo.close()
