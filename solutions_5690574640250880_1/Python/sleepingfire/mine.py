import sys

path = "test.in" if len(sys.argv) == 1 else sys.argv[1]
file = open(path, "r")
T = int(file.readline())

def output(s):
    for i in range(R):
        print("".join(s[i]))

for i in range(T):
    print("Case #%d:"%(i+1))
    R, C, M = [int(z) for z in file.readline().split()]
    m = R * C - M

    s = []
    for j in range(R):
        s.append([])
        for k in range(C):
            s[j].append('*')

    possible = False
    if m == 1:
        possible = True
        s[0][0] = 'c'
    elif (R == 1 or C == 1) and (m > 1 or m == R * C):
        possible = True
        if R == 1:
            for j in range(m):
                s[0][j] = '.'
        elif C == 1:
            for j in range(m):
                s[j][0] = '.'
        s[0][0] = 'c'
    elif (R == 2 or C == 2) and m % 2 == 0 and m // 2 >= 2:
        possible = True
        if R == 2:
            for j in range(m):
                s[j % 2][j // 2] = '.'
        elif C == 2:
            for j in range(m):
                s[j // 2][j % 2] = '.'
        s[0][0] = 'c'

    line = C
    while line > 1 and not possible:
        if m < 2 * line:
            line -= 1
            continue

        left = m % line
        line_count = m // line
        if left > 0:
            line_count += 1
        if line_count > R:
            break

        if left != 1:
            possible = True
            for j in range(m):
                s[j // line][j % line] = '.'
            s[0][0] = 'c'
        else:
            # left 1
            if line_count > 3 and line > 2:
                possible = True
                for j in range(m):
                    s[j // line][j % line] = '.'
                s[line_count-1][1] = '.'
                s[line_count-2][line-1] = '*'
                s[0][0] = 'c'
        line -= 1

    if possible:
        output(s)
    else:
        #print(i+1,"Impossible", R, C, M)
        print("Impossible")
