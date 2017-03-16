import logging
import string
import numpy as np
# import random


def exA(filename='inputA'):
    # reader
    rownum = 0
    s = list()
    with open('Input/' + filename, 'rb') as file:
        for row in file:
            if rownum > 0 and rownum % 2 == 0:
                s.append(row.split(' '))
            rownum += 1
    sint = list()
    for e in s:
        sint.append([int(x) for x in e])

    print sint

    # algo
    d = dict()
    for x, y in zip(range(1, 27), string.ascii_uppercase):
        d[x] = y

    with open('Output/' + filename.split('.')[0] + '.out', 'w') as file:
        solnum = 0
        for e in sint:
            solnum += 1
            file.write('Case #' + str(solnum) + ': ')
            while max(e) > 0:
                tmpSol = ''
                idx = e.index(max(e))
                e[idx] -= 1
                tmpSol += d[idx + 1]

                if max(e) == 0:
                    file.write(tmpSol)
                    break

                if sum(e) % 2 == 0:
                    # take only one argument
                    file.write(tmpSol + ' ')
                    continue

                idx = e.index(max(e))
                e[idx] -= 1
                tmpSol += d[idx + 1]
                file.write(tmpSol + ' ')
            file.write('\n')

    # for i in range(len(sol)):
    # file.write('Case #' + str(i+1) + ': ' + sol[i] + '\n')


def exB(filename='inputB.in'):
    # reader
    rownum = 0
    s = list()
    with open('Input/' + filename, 'rb') as file:
        for row in file:
            if rownum > 0:
                s.append((int(row.split(' ')[0].strip()), int(row.split(' ')[1].strip())))
            rownum += 1
    print s

    # algo
    file = open('Output/' + filename.split('.')[0] + '.out', 'w')
    solnum = 0
    for e in s:
        solnum += 1
        B = e[0]
        M = e[1]

        mat = np.zeros((B, B), dtype=np.int)

        if pow(2, B - 2) < M:
            file.write('Case #' + str(solnum) + ': IMPOSSIBLE\n')
        else:
            file.write('Case #' + str(solnum) + ': POSSIBLE\n')
            npaths = recPath(mat, 0, B - 1, M, 0)

            # count paths
            n = countPaths(mat, 0)
            if n != npaths:

                row, col = np.nonzero(mat)
                for i in range(len(row)):
                    mat[row[i], col[i]] = 0
                    if countPaths(mat, 0) == M:
                        continue
                    else:
                        mat[row[i], col[i]] = 1


                #print B
                #print M
                #print npaths
                #print n
                #print mat

            # write
            for i in range(mat.shape[0]):
                tmpStr = ''
                for j in range(mat.shape[1]):
                    tmpStr += str(mat[i][j])
                tmpStr += '\n'
                file.write(tmpStr)


def countPaths(mat, n, start=0):
    if start == mat.shape[0] - 1:
        return n + 1

    indices = [i for i, x in enumerate(mat[start]) if x == 1]
    for e in indices:
        n = countPaths(mat, n, e)
    return n


def recPath(mat, start, B, M, npaths):

    if npaths == M:
        # print '#paths == M'
        return npaths

    if start == B:
        # print '\nPath found'
        # print mat
        npaths += 1
        # print npaths
        return npaths

    for i in range(start + 1, B + 1):
        # print 'Start: ' + str(start) + '  Ziel: ' + str(i) + '  #Paths: ' + str(npaths)
        mat[start, i] = 1
        npaths = recPath(mat, i, B, M, npaths)

        if npaths == M:
            break

    return npaths


def exC(filename='inputC.in'):
    pass


if __name__ == "__main__":

    FORMAT = '%(levelname)s: %(message)s'
    logging.basicConfig(format=FORMAT, level=logging.DEBUG)

    # exA('inputA.in')
    exB('inputB.in')
    # exC('inputC.in')
