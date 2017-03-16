inf = open('input.in')
inp = inf.read().split('\n')
inf.close()

T = int(inp.pop(0))

def Omino(X, R, C):
    if X > 6 or (R*C)%X != 0 or (R<X and C<X) or R < int((X+1)/2) or C < int((X+1)/2):
        res = 0
    elif X < 4 or (R >= X and C >= X):
        res = 1
    else:
        if R*C > 2*X:
            res = 1
        else:
            res = 0
    return res

outf = open('output','w')
for i in range(T):
    x, r, c = [int(x) for x in inp.pop(0).split(' ')]
    outf.write('Case #%d: %s\n'%(i+1,['RICHARD','GABRIEL'][Omino(x,r,c)]))
outf.close()