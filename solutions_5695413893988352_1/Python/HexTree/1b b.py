def big(B):
    return B.replace('?', '9')

def small(B):
    return B.replace('?', '0')

def similar(C, J):
    if C == "":
        return "", ""
    x = C[0]
    y = J[0]
    if x != '?' and y != '?':
        if x == y:
            Ci, Ji = similar(C[1:], J[1:])
            return (x + Ci, y + Ji)
        elif int(x) > int(y):
            return (small(C), big(J))
        elif int(x) < int(y):
            return (big(C), small(J))
    if x == '?' and y == '?':
        tries = []
        tries.append(similar('0' + C[1:], '0' + J[1:]))
        tries.append(similar('0' + C[1:], '1' + J[1:]))
        tries.append(similar('1' + C[1:], '0' + J[1:]))
        minv = int("9" * len(C))
        minarg = -1
        for i in range(len(tries)):
            if abs(int(tries[i][0]) - int(tries[i][1])) < minv:
                minv = abs(int(tries[i][0]) - int(tries[i][1]))
                minarg = i

        return tries[minarg]

    elif x == '?':
        tries = []
        if y != '0':
            tries.append(similar(str(int(y)-1) + C[1:], J))
        tries.append(similar(y + C[1:], J))
        if y != '9':
            tries.append(similar(str(int(y) + 1) + C[1:], J))

        minv = int("9"*len(C))
        minarg = -1
        for i in range(len(tries)):
            if abs(int(tries[i][0]) - int(tries[i][1])) < minv:
                minv = abs(int(tries[i][0]) - int(tries[i][1]))
                minarg = i

        return tries[minarg]

    elif y == '?':
        tries = []
        if x != '0':
            tries.append(similar(C, str(int(x) - 1) + J[1:]))
        tries.append(similar(C, x + J[1:]))
        if x != '9':
            tries.append(similar(C, str(int(x) + 1) + J[1:]))

        minv = int("9" * len(C))
        minarg = -1
        for i in range(len(tries)):
            if abs(int(tries[i][0]) - int(tries[i][1])) < minv:
                minv = abs(int(tries[i][0]) - int(tries[i][1]))
                minarg = i

        return tries[minarg]


with open("data.txt", 'r') as f:
    with open("data1.txt", 'w') as g:
        T = int(f.readline())
        for j in range(T):
            C, J = f.readline().split()
            Cout, Jout = similar(C, J)
            g.write("Case #%d: %s %s\n" % (j+1, Cout, Jout))