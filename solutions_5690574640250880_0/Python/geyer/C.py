# Minesweeper
import numpy


def reverse_ll(t):
        a = numpy.array(t)
        a = a.transpose()
        t = list(a)
        t = map(list, t)
        return t


def width_1(length, mines):
    """ solves problem for R = 1, C = length, M = mines
        assume length > mines >= 0
    """
    s = '.' * (length - mines) + '*' * mines
    return [list(s)]


def width_2(length, mines):
    """ solve for R = 2, C = length >= 2, M = mines
        assume M is even
    """
    if 2 * length == mines + 1:
        t = list('*' * length)
        output = [t[:], t[:]]
        output[0][0] = 'c'
        return output
    if mines % 2 != 0 or mines == 2 * length - 2:
        print 'In width_2: mine number must be (RC-1) or even and <=(RC-4)'
        return None
    t = list('.' * (length - (mines / 2)) + '*' * (mines / 2))
    output = [t[:], t[:]]
    return output


def width_high(R, C, M):
    """ use width_1 and width_2 versions to solve this.
        Assume 3 <= R <= C
    """
    t = []
    free = R * C - M
    if free in [1, 4, 6, 8, 9]:
        for iterator in range(R):
            t.append(list('*' * C))
        # special cases
        if free == 1:
            t[0][0] = 'c'
        elif free == 4:
            t[0][0] = 'c'
            t[0][1] = '.'
            t[1][0] = '.'
            t[1][1] = '.'
        elif free == 6:
            for i in range(3):
                for j in range(2):
                    t[i][j] = '.'
            t[0][0] = 'c'
        elif free == 8:
            for i in range(3):
                for j in range(3):
                    t[i][j] = '.'
            t[0][0] = 'c'
            t[2][2] = '*'
        elif free == 9:
            for i in range(3):
                for j in range(3):
                    t[i][j] = '.'
            t[0][0] = 'c'
        return t
    # end of special cases

    # write M = n * R + k
    n, k = divmod(M, R)

    if C - n > 3:
        # fill n columns from left
        for r in range(R):
            t.append(list('.' * (C - n) + '*' * n))
        # there are k < R mines left
        if k < R - 1:
            for i in range(k):
                t[i][C - n - 1] = '*'
            t[0][0] = 'c'
        else:
            # k = R - 1 and R >= 4
            for i in range(2, R):
                t[i][C - n - 1] = '*'
            t[R - 1][C - n - 2] = '*'
            t[0][0] = 'c'
        return t

    # remains C - n <= 3, free > 9
    for r in range(R):
        t.append(list('.' * 3 + '*' * (C - 3)))
    # calculate remaining mines
    M = M - R * (C - 3)
    # write M = 3 * n + k
    n, k = divmod(M, 3)
    for i in range(R - n, R):
        t[i][0] = '*'
        t[i][1] = '*'
        t[i][2] = '*'
    for i in range(R - n - k, R - n):
        t[i][2] = '*'
    t[0][0] = 'c'
    return t


def test_field(R, C, M):
    # Assume that R <= C. Need to compensate when printing example
    reverse = False
    if C < R:
        R, C = C, R
        reverse = True

    # output in list t, and t == [] if impossible
    if R == 1:
        t = width_1(C, M)
        t[0][0] = 'c'
    elif R == 2:
        if (M % 2 == 1 and R * C != M + 1) or (R * C == M + 2):
            t = []
        else:
            t = width_2(C, M)
            t[0][0] = 'c'
    elif R * C - M in [2, 3, 5, 7]:
        t = []
    else:
        t = width_high(R, C, M)

    # output of function
    if t == []:
        return 'Impossible'
    # place click in top left corner
    if reverse is True:
        t = reverse_ll(t)
    t = map(lambda x: ''.join(x), t)
    t = '\n'.join(t)
    return t

# file input
with open('C-small-attempt2.in.txt', 'r') as fin, open('C-small.out.txt', 'w') as fout:
    T = int(fin.readline().split()[0])
    for case in range(T):
        line = fin.readline()
        R, C, M = map(int, line.split())
        print R, C, M
        output = "Case #%d: \n" % (case + 1)
        output = output + test_field(R, C, M)
        fout.write(output + '\n')
