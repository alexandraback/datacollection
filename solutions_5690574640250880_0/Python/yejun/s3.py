import sys
import array

sys.setrecursionlimit(1000000)

f = open(sys.argv[1]) if len(sys.argv)>1 else sys.stdin

total = int(f.readline().strip())

MINE = ord('*')
CLICK = ord('c')
CLEAR = ord('.')

def output(b, R, C):
    for i in range(R):
        print(repr(b[i*C:(i+1)*C].tostring())[2:-1])

def flip(b, R, C, x, y):
    if x >= 0 and x < R and y >= 0 and y < C:
        if b[x*C+y] == MINE:
            b[x*C+y] = CLEAR
            return 1
    return 0

def clearmine(b, R, C, x, y):
    return (flip(b, R, C, x-1, y-1)+
            flip(b, R, C, x, y-1)+
            flip(b, R, C, x+1, y-1)+
            flip(b, R, C, x-1, y)+
            flip(b, R, C, x, y)+
            flip(b, R, C, x+1, y)+
            flip(b, R, C, x-1, y+1)+
            flip(b, R, C, x, y+1)+
            flip(b, R, C, x+1, y+1)) 


def nearz(z, R, C, x, y):
    def isz(a, b):
        if a >= 0 and a < R and b >= 0 and b < C:
            return z[a*C+b] == 1
        return 0
    return (isz(x-1, y-1) or
            isz(x, y-1) or
            isz(x+1, y-1) or
            isz(x-1, y) or
            isz(x+1, y) or
            isz(x-1, y+1) or
            isz(x, y+1) or
            isz(x+1, y+1))

def play(b, z, R, C, m, M):
    bc = array.array('b', b)
    for i in range(R*C):
           if z[i]:
               m -= clearmine(bc, R, C, i // C,  i % C)
    if m == M:
        return bc
    if m < M:
        return None
    for i in range(R*C):
        if z[i] == 0 and nearz(z, R, C, i // C, i % C):
            z[i] = 1
            r = play(bc, z, R, C, m, M)
            if r:
                return r
            z[i] = 0

def solve(R, C, M):
    b = array.array('b', [MINE]*(R*C))
    if R*C - M == 1:
        b[0] = CLICK
        return b
    z = array.array('b', [0]*(R*C))
    for i in range(R*C):
        z[i] = 1
        r = play(b, z, R, C, R*C, M)
        if r:
            r[i] = CLICK
            return r
        z[i] = 0
    return None

for i in range(total):
    print("Case #%d: " % int(i+1))
    R, C, M = [int(j) for j in f.readline().strip().split()]
    r = solve(R, C, M)
    if r:
        output(r, R, C)
    else:
        print("Impossible") 
