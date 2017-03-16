t = input()
for a in xrange(t):
    x,y = map(int,raw_input().split())
    moves = ""
    i = 0
    j = 0
    p = 0

    if x < 0:
        flx = 1
        x = abs(x)
    elif x >= 0:
        flx = 0
        
    if y < 0:
        fly = 1
        y = abs(y)
    elif y >= 0:
        fly = 0
    if x != 0:
        while True:
            p += 1
            i += p
            if i < x:
                if flx == 1:
                    moves += "W"
                else:
                    moves += "E"
            elif i == x:
                if x != 0:
                    if flx == 1:
                        moves += "W"
                    else:
                        moves += "E"
                break
            else:
                i -= 2*p
                if flx == 1:
                    moves += "E"
                else:
                    moves += "W"
    if y != 0:
        while True:
            p += 1
            j += p
            if j < y:
                if fly == 1:
                    moves += "S"
                else:
                    moves += "N"
            elif j == y:
                if y != 0:
                    if fly == 1:
                        moves += "S"
                    else:
                        moves += "N"
                break
            else:
                j -= 2*p
                if fly == 1:
                    moves += "N"
                else:
                    moves += "S"

    print "Case #" + str(a+1) + ": " + moves
