def check(t, sb):
    for i in range(4):
        cp = True
        for j in range(4):
            cp = cp and (t[j][i] == sb or t[j][i] == 'T')
        if cp:
            return True
    for i in range(4):
        cp = True
        for j in range(4):
            cp = cp and (t[i][j] == sb or t[i][j] == 'T')
        if cp:
            return True
    cans = True    
    for i in range(4):
        cans = cans and (t[i][i] == sb or t[i][i] == 'T')
    cans1 = True
    for i in range(4):
        cans1 = cans1 and (t[4 - i - 1][i] == sb or t[4 - i - 1][i] == 'T')
    return cans or cans1

def isFull(t):
    for i in range(4):
        if t[i].count("."):
            return False
    return True;

def getAns(t):
    if check(t, 'X'):
        return "X won"
    elif check(t, 'O'):
        return "O won"
    elif isFull(t):
        return "Draw"
    else:
        return "Game has not completed"
    
if __name__ == "__main__":
    FIN = open("input.txt", "r")
    FOUT = open("output.txt", "w")
    n = FIN.readlines()
    s = int(n[0])
    cp = 1
    for i in range(s):
        print("Case #{0}: ".format(i + 1) + getAns(n[cp: cp + 4]), file = FOUT)
        cp += 5
    FIN.close()
    FOUT.close()