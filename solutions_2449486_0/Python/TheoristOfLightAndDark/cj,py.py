f = open("A")
w = open("out",'w')

for t in range(1,int(f.readline())+1):
    strl = f.readline().strip('\n').split()
    n = int(strl[0])
    m = int(strl[1])

    board = []
    for i in range(n):
        board.append(map(int,f.readline().strip('\n').split()))
    boardT = zip(*board)

    maxr = map(max,board)
    maxc = map(max,boardT)

    win = True
    for i in range(n):
        for j in range(m):
            win = win and (board[i][j] == maxr[i] or board[i][j] == maxc[j])

    mmap = {True:'YES', False:'NO'}
    print 'Case #'+str(t)+': '+mmap[win]
    w.write('Case #'+str(t)+': '+mmap[win]+'\n')

f.close()
w.close()