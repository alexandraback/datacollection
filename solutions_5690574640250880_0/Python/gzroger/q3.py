__author__ = 'zoli'


class Imposible(Exception):
    pass


def countNeighbour(row, col, R, C, tab):
    cT = 0
    for r in range(-1, 2, 1):
        for c in range(-1, 2, 1):
            if 0 <= (row + r) < R and 0 <= (col + c) < C:
                if tab[row + r][col + c] == '*':
                    cT += 1
    return ' ' if cT == 0 else str(cT)


def generateAndCheck(R, C, M, tab):
    countM = 0
    checkTab = []
    for row in range(R):
        rgrow = []
        for col in range(C):
            if tab[row][col] == '*':
                countM += 1
                rgrow.append('*')
            else:
                rgrow.append(countNeighbour(row, col, R, C, tab))
        checkTab.append(rgrow)
        #print(''.join(rgrow))

    #print('')

    for row in range(R):
        for col in range(C):
            if not checkTab[row][col] in {' ', '*'}:
                fOk = row == 0 and col == 0
                for r in range(-1, 2, 1):
                    for c in range(-1, 2, 1):
                        if 0 <= (row + r) < R and 0 <= (col + c) < C:
                            fOk = fOk or checkTab[row + r][col + c] == ' '
                if not fOk:
                    raise Exception

    if M != countM:
        raise Exception


def putEmpty(R, C, cNotMine, cNow, tab, row, col):
    if row == 0:
        if (cNow < cNotMine - 1) and ((col != (C - 1)) or cNotMine - cNow - 2 != 1):
            tab[0][col] = '.'
            tab[1][col] = '.'
            cNow += 2
    elif col == 0:
        if cNow < cNotMine - 1:
            tab[row][0] = '.'
            tab[row][1] = '.'
            cNow += 2
    else:
        tab[row][col] = '.'
        tab[row][col] = '.'
        cNow += 1
    return cNow


def generateLarge(C, R, cNotMine, cNow, tab):
    tab[0][1] = '.'
    tab[1][0] = '.'
    tab[1][1] = '.'
    cNow = 4

    if cNotMine == 9 and C >= 3 and R >= 3:
        cNow = putEmpty(R, C, cNotMine, cNow, tab, 0, 2)
        cNow = putEmpty(R, C, cNotMine, cNow, tab, 2, 0)
        cNow = putEmpty(R, C, cNotMine, cNow, tab, 2, 2)
        return cNow

    #while cNow < cNotMine:
    row = 0
    col = 2
    while col < C and cNow < cNotMine:
        cNow = putEmpty(R, C, cNotMine, cNow, tab, row, col)
        col += 1

    row = 2
    col = 0
    while row < R and cNow < cNotMine:
        cNow = putEmpty(R, C, cNotMine, cNow, tab, row, col)
        row += 1

    row = 2
    while row < R and cNow < cNotMine:
        col = 2
        while col < C and cNow < cNotMine:
            cNow = putEmpty(R, C, cNotMine, cNow, tab, row, col)
            col += 1
        row += 1

    return cNow


def revealFromCR(R, C, M, tab, revealed, row, col):
    revealed[row][col] = countNeighbour(row, col, R, C, tab)
    if revealed[row][col] == ' ':
        for r in range(-1, 2, 1):
            for c in range(-1, 2, 1):
                if 0 <= (row + r) < R and 0 <= (col + c) < C:
                    if revealed[row + r][col + c] == '.':
                        revealFromCR(R, C, M, tab, revealed, row + r, col + c)


def revealFromC(R, C, M, tab, rowStart, colStart):
    revealed = []
    for row in range(R):
        rgrow = []
        for col in range(C):
            rgrow.append('.')
        revealed.append(rgrow)
    revealFromCR(R, C, M, tab, revealed, rowStart, colStart)
    cDot = 0
    for row in range(R):
        for col in range(C):
            if revealed[row][col] == '.':
                cDot += 1
    if cDot != M:
        raise Exception


def generate(R, C, M):
    cNotMine = R * C - M
    if 1 > cNotMine:
        raise Imposible

    if cNotMine in {2, 3, 5, 7} and M != 0 and C != 1 and R != 1:
        raise Imposible
    if (R == 2 or C == 2) and cNotMine % 2 == 1 and cNotMine != 1:
        raise Imposible

    tab = []
    for row in range(R):
        rgrow = []
        for col in range(C):
            rgrow.append('*')
        tab.append(rgrow)

    tab[0][0] = 'c'
    cNow = 1
    if cNotMine != 1:
        if R == 1 and C == 1:
            cNow = 0
        elif R == 1:
            tab[0][1] = '.'
            cNow = 2
            while cNow < cNotMine:
                tab[0][cNow] = '.'
                cNow += 1
        elif C == 1:
            tab[1][0] = '.'
            cNow = 2
            while cNow < cNotMine:
                tab[cNow][0] = '.'
                cNow += 1
        else:
            cNow = generateLarge(C, R, cNotMine, cNow, tab)

    if cNow == cNotMine:
        generateAndCheck(R, C, M, tab)
        revealFromC(R, C, M, tab, 0, 0)
        # try:
        # except Exception:
        #     pass
        # else:
        #     if cNotMine in {2, 3, 5, 7} and M != 0 and R != 1 and C != 1:
        #         raise Exception
        #     if (R == 2 or C == 2) and cNotMine % 2 == 1 and R * C - M != 1:
        #         raise Exception
        #
        return tab
        #

    raise Exception


import itertools


def checkVariant(C, M, R, tab):
    for row in range(R):
        for col in range(C):
            if countNeighbour(row, col, R, C, tab) == ' ':
                try:
                    revealFromC(R, C, M, tab, row, col)
                    tab[row][col] = 'c'
                    return True
                except Exception:
                    return False


def tryAll(R, C, M):
    for cmb in itertools.combinations(range(R * C), M):
        tab = []
        for row in range(R):
            rgrow = []
            for col in range(C):
                rgrow.append('.')
            tab.append(rgrow)
        for c in cmb:
            tab[c % R][c // R] = '*'

        if checkVariant(C, M, R, tab):
            return tab

    return None


def solve(filnIn, filnOut):
    f = open(filnIn)
    fOut = open(filnOut, "w")
    T = int(f.readline())

    for i in range(T):
        rgparams = [int(st) for st in f.readline().split()]
        R = rgparams[0]
        C = rgparams[1]
        M = rgparams[2]
        stMsg = "Case #{0}: ".format(i + 1)
        print(stMsg)
        fOut.write(stMsg)
        fOut.write("\n")

        try:
            tab = generate(R, C, M)
        except Imposible:
            if R != 2 and C != 2 and R * C - M > 3:
                print('Impossible')
            fOut.write('Impossible')
            fOut.write("\n")
        else:
            for rgLine in tab:
                print(''.join(rgLine))
                fOut.write(''.join(rgLine))
                fOut.write('\n')

#         t = tryAll(R, C, M)
#         if t:
#             tab = t
#             for rgLine in tab:
#                 print(''.join(rgLine))
#                 fOut.write(''.join(rgLine))
#                 fOut.write('\n')
#         else:
#             print("Impossible")
#             fOut.write("Impossible")
#             fOut.write('\n')



if __name__ == "__main__":
    #    solve("B-large.in", "B-large.out")
    #        solve("C-small-attempt1.in", "C-small-attempt1.out")
    solve("C-small-attempt5.in", "C-small-attempt5.out")
    #solve("C-small-attempt4.in", "C-small-attempt4.out")
    #solve("C-small-attempt0.in", "C-small-attempt0.out")
    #solve("sample.in", "sample.out")
