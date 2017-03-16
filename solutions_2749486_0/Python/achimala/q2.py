from collections import defaultdict
from sys import setrecursionlimit

mem = {(0,0,0): ""}
visited = defaultdict(bool)
def f(X, Y):
    try:
        return mem[X, Y]
    except KeyError:
        check = [(0,0)]
        for n in range(1, 501):
            newcheck = set()
            for x,y in check:
                if not visited[x,y]:
                    mem[x,y] = mem[x,y,n-1]
                visited[x,y] = True
                
                if (x,y) == (X,Y):
                    return mem[x,y]
                
                mem[x+n,y,n] = mem[x,y,n-1] + 'E'
                mem[x-n,y,n] = mem[x,y,n-1] + 'W'
                mem[x,y+n,n] = mem[x,y,n-1] + 'N'
                mem[x,y-n,n] = mem[x,y,n-1] + 'S'
                
                for xx,yy in ((x+n,y),(x-n,y),(x,y+n),(x,y-n)):
                    if visited[xx,yy]:
                        mem[xx,yy] = min(mem[xx,yy], mem[xx,yy,n])
                    else:
                        mem[xx,yy] = mem[xx,yy,n]
                newcheck |= {(x+n,y), (x-n,y), (x,y+n), (x,y-n)}
            check = newcheck

def check(s):
    dirs = dict(zip('EWNS', ((1,0),(-1,0),(0,1),(0,-1))))
    n = 1
    x, y = 0, 0
    for d in s:
        dx, dy = dirs[d]
        x += dx*n
        y += dy*n
        n += 1
    return x, y

N = int(raw_input())
for case in range(1,N+1):
    x, y = map(int, raw_input().split())
    print "Case #{}: {}".format(case, f(x, y))