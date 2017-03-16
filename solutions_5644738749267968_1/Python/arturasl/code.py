#!/usr/local/bin/pythonw3.2

def kenMove(n, blocks):
    for j in range(len(blocks)):
        if blocks[j] > n:
            return j
    for j in range(len(blocks)):
        if blocks[j] != -1:
            return j

for case in range(1, int(input()) + 1):
    N = int(input())
    blocks = [sorted([int(a[2:].ljust(6, '0')) for a in input().strip().split()[:N]]) for _ in range(2)]

    t = blocks[1][:]
    z = 0
    for n in blocks[0]:
        j = kenMove(n, t)
        z += t[j] < n
        t.pop(j)

    t = blocks[1][:]
    y = 0
    while blocks[0]:
        j = kenMove(n, t)
        if t[j] < blocks[0][0]:
            y += 1
        else:
            j = kenMove(max(t) - 0.1, t)
        blocks[0].pop(0)
        t.pop(j)

    print('Case #{}: {} {}'.format(case, y, z))
