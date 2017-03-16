def isCorr(t, x, y):
    cp = True
    for i in range(len(t)):
        cp = cp and (t[i][y]  <= t[x][y])
    cp1 = True
    for i in range(len(t[x])):
        cp1 = cp1 and (t[x][i]  <= t[x][y])
    return (cp or cp1)

def getAns(t):
    cans = True
    for i in range(len(t)):
        for j in range(len(t[i])):
            cans = cans and isCorr(t, i, j)
    return (["YES", "NO"][not cans])

if __name__ == "__main__":
    FIN = open("input.txt", "r")
    FOUT = open("output.txt", "w")
    n = list(map(lambda a: list(map(int, a.split())), FIN.readlines()))
    cp = 1
    s = n[0][0]
    for i in range(s):
        h, w = n[cp]
        cp +=1
        print("Case #{0}: ".format(i + 1) + getAns(n[cp: cp + h]), file = FOUT)
        cp += h
    FIN.close()
    FOUT.close()