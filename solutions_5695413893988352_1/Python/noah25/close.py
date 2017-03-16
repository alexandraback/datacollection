# Google Code Jam 2016 Round 1B
# Problem B. Close Math

# I. C and J have different first digits (WLOG C < J). Solution : Make C as large as possible and J as small as possible.

# II. C and J have the same first digit. Solution : Just worry about the rest of the string.

# III. C and J both start with question marks. The first digits must be within 1 of each other. We can replace each question mark with (0, 0), (0, 1), or (1, 0). Then, solve the rest of the problem.

# IV. C starts with a question mark, but J does not. Replace the first digit of C with J - 1, J, or J + 1.

# All this should work in the small case at least.

def scores(C, J):
    if len(C) == 0:
        return '', ''
    if C[0] == J[0]:
        if C[0] == '?':
            c, j = scores('0' + C[1:], '0' + J[1:])
            c, j = int(c), int(j)
            x, y = scores('0' + C[1:], '1' + J[1:])
            x, y = int(x), int(y)
            if abs(x - y) < abs(c - j):
                c, j = x, y
            elif abs(x - y) == abs(c - j):
                if x < c or (x == c and y < j):
                    c, j = x, y
            x, y = scores('1' + C[1:], '0' + J[1:])
            x, y = int(x), int(y)
            if abs(x - y) < abs(c - j):
                c, j = x, y
            elif abs(x - y) == abs(c - j):
                if x < c or (x == c and y < j):
                    c, j = x, y
            c = str(c)
            j = str(j)
            c = (len(C) - len(c))*'0' + c
            j = (len(J) - len(j))*'0' + j
            return c, j
        else:
            x, y = scores(C[1:], J[1:])
            return C[0] + x, C[0] + y
    # At this point, C[0] != J[0].
    if C[0] == '?':
        c, j = scores(J[0] + C[1:], J)
        c = int(c)
        j = int(j)
        if J[0] != '9':
            x, y = scores(str(int(J[0]) + 1) + C[1:], J)
            x = int(x)
            y = int(y)
            if abs(x - y) < abs(c - j):
                c = x
                j = y
            elif abs(x - y) == abs(c - j):
                if x < c:
                    c = x
                    j = y
                elif x == c:
                    j = y
        if J[0] != '0':
            x, y = scores(str(int(J[0]) - 1) + C[1:], J)
            x = int(x)
            y = int(y)
            if abs(x - y) < abs(c - j):
                c = x
                j = y
            elif abs(x - y) == abs(c - j):
                if x < c or (x == c and y < j):
                    c = x
                    j = y
        c = str(c)
        j = str(j)
        c = (len(C) - len(c))*'0' + c
        j = (len(J) - len(j))*'0' + j
        return c, j
    if J[0] == '?':
        c, j = scores(C, C[0] + J[1:])
        c = int(c)
        j = int(j)
        if C[0] != '9':
            x, y = scores(C, str(int(C[0]) + 1) + J[1:])
            x = int(x)
            y = int(y)
            if abs(x - y) < abs(c - j):
                c = x
                j = y
            elif abs(x - y) == abs(c - j):
                if x < c or (x == c and y < j):
                    c = x
                    j = y
        if C[0] != '0':
            x, y = scores(C, str(int(C[0]) - 1) + J[1:])
            x = int(x)
            y = int(y)
            if abs(x - y) < abs(c - j):
                c = x
                j = y
            elif abs(x - y) == abs(c - j):
                if x < c or (x == c and y < j):
                    c = x
                    j = y
        c = str(c)
        j = str(j)
        c = (len(C) - len(c))*'0' + c
        j = (len(J) - len(j))*'0' + j
        return c, j
    # C and J start with different digits.
    c = ''
    j = ''
    first = C[0] < J[0]
    for i in C:
        if i == '?':
            c += str(9*first)
        else:
            c += i
    for i in J:
        if i == '?':
            j += str(9*(not first))
        else:
            j += i
    return c, j

def games():
    f = open('commands.txt', 'r')
    g = open('scores.txt', 'w')
    line = 0
    for i in f:
        if line == 0:
            T = int(i)
            line = 1
        else:
            C = ''
            J = ''
            spaces = 0
            for j in i:
                if j == ' ':
                    spaces = 1
                else:
                    if j != '\n':
                        if spaces == 0:
                            C += j
                        else:
                            J += j
            g.write('Case #' + str(line) + ': ')
            c, j = scores(C, J)
            g.write(c + ' ' + j + (T != line)*'\n')
            line += 1
            if line%10 == 0:
                print line
    f.close()
    g.close()
