#import re #regex
#import math #math
# math.sqrt(x) -> squre root of x
# math.pow(x, y) -> x ^ y
# math.ceil(math.sqrt(a))


inFile = "C-small-attempt1"
verbose = False
def main():
    if not verbose:
            
        f = open("C:\Users\Peter\Downloads\\" + inFile + ".in", "r")    
        o = open("C:\Users\Peter\Desktop\\" +inFile + ".out", "w")
        n = int(f.readline())

        for x in range(n):
            output(x+1, process(f.readline()[:-1]), o)
    else :
        print process("5 3 10")

def process(line):
    x = [int(n) for n in line.split(" ")]
    r = x[0]
    c = x[1]
    m = x[2]
    spaces = r * c - m
    if spaces == 2 and r != 1 and c != 1:
        return "\nImpossible"
    matrix = genDummy(r,c)
    matrix[0][0] = "."
    success, out = genFinal(matrix, spaces)
    
    if success:
        out[0][0] = "c"
        return stringmap(out)
    else:
        return "\nImpossible"
    
    #return str(r) + " " + str(c) + " " + str(m)


def generate(matrix, spaces):
    print spaces
    numSpaces = 0;
    matrix[0][0] = "."
        
def genFinal(matrix, numSpaces):
    edges, spaces = findEdges(matrix)
    
    if spaces == numSpaces and (numSpaces == 1 or valid(matrix)):
        return True, matrix
    
    if spaces > numSpaces:
        return False, matrix
    
    for edge in edges:
        m = copyMatrix(matrix)
        overlay(m, edge[0], edge[1])
        validRes, resMatrix = genFinal(m,numSpaces)
        if validRes:
            return validRes, resMatrix
    return False, matrix

def findEdges(map):
    edges = []
    spaceCount = 0
    for x in range(len(map)):
        for y in range(len(map[0])):
            if isEdge(map, x, y):
                edges.append((x,y))
            if map[x][y] == ".":
                spaceCount = spaceCount + 1
    return edges, spaceCount
                
def isEdge(map, x, y):
    if map[x][y] =="*":
        return False
    for point in adjPoints:
        if between(x + point[0], 0, len(map)) and between(y+point[1], 0, len(map[0])):
            if map[x + point[0]][y + point[1]] == "*":
                return True
    return False
    

def copyMatrix(matrix):
    return [[y for y in x] for x in matrix ]
    
def overlay(map, x , y):
    for point in adjPoints:
        if between(x + point[0], 0, len(map)) and between(y+point[1], 0, len(map[0])):
            map[x + point[0]][y + point[1]] = "."
    

def nums(matrix):
    out = []
    for x in range(len(matrix)):
        line = []
        for y in range(len(matrix[0])):
            line.append(getNum(matrix, x,y))
        out.append(line)
    return out

def valid(blankMatrix):
    matrix = nums(blankMatrix)
    for x in range(len(matrix)):
        for y in range(len(matrix[0])):
            if not isValid(matrix, x, y):
                return False
    return True
def isValid(map, x, y):
    if map[x][y] == "." or map[x][y] == "*":
        return True
    
    for point in adjPoints:
        if between(x + point[0], 0, len(map)) and between(y+point[1], 0, len(map[0])):
            if map[x + point[0]][y + point[1]] == ".":
                return True
    return False
 
adjPoints = [(-1, 0),(0,-1),(0,1),(1,0),(-1, 1),(-1,-1),(1,1),(1,-1)]
def getNum(map, x, y):
    num = 0
    if map[x][y] == "*":
        return "*"
    
    for point in adjPoints:
        if between(x + point[0], 0, len(map)) and between(y+point[1], 0, len(map[0])):
            if map[x + point[0]][y + point[1]] == "*":
                num = num + 1
    if num == 0:
        return "."
    return num

def between(x, low, high):
    return x >= low and x < high
    

def genDummy(h,w):
    matrix = []
    for x in range(h):
        matrix.append(["*"] * w)
    return matrix
        

def stringmap(map):
    out = ""
    for line in map:
        out = out + "\n"
        for item in line:
            out = out + str(item)
    return out

def output(case, outline, o):
    print "Case #" + str(case) + ": " + str(outline)
    o.write( "Case #" + str(case) + ": " + str(outline) + "\n")
    
if __name__ == "__main__":
    main()