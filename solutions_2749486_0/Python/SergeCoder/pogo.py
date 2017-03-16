#!/usr/bin/python2

def readf(f):
    rline = lambda : [int(v) for v in f.readline().split(' ')]
    return rline()

def walk(path):
    x, y = 0, 0
    d = 1
    for c in path:
        if c == 'N': y += d
        elif c == 'S': y -= d
        elif c == 'E': x += d
        elif c == 'W': x -= d
        else: print "error"
        d += 1
    return x, y
        
def test(pos):
    x, y = pos
    path = ""
    if x != 0:
        if x > 0:
            path = "E" + "WE" * (x - 1)
        else:
            path = "W" + "EW" * (-1 - x)
    vert = ""
    if y != 0:
        if y > 0:
            vert = "SN" * y
        else:
            vert = "NS" * (0 - y)
    ans = path + vert
    nx, ny = walk(ans)
    if nx != x or ny != y:
        print "error at ", x , y, " we at ", nx, ny
    return ans
    
if __name__=="__main__":
    f = file("pogo.case");
    t = int(f.readline())
    for i in range(t):
        print "Case #%d:" % (i + 1), test(readf(f))
