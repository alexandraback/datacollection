import sys

maze = []

def printmaze():
    for r in maze:
        print r

def findx():
    for y, row in enumerate(maze):
        for x, c in enumerate(row):
            if c == 'X':
                return x, y
def isEq(a, b):
    return abs(a-b) < 1e-6

def isHalf(a):
    return isEq(abs(a - round(a)), 0.5)

def wall(x, y):
    #print "checking wall %.2f %.2f" % (x, y),
    r = maze[int(round(y))]
    c = r[int(round(x))]
    #print c == '#'
    return c == '#'

def canseeme(x0, y0, dx, dy):
    x = float(x0)
    y = float(y0)
    nsteps = max(abs(dx), abs(dy)) * 2
    goy = abs(dy) >= abs(dx)
    sx = dx / float(nsteps)
    sy = dy / float(nsteps)
    #print "starting from x=%.2f y=%.2f" % (x, y)
    #print "exploring dx=%d dy=%d" % (dx, dy)
    for n in range(1, nsteps+1):
        x += sx
        y += sy
        #print "going to x=%.2f y=%.2f" % (x, y)
        #if not isHalf(x) and not isHalf(y) and wall(x, y):
        #    print "error: entering wall at x=%.2f y=%.2f" % (x, y)
        #    sys.exit(1)
        #print "good"
        if isEq(x, x0) and isEq(y, y0):  # back where we started?
            return True
        if isHalf(x):
            if isHalf(y):
                # messy case where we hit corner...
                wx = wall(x+sx, y-sy)
                wxy = wall(x+sx, y+sy)
                wy = wall(x-sx, y+sy)
                if wx and wxy and wy:
                    sx = -sx
                    sy = -sy # reflect both
                elif wx and wxy:
                    sx = -sx
                elif wy and wxy:
                    sy = -sy
                elif wxy and not wx and not wy:
                    return False  # absorb!
                # in all other cases, let the ray through
            else: # only x is half
                if wall(x+sx, y):
                    sx = -sx # reflect
        else:
            if isHalf(y): # only y is half
                if wall(x, y+sy):
                    sy = -sy # reflect
        # still need to check if enter wall sideways
        if goy and not isHalf(x): # if going mainly in y direction
            #print "checking x sideways"
            if wall(x+sx, y+sy/2):
                rx = 2*(round(x+.5) - (x+.5))
                #print "adjusting x from %.2f to %.2f" % (x, x+rx)
                x += rx # virtual x location in wall
                sx = -sx  # go back out
        if not goy and not isHalf(y): #going mainly in x direction
            #print "checking y sideways"
            if wall(x+sx/2, y+sy):
                ry = 2*(round(y+.5) - (y+.5))
                #print "adjusting y from %.2f to %.2f" % (y, y+ry)
                y += ry # virtual y location in wall
                sy = -sy  # go back out
                
    return False

def locs(d):
    r = []
    for x in range(1, d+1):
        for y in range(1, d+1):
            if x*x + y*y > d*d:
                continue
            repl = False
            for i in range(len(r)):
                a, b = r[i]
                if a*y == b*x and x > a:
                    r[i] = (x, y)
                    repl = True
            if not repl:
                r.append((x, y))
    return r

def solve(d):
    #printmaze()
    x0, y0 = findx()
    #print x0, y0

    n = 0
    # generate possible target locations
    loc = [(0, d), (0, -d), (d, 0), (-d, 0)]
    for dx, dy in locs(d):
        loc.append((dx, dy))
        loc.append((dx, -dy))
        loc.append((-dx, dy))
        loc.append((-dx, -dy))
    #print loc
    for dx, dy in loc:
        if canseeme(x0, y0, dx, dy):
            #print "yes\n"
            n += 1
        else:
            #print "no\n"
            pass
    return n

data = sys.stdin.readlines()
n = int(data[0])
#n = 3
#print n
k = 1
for i in range(1, n+1):
    h, w, d = map(int, data[k].split())
    #print h, w, d
    k += 1
    maze = [x.strip() for x in data[k:k+h]]
    #print maze
    print "Case #%d: %d" % (i, solve(d))
    k += h
