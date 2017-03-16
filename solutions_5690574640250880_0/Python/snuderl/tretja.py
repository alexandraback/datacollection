t = int(input())
import copy

def transform(x):
    if x == True:
        return "."
    if x == False:
        return "*"

def display(table, x, y):
    table2 = list([list(map(transform, x)) for x in table])
    table2[x][y] = "c"
    for line in table2:
        print ("".join(line))
        

def solve(x, y, R, C, M, used):
    openCount = [0]
    #print (used, M)

    if(openCount[0] == M): return used
    if(openCount[0] > M): return False
    
    def spread(posX, posY):
        if(posX > 0):
            yield (posX - 1, posY)
        if(posY > 0):
            yield (posX, posY - 1)
        if(posX > 0 and posY > 0):
            yield (posX-1, posY-1)
        if(posX < R - 1):
            yield(posX + 1, posY)
        if(posY < C - 1):
            yield (posX, posY + 1)
        if(posX < R - 1 and posY < C - 1):
            yield (posX + 1, posY + 1)
        if(posX > 0 and posY < C - 1):
            yield (posX - 1, posY + 1)
        if(posX < R - 1 and posY > 0):
            yield (posX + 1, posY -1)


    openedNew = []
    opened = list(spread(x, y))
    for x, y in opened:
        if used[x][y] == False:
            openCount[0] += 1
            used[x][y] = True
            openedNew.append((x, y))
    #print ("after opening, ", used) 
    for x,y in openedNew:
        s = solve(x, y, R, C, M - openCount[0], copy.deepcopy(used))
        if s:
            return s 

    return False
    

for i in range(t):
    r, c, m = map(int, input().split())


    used = list([list([False] * c) for x in range(r)])
    used[0][0] = True
    result = solve(0, 0, r, c, r * c - m - 1, used)
    print ("Case #{}:".format(i + 1))
    if result == False:
        print("Impossible")
    else:
        #print (result)
        display(result, 0, 0)

