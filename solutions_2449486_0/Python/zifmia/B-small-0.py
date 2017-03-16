# code jam qualifier 2013 problem B

# lawnmower

sXwin = "X won" 
sOwin = "O won"
sDraw = "Draw" 
sPlaying = "Game has not completed"


def result(lawn, n, m):

    row_height = [max(lawn[i]) for i in range(n)]
    col_height = [max([lawn[j][i] for j in range(n)]) for i in range(m)]

    for i in range(n):
        for j in range(m):
            if lawn[i][j] < row_height[i] and lawn[i][j] < col_height[j]:
                return "NO"
    return "YES"


fin = open("B-small-0.in", "r")
fout = open("B-small-0.out", "w")

t = int(fin.readline())
for testCase in xrange(t):
    n,m = map(int, fin.readline().split())
    lawn = []
    for rowNum in range(n):
        lawn.append(map(int, fin.readline().split()))
    
    fout.write( "Case #" + str(testCase+1) + ": " + result(lawn, n,m) + "\n")

fout.close()
