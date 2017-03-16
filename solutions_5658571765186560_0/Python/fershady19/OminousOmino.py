f = open("/Users/fernandorenteria/Documents/CodeJam/D-small-attempt0.in", "r")
inputL = []
for line in f:
    inputL.append(line)

thisline = []   
for i in inputL:
    thisline.append(i.split(" "))
    

def OminousOmio(a):
    ans = True
    winner=""
    X = int(a[0])
    R = int(a[1])
    C = int(a[2])
    
    if X >= 7:
        ans = False
    elif X > R and X > C:
        ans = False
    elif R * C % X != 0:
        ans = False
    elif (X + 1) // 2 > min(R, C):
        ans = False
    elif X in (1, 2, 3):
        ans = True
    elif X == 4:
        ans = min(R, C) > 2
    elif X == 5:
        ans = not(min(R, C) == 3 and max(R, C) == 5)
    elif X == 6:
        ans = min(R, C) > 3
    if ans:
        winner = 'GABRIEL'
    else:
        winner = 'RICHARD'
    return winner

  
for i in range(int(inputL[0])):
    arr = []
    for j in range(3):
        arr.append(thisline[i+1][j])
    print'Case #%d:' % (i + 1), OminousOmio(arr)
