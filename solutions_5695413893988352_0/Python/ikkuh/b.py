T = int(raw_input())

for i in range(T):
    C, J = raw_input().split()
    
    CC = [C[:]]
    JJ = [J[:]]
    for j in range(len(C)):
        if C[j] == '?':
            newCC = []
            for c in CC:
                newCC.append(c.replace('?', '0', 1))
                newCC.append(c.replace('?', '1', 1))
                newCC.append(c.replace('?', '2', 1))
                newCC.append(c.replace('?', '3', 1))
                newCC.append(c.replace('?', '4', 1))
                newCC.append(c.replace('?', '5', 1))
                newCC.append(c.replace('?', '6', 1))
                newCC.append(c.replace('?', '7', 1))
                newCC.append(c.replace('?', '8', 1))
                newCC.append(c.replace('?', '9', 1))
            CC = newCC
    for j in range(len(C)):
        if J[j] == '?':
            newJJ = []
            for c in JJ:
                newJJ.append(c.replace('?', '0', 1))
                newJJ.append(c.replace('?', '1', 1))
                newJJ.append(c.replace('?', '2', 1))
                newJJ.append(c.replace('?', '3', 1))
                newJJ.append(c.replace('?', '4', 1))
                newJJ.append(c.replace('?', '5', 1))
                newJJ.append(c.replace('?', '6', 1))
                newJJ.append(c.replace('?', '7', 1))
                newJJ.append(c.replace('?', '8', 1))
                newJJ.append(c.replace('?', '9', 1))

            JJ = newJJ

    CC = list(map(int, CC))
    JJ = list(map(int, JJ))

    result = []
    for c in CC:
        for j in JJ:
            result.append((abs(c-j), c, j))
    answer = sorted(result)[0]
    print(("Case #%d: %0"+str(len(C))+"d %0"+str(len(C))+"d") % (i+1, answer[1], answer[2]))

