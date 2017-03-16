from sys import stdin

def findmin(lawn):
    sofar = 99999
    idx = (-1, -1)
    for r in range(len(lawn)):
        for c in range(len(lawn[r])):
            if lawn[r][c] < sofar:
                sofar = lawn[r][c]
                idx = (r, c)
    return idx

def const(l):
    return min(l) == max(l)

def constrow(lawn, r):
    return const(lawn[r])

def constcol(lawn, c):
    return const([X[c] for X in lawn])

def deleterow(lawn, r):
    return lawn[:r] + lawn[r+1:]

def deletecol(lawn, c):
    return [X[:c] + X[c+1:] for X in lawn]

C = int(stdin.readline())
for x in range(C):
    (rows, cols) = [int(X) for X in stdin.readline().split()]
    lawn = []
    for y in range(rows):
        lawn.append([int(X) for X in stdin.readline().split()])
    ok = True
    while (rows > 0) and (cols > 0):
        (r, c) = findmin(lawn)
        if constrow(lawn, r):
            lawn = deleterow(lawn, r)
            rows = rows - 1
        elif constcol(lawn, c):
            lawn = deletecol(lawn, c)
            cols = cols - 1
        else:
            ok = False
            break
    print "Case #" + str(x+1) + ": " + ("YES" if ok else "NO")


