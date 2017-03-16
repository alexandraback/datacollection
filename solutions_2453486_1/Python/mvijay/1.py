import numpy

n = int(raw_input(""))
for i in range(0,n):
    b = [ [0] * 4 for k in range(0,4)]

    solved = False
    board_empty = False
    b = [ [0] * 4 for k in range(0,4)]
    tpos = []
    j = 0
    while j < 4:
        inp = raw_input("")
        if inp.strip() == "":
            continue
        for k in range(len(inp)):
            if inp[k] == "X":
                b[j][k] = 1
            if inp[k] == "O":
                b[j][k] = -1
            if inp[k] == "T":
                b[j][k] = 100
                tpos = (j,k)
            if inp[k] == ".":
                board_empty = True
        j += 1
    
    for tval in [-1,1]:
        if tval == 1 and len(tpos) == 0:
            continue
        if solved:
            continue
        if len(tpos) != 0:
            b[tpos[0]][tpos[1]] = tval
            
        s = numpy.sum(b, axis=0)
        for k in range(4):
            if s[k]  == 4:
                if not solved:
                    print "Case #%d: X won"%(i+1)
                solved = True
                continue
            if s[k] == -4:
                if not solved:
                    print "Case #%d: O won"%(i+1)
                solved = True                
                continue
     
        s = numpy.sum(b, axis=1)
        for k in range(4):
            if s[k]  == 4:
                if not solved:
                    
                    print "Case #%d: X won"%(i+1)
                solved = True                
                continue
            if s[k] == -4:
                if not solved:                
                    print "Case #%d: O won"%(i+1)
                solved = True                
                continue
        ds = b[0][0] + b[1][1] + b[2][2] + b[3][3]
        if ds == 4:
            if not solved:
            
                print "Case #%d: X won"%(i+1)
            solved = True            
            continue
        if ds == -4:
            if not solved:            
                print "Case #%d: O won"%(i+1)
            solved = True            
            continue
     
        ds = b[0][3] + b[1][2] + b[2][1] + b[3][0]
        if ds == 4:
            if not solved:            
                print "Case #%d: X won"%(i+1)
            solved = True            
            continue
        if ds == -4:
            if not solved:            
                print "Case #%d: O won"%(i+1)
            solved = True            
            continue
    if not solved:
        if board_empty:
            print "Case #%d: Game has not completed"%(i+1)
        else:
            print "Case #%d: Draw"%(i+1)
        

                
                
