fin = open('tictac.in').read()[2:].strip().split('\n\n')
fout = open('tictac.out','w')
def pp(s):#print end case
    print 'Case #%d: ' % (cnt) +s
    fout.write('Case #%d: ' % (cnt) +s+'\n')
    
cnt=0
for game in fin:
    cnt+=1
    rows = game.split('\n')
    cont = False
    for r in rows:
        os = r.count('O')
        xs = r.count('X')
        ts = r.count('T')
        if os==4 or os==3 and ts==1:
            pp('O won')
            cont = True
            break
        elif xs==4 or xs==3 and ts==1:
            pp('X won')
            cont = True
            break
    if cont:
        continue
    cols = zip(*rows)
    for r in cols:
        os = r.count('O')
        xs = r.count('X')
        ts = r.count('T')
        if r.count('O')==4 or r.count('O')==3 and r.count('T')==1:
            pp('O won')
            cont = True
            break
        elif r.count('X')==4 or r.count('X')==3 and r.count('T')==1:
            pp('X won')
            cont=True
            break
    if cont:
        continue
    leftDiag = [
        [0,0],
        [1,1],
        [2,2],
        [3,3]
    ]
    rightDiag = [
        [0,3],
        [1,2],
        [2,1],
        [3,0]
    ]
    left = []
    for pos in leftDiag:
        left.append(cols[pos[0]][pos[1]])
        
    right = []
    for pos in rightDiag:
        right.append(cols[pos[0]][pos[1]])
    
    osL = left.count('O')
    xsL = left.count('X')
    tsL = left.count('T')
    
    osR = right.count('O')
    xsR = right.count('X')
    tsR = right.count('T')
    
    if osL==4 or osL==3 and tsL==1:
        pp('O won')
        continue
    elif xsL==4 or xsL==3 and tsL==1:
        pp('X won')
        continue
        
    if osR==4 or osR==3 and tsR==1:
        pp('O won')
        continue
    elif xsR==4 or xsR==3 and tsR==1:
        pp('X won')
        continue
    
    for r in cols:
        if r.count('.') > 0:
            pp('Game has not completed')
            break
    else:
        pp('Draw')
fout.close()