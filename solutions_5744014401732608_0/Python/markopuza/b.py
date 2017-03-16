import numpy as np

def ways(mat, b, aim):
    good = False
    for j in range(b):
        if mat[j][b-1] == 1:
            good = True
            break
    if good == False:
        return 0

    curr = mat
    r = curr[0][b - 1]
    for _ in range(b - 1):
        curr = curr.dot(mat)
        r += curr[0][b - 1]
    return r

def cyclic(mat, b):
    pw = np.linalg.matrix_power(mat, b)
    for i in range(b):
        for j in range(b):
            if pw[i][j]:
                return True
    return False


def check(mat, aim, b, ones, lasti, lastj):
    if (ones > 0 and cyclic(mat, b)) or ones > b * b // 2 + 1:
        return (False, False)

    w = ways(mat, b, aim)
    if w == aim:
        return (True, mat)
    elif w < aim:
        for i in range(lasti, b):
            for j in range((lastj if i == lasti else i) + 1, b):
                if mat[i][j] == 0 and mat[j][i] != 1:
                    copym = np.array(mat)
                    copym[i][j] = 1
                    res = check(copym, aim, b, ones + 1, i, j)
                    if res[0] == True:
                        return res
    return (False, False)

for t in range(1, int(raw_input()) + 1):
     b, m = map(int, raw_input().split())
     mat = np.array([np.array([0 for _ in range(b)]) for _ in range(b)])
     ch = check(mat, m, b, 0, 0, 0)
     if ch[0]:
         print('Case #' + str(t) + ': POSSIBLE')
         for l in ch[1]:
             print(''.join(map(str,l)))
     else:
         print('Case #' + str(t) + ': IMPOSSIBLE')
