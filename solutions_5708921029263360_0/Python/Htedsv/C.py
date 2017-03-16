import sys

fin = open(sys.argv[1])
T = int(fin.readline())
for I in range(1, T+1):
    a, b, c, k = [int(x) for x in fin.readline().split(' ')]
    outfit = a*b*c
    outfit = min(outfit, a*b*k)
    print "Case #%d: %d"%(I, outfit)
    cc = 0
    count = outfit
    counts = [[k for j in range(c)] for i in range(a)]
    counts2 = [[k for j in range(b)] for i in range(a)]
    counts3 = [[k for j in range(c)] for i in range(b)]
    s = set([])
    for kk in range(k):
        for i in range(a):
            for j in range(b):
                tc = -1
                for cc in range(c):
                    if counts[i][cc] > 0 and counts2[i][j] > 0 and counts3[j][cc] > 0 and (i, j, cc) not in s:
                        tc = cc
                        break
                if tc == -1: continue
                s.add((i, j, tc))
                counts[i][tc] -= 1
                counts2[i][j] -= 1
                counts3[j][tc]-= 1
                print i+1, j+1, tc+1
                count -= 1
                if count == 0:
                    break
            if count == 0:
                break
        if count == 0:
            break

