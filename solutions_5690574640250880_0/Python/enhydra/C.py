import sys

inp = map(int, (' '.join(sys.stdin.read().splitlines())).split(' '))

N = inp[0]
for T in xrange(int(N)):
    H, W, M = inp[1+T*3:4+T*3]
   
    if W > H:
        H, W = W, H
        R = 1
    else:
        R = 0

    fie = [['*']*W for i in xrange(H)]

    fc = H*W - M
    if W == 1:
        fie[0][0] = 'c'
        for i in xrange(1, fc):
            fie[i][0] = '.'
    elif W == 2:
        if fc % 2 == 0 and fc > 2:
            for i in xrange(fc / 2):
                fie[i][0] = fie[i][1] = '.'
            fie[0][0] = 'c'
        elif fc == 1:
            fie[0][0] = 'c'
        else:
            fie = None
    else:
        if fc in [2, 3, 5, 7]:
            fie = None
        elif fc == 1:
            fie[0][0] = 'c'
        elif fc == 4:
            fie[0][0] = 'c'
            fie[0][1] = fie[1][0] = fie[1][1] = '.'
        elif fc == 6:
            fie[0][0] = 'c'
            fie[0][1] = fie[1][0] = fie[1][1] = fie[2][0] = fie[2][1] = '.'
        elif fc == 8:
            fie[0][0] = 'c'
            fie[0][1] = fie[1][0] = fie[1][1] = fie[2][0] = fie[2][1] = fie[0][2] = fie[1][2] = '.'
        else: # 9+
            if fc <= 3 * W:
                rows = [fc/3]*3
                if fc % 3 == 1:
                    rows[0] += 1
                    rows[1] += 1
                    rows[2] -= 1
                elif fc % 3 == 2:
                    rows[0] += 1
                    rows[1] += 1
            else:
                rows = [W]*(fc/W) + [fc % W]
                if rows[-1] == 1:
                    rows[-1] += 1
                    rows[-2] -= 1
            for i, I in enumerate(rows):
                for j in xrange(I):
                    fie[i][j] = '.'
            fie[0][0] = 'c'

    if R and fie:
        fie = [[fie[j][i] for j in xrange(len(fie))] for i in xrange(len(fie[0]))]
    if fie:
        r = '\n'.join(map(''.join, fie))
    else:
        r = "Impossible"

    print "Case #%d:\n%s" % (T+1, r)
