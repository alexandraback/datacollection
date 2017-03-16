input = open(file = 'input', mode = 'r')
output = open(file = 'output', mode = 'w')

def check(c, S):
    for i in range(4):
        if S[i].count(c) == 4:
            return True
    for j in range(4):
        amount = 0
        for i in range(4):
            amount += int(S[i][j] == c)
        if amount == 4:
            return True
    H1 = [S[0][0], S[1][1], S[2][2], S[3][3]]
    H2 = [S[0][3], S[1][2], S[2][1], S[3][0]]
    return H1.count(c) == 4 or H2.count(c) == 4     
    
def f():
    S = []
    for i in range(4):
        S.append(list(input.readline().rstrip()))
    input.readline()
    x, y = -1, -1
    for i in range(4):
        for j in range(4):
            if S[i][j] == 'T':
                x, y = i, j
    if x != -1:
        S[x][y] = 'X'
    if check('X', S):
        output.write("X won" + "\n")
        return
    if x != -1:
        S[x][y] = 'O'
    if check('O', S):
        output.write("O won" + "\n")
        return
    amount = 0
    for i in range(4):
        amount += S[i].count('.')
    if(amount == 0):
        output.write("Draw" + "\n")
        return
    output.write("Game has not completed" + "\n")
    return
    

n = int(input.readline().rstrip())
for i in range(n):
    output.write("Case #" + str(i + 1) + ": ")
    f()
