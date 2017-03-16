def check(x):
    for i in range(1, x + 1):
        cnt = 0
        for j in range(len(p)):
            cnt += (p[j] - 1) // i
        if i + cnt <= x:
            return True
    return False

fin = open("b.in", "r")
fout = open("b.txt", "w")

t = int(fin.readline())
for ii in range(t):
    d = int(fin.readline())
    p = list(map(int, fin.readline().split()))
    L = 0
    R = 10 ** 6
    while R - L > 1:
        M = (R + L) // 2
        if check(M):
            R = M
        else:
            L = M
    print('Case #%d: %d' % (ii + 1, R), file=fout)

fin.close()
fout.close()