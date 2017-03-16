import sys
import math

def gcd(a,b):
    if (a < 0): return gcd(-a,-b)
    if (a == 0): return b
    return a if b == 0 else gcd(b, a % b)


def reflections(H,W,D,x,y):
    r = 0
    x -= 1
    y -= 1
    H -= 2
    W -= 2
    angles = set()
    h = math.ceil(D/H)
    w = math.ceil(D/W)
    for i in range(-(h+1),(h+2)):
        for j in range(-(w+1),(w+2)):
            if i== 0 and j == 0: continue
            xx = i*H + (x if i % 2 == 0 else H-(x+1))
            yy = j*W + (y if j % 2 == 0 else W-(y+1))
            xx -= x
            yy -= y
            if (math.sqrt(xx**2 + yy**2) <= D):
                if xx == 0 or yy == 0:
                    if xx != 0: xx //= abs(xx)
                    if yy != 0: yy //= abs(yy)
                else:
                    d = gcd(xx,yy)
                    xx,yy = xx//d, yy//d
                if (xx,yy) not in angles:
                    #print(((i,j),(xx,yy)))
                    r +=1
                    angles.add((xx,yy))
    return r
    


T=int(sys.stdin.readline())
for i in range(1,T+1):
    H,W,D = [int(x) for x in sys.stdin.readline().split()]
    x = 0
    y = 0
    for r in range(H-1,-1,-1):
        row = sys.stdin.readline().strip()
        for c in range(0,W):
            if row[c] == 'X':
                x = r
                y = c
    print("Case #%s: %s" % (i, reflections(H,W,D,x,y)))
            
    
