from common import *

# 0 = 1
# 1 = i
# 2 = j
# 3 = k
# +4 = change sign

mult = [None] * 8
for a in range(8):
    mult[a] = [None] * 8

mult[0] = list(range(8))
mult[1] = [1, 4, 3, 6, 5, 0, 7, 2]
mult[2] = [2, 7, 4, 1, 6, 3, 0, 5]
mult[3] = [3, 2, 5, 4, 7, 6, 1, 0]
for a in range(4, 8):
    for b in range(8):
        mult[a][b] = (4 + mult[a - 4][b]) % 8

def power(a, n):
    n = (n % 4)
    if n == 0:
        return 0
    elif n == 1:
        return a
    elif n == 2:
        return mult[a][a]
    else:
        return mult[a][mult[a][a]]


def parse(c):
    if c == 'i':
        return 1
    if c == 'j':
        return 2
    if c == 'k':
        return 3

def unparse(a):
    s = ''
    if a >= 4:
        s = '-'
        a -= 4
    s += '1ijk'[a]
    return s


def main(casenum):
    l, x = readints()
    cs = readline()
    vs = []
    for c in cs:
        vs.append(parse(c))

    if x > 12:
        x = (x % 4) + 8

    vs = vs * x

    found_i = False
    found_j = False
    found_k = False

    prod = 0
    for v in vs:
        prod = mult[prod][v]

        if found_i:
            if prod == 3:
                found_j = True
        else:
            if prod == 1:
                found_i = True

    if found_i and found_j and prod == 4:
        found_k = True

    if found_i and found_j and found_k:
        writecase(casenum, 'YES')
    else:
        writecase(casenum, 'NO')

run(main)
