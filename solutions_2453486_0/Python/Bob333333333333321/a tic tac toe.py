def status(board):
    origBoard = board[:]
    winners = []
    if xWin(board):
        res = "X won"
    elif oWin(board):
        res = "O won"
    elif unfull(board):
        res = "Game has not completed"
    else:
        res = "Draw"
    return res

def convertToArr(board): # not in use
    res = [board[0:4], board[4:8], board[8:12], board[12:16]]
    return res

def unfull(board):
    for i in board:
        if i.count("."):
            return True
    return False

def xWin(board):
    for i in board:
        if i.count("X") + i.count("T") == 4:
            return True
    k = [board[0][0], board[1][1], board[2][2], board[3][3]]
    if k.count("T") + k.count("X") == 4:
        return True
    k = [board[3][0], board[2][1], board[1][2], board[0][3]]
    if k.count("T") + k.count("X") == 4:
        return True
    for i in range(4):
        k = []
        for j in range(4):
            k.append(board[j][i])
        if k.count("T") + k.count("X") == 4:
            return True
    return False

def oWin(board):
    for i in board:
        if i.count("O") + i.count("T") == 4:
            return True
    k = [board[0][0], board[1][1], board[2][2], board[3][3]]
    if k.count("T") + k.count("O") == 4:
        return True
    k = [board[3][0], board[2][1], board[1][2], board[0][3]]
    if k.count("T") + k.count("O") == 4:
        return True
    for i in range(4):
        k = []
        for j in range(4):
            k.append(board[j][i])
        if k.count("T") + k.count("O") == 4:
            return True
    return False

def getBoardsFromFile(path = r'C:\Python32\google code jam 2013\qualification round\a_small.txt'):
    reader = open(path)
    data = reader.readlines()
    for i in range(len(data)):
        if data[i][-1] == "\n":
            data[i] = data[i][:-1]
    reader.close()
    numCases = (len(data)) // 5
    output = ""
    for i in range(numCases):
        frstLineIndx = 5 * i + 1
        caseArr = []
        for j in range(4):
            caseArr.append(data[frstLineIndx + j])
        output += "Case #" + str(i + 1) + ": " + status(caseArr) + "\n"
    output = output[:-1]
    print(output)
getBoardsFromFile()
