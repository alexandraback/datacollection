from IOManager import formatInput, readInput, writeOutput
import math

eps = 2**-40

def solve(data):
    
    results = []
    
    for s in data:
        
        t1, t2, t3 = s.split(" ")
        results.append(calc(int(t1),int(t2),int(t3)))
        
    return results


def calc(n1,m1,req):
    
    n = max(n1,m1)
    m = min(n1,m1)
    
    h = n/2.0
    k = m/2.0
    
    if int(h) == h:
        h -= 0.5
    if int(k) == k:
        k -= 0.5
    
    board = [[0 for x in range(n)] for y in range(m)]
    points = [(x,y,(x-h)*(x-h)+(y-k)*(y-k)) for x in range(n) for y in range(m)]
    
    h = n/2.0
    k = m/2.0
    
    pointsInsideCircle = []
    for x,y,d in points:
        if d <= k*k:
            pointsInsideCircle.append((x,y,d))
            board[y][x] = 1
    pointsInsideCircle = sorted(pointsInsideCircle,key=lambda p: p[2])
    
    pointsOutsideCircle = []
    for x,y,d in points:
        if d > k*k:
            try:
                pointsOutsideCircle.append((x,y,(x-h)*(x-h)/(1-(y-k)*(y-k)/(k*k+0.1))))
                board[y][x] = 0
            except ZeroDivisionError:
                print("hmm")
    pointsOutsideCircle = sorted(pointsOutsideCircle,key=lambda p: p[2])
    
    
    board = [[0 for x in range(n)] for y in range(m)]
    g = 0
    while g < req and len(pointsInsideCircle) != 0:
        p = pointsInsideCircle.pop(0)
        board[p[1]][p[0]] = 1
        g += 1
    
    while g < req and len(pointsOutsideCircle) != 0:
        p = pointsOutsideCircle.pop(0)
        board[p[1]][p[0]] = 1
        g += 1
    
    stones = 0
    for y in range(m):
        for x in range(n):
            if board[y][x] == 1:
                if y == m-1 or y == 0 or x == 0 or x == n-1:
                    stones += 1
                elif board[y+1][x] == 0 or board[y-1][x] == 0 or board[y][x+1] == 0 or board[y][x+1] == 0:
                    stones += 1
    
    return str(stones)
            
def inside(x,h,rx,y,k,ry):
    return (x-h)*(x-h)/(rx*rx) + (y-h)*(y-h)/(ry*ry) <= 1

question = "C"
roundNumber = "2C"
name = "small-attempt4"

inputName = question + "-" + name + ".in"
outputName = question + "-" + name + ".out"

testCases, data = readInput(inputName)
writeOutput(solve(data),outputName)


    