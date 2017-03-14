debug=False
#debug=True

def gcd(a, b):
    if a == b: return a
    while b > 0: a, b = b, a % b
    return a

def distsq((x1,y1),(x2,y2)):
    return (x1-x2)**2+(y1-y2)**2

def sgn(x):
    if (x%2==0): return 1
    return -1

def signterm(val,mul,HW):
    if (mul%2==0): return val
    return (HW-val-1)

for case in range(input()):
    #if case+1==90: debug=True
    print "Case #"+str(case+1)+":",
    H,W,D=map(int,raw_input().split())
    for j in xrange(H):
        row=raw_input()
        if "X" in row:
            y=j
            x=row.index("X")
    H=H-2
    W=W-2
    x=x-1
    y=y-1
    count=0
    skip={}
    if debug: print H,W,x,y,D
    if debug: foobar={}
    for i in xrange(-D/W-1,D/W+2):
        for j in xrange(-D/H-1,D/H+2):
            if (i,j)==(0,0): continue
            (x1,y1)=(i*W+signterm(x,i,W),j*H+signterm(y,j,H))
            if debug:
                if (x1,y1) in skip:
                    foobar[(x1,y1)]=True
            if (x1,y1) in skip: continue
            if distsq((x1,y1),(x,y)) > D**2:
                continue
            if debug:
                print
                print (i,j),(x1,y1),i*W,distsq((x1,y1),(x,y)),gcd(abs(i),abs(j)),
            gcdxy=gcd(abs(x1),abs(y1))
            (x2,y2)=(x1/gcdxy,y1/gcdxy)
            if debug:
                print (x2,y2) in skip, (x2,y2)
            if (x2,y2) in skip: continue
            if debug: foobar[(x1,y1)]=True
            for factor in xrange(1,gcdxy+1):
                skip[(x2*factor,y2*factor)]=True
            count+=1
    if debug:
        grid=[[" " for i in xrange((-D/W-1)*W,(D/W+1)*W)] for j in xrange((-D/H-1)*H,(D/H+1)*H)]
        grid[(D/H+1)*H][(-D/W-1)*W]="0"
        for (a,b) in foobar:
            grid[b+(D/H+1)*H][a+(D/W+1)*W]="-"
        for row in grid:
            print "".join(row)
    print count
