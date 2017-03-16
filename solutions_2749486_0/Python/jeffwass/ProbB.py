__author__ = 'jeff'

base = "B-small-attempt0"
f = open(base +'.in','r')
fout = open(base +'.out','w')

moves={'N':(0,1), 'S':(0,-1), 'E':(1,0), 'W':(-1,0)}

def jump(points,n):
    global moves
    new_points = {}
    for di,mv in moves.items():
        a=list(map(lambda p: (p[0]+n*mv[0],p[1]+n*mv[1]), points.keys()))
        b=list(map(lambda d: d+di, points.values()))
        new_points.update(dict(zip(a,b)))
    return new_points






num = int(f.readline())
for case in range(1,num+1):
    [x,y]=f.readline()[0:-1].split(' ')
    x=int(x)
    y=int(y)

    points={(0,0):''}
    for n in range(1,1000):
        points = jump(points,n)
        if((x,y) in points):
            break

    out = 'Case #{0}: {1}\n'.format(case,points[(x,y)])
    fout.write(out)
    print((x,y),out)

f.close()
fout.close()


