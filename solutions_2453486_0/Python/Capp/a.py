#!/usr/bin/env python

from sys import stdin


masu = {
    '.' : 0,
    'X' : 1,
    'O' : 2,
    'T' : 3
}

def l_and(list):
    ret = list[0]
    for i in [1,2,3]: ret &= list[i]
    return ret


T = int(stdin.readline())
data = [ [ 0 for i in range(4) ] for j in range(4) ]
#print data # debug

for t in range(T):
    print "Case #%d:" % (t+1),

    ## read
    for i in range(4):
        line = stdin.readline()
        for j in range(4):
            data[i][j] = masu[line[j]]
            pass
        pass
    line = stdin.readline()

    ## debug
    # for i in range(4):
    #     for j in range(4):
    #         print data[i][j],
    #         pass
    #     print
    #     pass
    # print

    ## line check
    test_samples = []
    test_samples.extend([[data[i][j] for j in range(4)] for i in range(4)])    # line
    test_samples.extend([[data[j][i] for j in range(4)] for i in range(4)])    # row
    test_samples.append([data[i][i]   for i in range(4)])  # cross1
    test_samples.append([data[3-i][i] for i in range(4)])  # cross2
    # print test_samples # debug
    check = 0
    for s in test_samples:
        check = l_and(s)
        if(check != 0): break
        pass
    if check == 1:   print "X won"
    elif check == 2: print "O won"
    else:
        check2 = 1
        for (i, j) in [ (ii, jj) for ii in range(4) for jj in range(4)]:
            if data[i][j] == 0:
                check2 = 0
                break
            pass
        if check2 == 0: print "Game has not completed"
        else:           print "Draw"

        pass


    pass

