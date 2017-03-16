import sys
import copy

def LCS(X, Y, vx, vy):
    m = len(X)
    n = len(Y)
     #An (m+1) times (n+1) matrix
    C = [[0] * (n+1) for i in range(m+1)]
    for i in range(1, m+1):
        for j in range(1, n+1):
            if X[i-1] == Y[j-1]: 
                C[i][j] = C[i-1][j-1] + min(vx[i-1], vy[j-1])
            else:
                C[i][j] = max(C[i][j-1], C[i-1][j])
    return C

#C = None
#X = None
#Y = None
#MEMO = {}
#def LCS(i, j, vx, vy):
    #if i == 0 or j == 0:
        #return 0
    #else:
        #key = (i, j, vx, vy)
        #val = MEMO.get(key, None)
        #if not val is None:
            #return val
        #else:
            #if X[i-1] == Y[j-1]:
                #if vx[i-1] > 0 and vy[j-1] > 0:
                    #m = min(vx[i-1], vy[j-1])
                    #newvx = tuple(x-m if ind == i - 1 else x for (ind,x) in enumerate(vx))
                    #newvy = tuple(y-m if ind == j - 1 else y for (ind,y) in enumerate(vy))
                    #return LCS(i,j,newvx, newvy) + m
            #return max(LCS(i,j-1,vx,vy), LCS(i-1,j,vx,vy))
            #MEMO[key] = z
            #return z
    
def backTrack(C, X, Y, vx, vy, i, j):
    if i == 0 or j == 0:
        return []
    elif X[i-1] == Y[j-1]:
        return backTrack(C, X, Y, vx, vy, i-1, j-1) + [(X[i-1], min(vx[i-1], vy[j-1]))]
    else:
        if C[i][j-1] > C[i-1][j]:
            return backTrack(C, X, Y, vx, vy, i, j-1)
        else:
            return backTrack(C, X, Y, vx, vy, i-1, j)

def case(idx, nn, mm):
    n = nn[1::2]
    m = mm[1::2]
    vn = nn[0::2]
    vm = mm[0::2]
    #global X
    #global Y
    #X = n
    #Y = m
    #MEMO.clear()
    #s = LCS(len(n),len(m),tuple(vn),tuple(vm))
    
    C = LCS(n,m, vn, vm)
    b = backTrack(C, n, m, vn, vm, len(n), len(m))
    s = 0
    for t,c in b:
        s += c
    print "Case #%s: %s" % (idx,s)

lines = open(sys.argv[1]).readlines()
cur_line = 0
T = int(lines[cur_line])
cur_line += 1

for idx in xrange(T):
    cur_line += 1
    nn = [int(x) for x in lines[cur_line].split()]
    cur_line += 1
    mm = [int(x) for x in lines[cur_line].split()]
    cur_line += 1
    case(idx + 1, nn, mm)
