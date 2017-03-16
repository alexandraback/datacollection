import sys
fin = open("inp.in","r")
fout = open("out.txt","w")
N = int(fin.readline())

for n in range(1,N+1):
    M = []
    drawPossible,wonX,wonO = True,False,False
    wonO=wonX=False
    for i in range(4):
        line = map(str,fin.readline().replace('\n',''))
        for spot in line:
            if spot == ".": drawPossible=False
        M.append(line)
        
    diag1 = ''.join(sorted([M[0][0],M[1][1],M[2][2],M[3][3]]))
    diag2 = ''.join(sorted([M[0][3],M[1][2],M[2][1],M[3][0]]))
    if diag1=="XXXX" or diag1=="TXXX" or diag2=="XXXX" or diag2=="TXXX": wonX = True
    if diag1=="OOOO" or diag1=="OOOT" or diag2=="OOOO" or diag2=="OOOT": wonO = True
    for i in range(4):
        row = ''.join(sorted(M[i]))
        if row=="XXXX" or row=="TXXX" or row=="XXXX" or row=="TXXX": wonX = True
        if row=="OOOO" or row=="OOOT" or row=="OOOO" or row=="OOOT": wonO = True
        col = ''.join(sorted([M[0][i],M[1][i],M[2][i],M[3][i]]))
        if col=="XXXX" or col=="TXXX" or col=="XXXX" or col=="TXXX": wonX = True
        if col=="OOOO" or col=="OOOT" or col=="OOOO" or col=="OOOT": wonO = True
        
    t = fin.readline()
    if drawPossible==True:
        if wonO==wonX==False: round = "Draw"
    else:
        if wonO==wonX==False: round = "Game has not completed"
        elif wonO: round= "O won"
        else: round = "X won"
    fout.write( "Case #" + str(n) + ": " + round + "\n")

fin.close()
fout.close()