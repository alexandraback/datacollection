f = open("A")
w = open("out",'w')

for t in range(1,int(f.readline())+1):
    board = []
    for i in range(4):
        board.append(f.readline().strip('\n'))

    won = "None"
    dot = 0
    print board

    # Row
    for i in range(4):
        cou = {'X':0, 'O':0, 'T':0, '.':0}
        for j in range(4):
            cou[board[i][j]] += 1
        if cou['X']+cou['T'] == 4:
            won = 'X'
        elif cou['O']+cou['T'] == 4:
            won = 'O'
        dot += cou['.']

    # Col
    for i in range(4):
        cou = {'X':0, 'O':0, 'T':0, '.':0}
        for j in range(4):
            cou[board[j][i]] += 1
        if cou['X']+cou['T'] == 4:
            won = 'X'
        elif cou['O']+cou['T'] == 4:
            won = 'O'

    #Dia1
    cou = {'X':0, 'O':0, 'T':0, '.':0}
    for i in range(4):
        cou[board[i][i]] += 1
    if cou['X']+cou['T'] == 4:
        won = 'X'
    elif cou['O']+cou['T'] == 4:
        won = 'O'

    #Dia 2
    cou = {'X':0, 'O':0, 'T':0, '.':0}
    for i in range(4):
        cou[board[i][3-i]] += 1
    if cou['X']+cou['T'] == 4:
        won = 'X'
    elif cou['O']+cou['T'] == 4:
        won = 'O'

    if won != 'None':
        print 'Case #'+str(t)+': '+won+' won'
        w.write('Case #'+str(t)+': '+won+' won\n')
    elif dot == 0:
        print 'Case #'+str(t)+': Draw'
        w.write('Case #'+str(t)+': Draw\n')
    else:
        print 'Case #'+str(t)+': Game has not completed'
        w.write('Case #'+str(t)+': Game has not completed\n')

    f.readline()

f.close()
w.close()