def xl(l):
    return xrange(len(l))

for case in range(input()):
    print "Case #"+str(case+1)+":",
    table = []
    if case>0:
        raw_input()
    for i in xrange(4):
        table.append(raw_input())
    #print table
    wins = [[(i,j) for i in xrange(4)] for j in xrange(4)]
    wins += [[(j,i) for i in xrange(4)] for j in xrange(4)]
    wins += [[(i,i) for i in xrange(4)]]
    wins += [[(3-i,i) for i in xrange(4)]]
    winner = None
    for win in wins:
        #print win,table[3],table[3][0]
        vals = [table[c[0]][c[1]] for c in win]
        if all(v in "XT" for v in vals):
            print "X won"
            winner = "X"
            break
        elif all(v in "OT" for v in vals):
            print "O won"
            winner = "O"
            break
    if not winner:
        if "." in "".join(table):
            print "Game has not completed"
        else:
            print "Draw"
