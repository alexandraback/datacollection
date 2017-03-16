#!/usr/bin/env python3

def solve(fin, fout):
    n, x, y = map(int, fin.readline().split())
    x = abs(x)

    if (n == 0):
        fout.write('0\n')
        return

    if (n == 1):
        if x == 0 and y == 0:
            fout.write('1\n')
            return
        else:
            fout.write('0\n')
            return

    lv = 0
    for i in range(1, 10000):
        if i * ( 2 * i - 1) > n:
            lv = i
            break
    
    lv -= 1
    if (x + y) / 2 > lv:
        fout.write('0\n')
        return
    if (x + y) / 2 < lv:
        fout.write('1\n')
        return

    m = n - lv * (lv * 2 - 1)

    if x == 0:
        fout.write('0\n')
        return

    op = False
    if m >= 2 * lv + 1:
        m = 2 * (2 * lv) - m
        y = (2 * lv) - y - 1
        op = True
        print('Flip!')

    if m < 2 * lv + 1:
        p = [0] * (2 * lv + 1)
        for i in range(m):
            j =  2 * lv
            q = 0.5
            while j > 0:
                p[j] += q * p[j - 1]
                q *= 1 - p[j-1]
                j -= 1
            p[0] += q
        print(p)
        print(m, y)
        if not op:
            fout.write(str(p[y]) + '\n')
        else:
            fout.write(str(1 - p[y]) + '\n')

        return


    fout.write('YES\n')

