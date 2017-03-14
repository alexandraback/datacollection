# hall of mirrors.  Google Code Jam April 2012

# small case only.  Hall of mirrors is always a rectangle.

def gcd(a,b):
    if a==0:
        return b
    elif b==0:
        return a
    while b>0:
        a,b = b, a%b
    return a

def reduced(a,b):
    """reduce to lowest terms; preserve signs"""
    if a==0 and b==0:
        return 0,0
    g = gcd( abs(a), abs(b) )
    return a/g, b/g
    

def reflections(grid, r,c, h,w,d):
    """ find reflections only for empty rectangle room for now"""
    # stupid slow algorithm for now; I think I have time.

    d *= 2
    up = 2*r - 1
    down = 2*(h - r) -3
    left = 2*c - 1
    right = 2*(w - c) - 3

    print r,h, up,down
    print c,w, left, right

    delta_r = 2*(up+down)
    delta_c = 2*(left+right)

    rdist = (d + delta_r-1)//delta_r * delta_r
    cdist = (d + delta_c-1)//delta_c * delta_c

    print delta_r, delta_c, d, rdist, cdist

    count = -1  # dont count 0,0
    i = 0
    rlist = range(-2*up,   -2*d,  -delta_r) + range(-rdist, 2*d, delta_r) + range(2*down,  2*d, delta_r)
    clist = range(-2*left, -2*d, -delta_c) +  range(-cdist, 2*d, delta_c) + range(2*right, 2*d, delta_c)
    print rlist
    print clist
    used = set()
    for r0 in rlist:
        for c0 in clist:
            if r0**2 + c0**2 <= d**2:
                r1,c1 = reduced(r0,c0)
                if (r1,c1) not in used:
                    count +=1
                    #print "image at", r0*0.5,c0*0.5
                    used.add( (r1,c1) )
                    
                

    print "count=", count
    return count  


f = open("d-small-attempt0.in", "r")
outf = open("d-small.out", "w")

t = int( f.readline() )
for t1 in range(t):
    h,w,d = map(int, f.readline().split())
    grid = []
    for row in range(h):
        grid.append( f.readline() )
        loc = grid[-1].find('X')
        if loc>0:
            r = len(grid)-1
            c = loc 

    print r,c

    score = reflections(grid, r,c, h,w,d)

    outf.write("Case #" + str(t1+1)+": " + str(score) + "\n")
outf.close()
