
def check(rect,xdim,ydim):
    for x in xrange(xdim):
        for y in xrange(ydim):
            pos_pass = True
            for nx in xrange(xdim):
                if rect[nx][y] > rect[x][y]:
                    pos_pass = False
                    break;
            if pos_pass == False:
                for ny in xrange(ydim):
                    if rect[x][ny] > rect[x][y]:
                        return 'NO'
    return 'YES'

def solve(filename):
    f = open(filename)
    out = open(filename + '.out.txt', 'w')
    n = int(f.readline())
    for i in xrange(n):
        xdim,ydim = map(int,f.readline().split())
        rect = []
        for x in xrange(xdim):
            rect.append(map(int,f.readline().split()))
        out.write('Case #'+str(i+1)+': '+check(rect,xdim,ydim)+'\n')
    f.close()
    out.close()
