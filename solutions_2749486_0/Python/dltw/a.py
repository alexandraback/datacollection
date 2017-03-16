f = open('B-small-attempt2.in', 'r')
o = open('B-small-attempt2.out', 'w')

T = int(f.readline().strip())

def check (s):
    x = 0
    y = 0
    pogo = 1;
    for i in range(len(s)):
        if s[i] == "N": y+=pogo
        elif s[i] == "S": y-=pogo
        elif s[i] == "E": x+= pogo
        elif s[i] == "W": x-= pogo
        pogo+=1
    return (x,y)



def nextMove (x, direction):
    res = 1
    goal = abs(x)
    temp = ""
    while (res * res < goal):
        res+=1
    res -=1
    if abs((res+1)*(res+1) - goal) < abs(goal - res * res):
        res += 1
    if (direction == 'x'):
        temp += 'W'*res
        temp += 'E'*res
    else:
        temp += 'S'*res
        temp += 'N'*res
    if (x < 0):
        temp = revs(temp)
    remainder = goal - res* res

    return (temp, remainder)

def genMove (x, direction):
    ans = ""
    newx = x

    while (newx != 0):
        (add, newx) = nextMove (newx,direction)
        ans+=add
    return ans


def revs (s):
    s= s.replace("E","T")
    s= s.replace("W","E")
    s= s.replace("T","W")
    s= s.replace("N","T")
    s= s.replace("S","N")
    s= s.replace("T","S")
    return s

def revx (s):
    s= s.replace("E","T")
    s= s.replace("W","E")
    s= s.replace("T","W")
    return s

def revy (s):
    s= s.replace("N","T")
    s= s.replace("S","N")
    s= s.replace("T","S")
    return s

for t in range(T):
    (x, y) = map(int, f.readline().strip().split(' '))
    modX = abs(x)
    modY = abs(y)
    pogo = 1;
    moves = ""
    while (modX > 0 or modY > 0):
        if (modX < modY):
            if (modX-pogo >=0):
                moves+="E"
                modX -= pogo
                pogo += 1

            elif (modY -pogo >= 0 or pogo - modY < modY - pogo):
                moves+='N'
                modY -= pogo
                pogo += 1
            else:
                break
        else:
            if (modY -pogo >= 0):
                moves+='N'
                modY -= pogo
                pogo += 1
            if (modX-pogo >=0 or pogo - modX < modX - pogo):
                moves+='E'
                modX -= pogo
                pogo += 1
            else:
                break

    # now we are the closest to x and y, we want to write it as sum of squares

    res = moves
    res += genMove(modX,'x')
    res += genMove(modY,'y')
    if (y<0): res = revy(res)
    if (x<0): res = revx(res)

    s = "Case #%d: %s\n" % (t+1, res)
    o.write(s)
    print(s)
o.close()

