f = open("/Users/fernandorenteria/Documents/CodeJam/D-large.in", "r")
inputL = []
for line in f:
    inputL.append(line)

thisline = []   
for i in inputL:
    thisline.append(i.split(" "))
    

def OminousOmio(a):
    win = True
    winner=""
    X = int(a[0])
    R = int(a[1])
    C = int(a[2])
    
    if (X >= 7):
        win = False
    elif (X > R and X > C):
        win = False
    elif (R * C % X != 0):
        win = False
    elif (X + 1) // 2 > min(R, C):
        win = False
    elif X in (1, 2, 3):
        win = True
    elif X == 4:
        win = min(R, C) > 2
    elif X == 5:
        win = not(min(R, C) == 3 and max(R, C) == 5)
    elif X == 6:
        win = min(R, C) > 3
    if win:
        winner = 'GABRIEL'
    else:
        winner = 'RICHARD'
    return winner

  
for i in range(int(inputL[0])):
    arr = []
    for j in range(3):
        arr.append(thisline[i+1][j])
    print'Case #%d:' % (i + 1), OminousOmio(arr)
