inp = open("input.txt", "r")
outp = open("output.txt", "w")
dx = [[0, 0, 0, 0], [1, 1, 1, 1], [2, 2, 2, 2], [3, 3, 3, 3], [0, 1, 2, 3], [0, 1, 2, 3], [0, 1, 2, 3], [0, 1, 2, 3], [0, 1, 2, 3], [0, 1, 2, 3]]
dy = [[0, 1, 2, 3], [0, 1, 2, 3], [0, 1, 2, 3], [0, 1, 2, 3], [0, 0, 0, 0], [1, 1, 1, 1], [2, 2, 2, 2], [3, 3, 3, 3], [0, 1, 2, 3], [3, 2, 1, 0]]

mas = [""] * 4
n = int(inp.readline().strip())


for i in xrange(n):
    for j in xrange(4):
        s = inp.readline().strip()
        mas[j] = s
        #print(s)
    #print
    tro = False
    trx = False
    for j in xrange(10):
        tr2o = True
        tr2x = True
        for k in xrange(4):
            #print("\b" + mas[dx[j][k]])
            if(mas[dx[j][k]][dy[j][k]] == "X" or mas[dx[j][k]][dy[j][k]] == "."):
                tr2o = False
            if(mas[dx[j][k]][dy[j][k]] == "O" or mas[dx[j][k]][dy[j][k]] == "."):
                tr2x = False
        ##print("\n")
        if(tr2o):
            #print("@")
            tro = True
        if(tr2x):
            trx = True

    if(tro):
        outp.write("Case #" + str(i + 1) + ": O won\n")
    elif(trx):
        outp.write("Case #" + str(i + 1) + ": X won\n")
    elif("." in mas[0] or "." in mas[1] or "." in mas[2] or "." in mas[3]):
        outp.write("Case #" + str(i + 1) + ": Game has not completed\n")
    else:
        outp.write("Case #" + str(i + 1) + ": Draw\n")

    s = inp.readline()

    #print
