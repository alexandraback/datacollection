from datetime import datetime

def gcd(a, b):
    a = a > 0 and a or -a
    b = b > 0 and b or -b
    if a > b:
        return gcd(b, a)
    if a == 0:
        return b
    return gcd(b%a, a)


def reduce(a, b):
    if a == 0 and b == 0: return (0, 0)
    #if a == 0: return (0, 1)
    #if b == 0: return (1, 0)
    g = gcd(a, b)
    return (a/g, b/g)


class Num:
    def __init__(self, up, down=1):
        assert isinstance(down, int)
        if isinstance(up, int):
            self.up = up
            self.down = down
        else:
            assert isinstance(up, Num)
            tmp = up / down
            self.up = tmp.up
            self.down = tmp.down

    def reduce(self):
        self.up, self.down = reduce(self.up, self.down)
        return self

    def __hash__(self):
        return (self.up * 79 + self.down) ^ (self.down >> 3)

    def __str__(self):
        return str(self.up) + '/' + str(self.down)

    def __add__(self, other):
        common_down = self.down * other.down
        common_up = self.up * other.down + other.up * self.down
        common_up, common_down = reduce(common_up, common_down)
        return Num(common_up, common_down)

    def __sub__(self, other):
        common_down = self.down * other.down
        common_up = self.up * other.down - other.up * self.down
        common_up, common_down = reduce(common_up, common_down)
        return Num(common_up, common_down)

    def __mul__(self, other):
        if isinstance(other, int):
            return self.__mul__(Num(other))
        return Num(self.up * other.up, self.down * other.down)

    def __div__(self, other):
        if isinstance(other, int):
            assert other != 0
            return Num(self.up, self.down * other)
        else:
            assert self.down * other.up != 0
            return Num(self.up * other.down, self.down * other.up)

    def __lt__(self, other):
        if isinstance(other, int):
            return self.__lt__(Num(other))
        self.sanitise()
        other.sanitise()
        return self.up * other.down < other.up * self.down

    def __eq__(self, other):
        if isinstance(other, int):
            return self.__eq__(Num(other))
        return self.up * other.down == other.up * self.down

    def __le__(self, other):
        return self.__lt__(other) or self.__eq__(other)

    def is_int(self):
        return self.up % self.down == 0

    def ceil(self):
        if self.is_int():
            return self.up / self.down
        else:
            return self.up / self.down + 1

    def floor(self):
        if self.is_int():
            return self.up / self.down
        else:
            return self.up / self.down - 1

    def sanitise(self):
        if self.down < 0:
            self.down = -self.down
            self.up = -self.up

        
class Point:
    def __init__(self, i, j):
        if isinstance(i, int):
            i = Num(i)
        if isinstance(j, int):
            j = Num(j)
        assert isinstance(i, Num)
        assert isinstance(j, Num)
        self.i = i
        self.j = j

    def __str__(self):
        return '(' + str(self.i) + ', ' + str(self.j) + ')'

    def dist2(self, other):
        h = self.i - other.i
        ww = self.j - other.j
        return h * h + ww * ww

    def __eq__(self, other):
        if self.i == other.i and self.j == other.j: return True
        if self.i == other.j and self.j == other.i: return True
        return False

    def __hash__(self):
        return hash(self.i) * 73 + hash(self.j)

    def reduce(self):
        self.i.reduce()
        self.j.reduce()
        return self
        

class Line:
    def __init__(self, a, b):
        assert isinstance(a, Point)
        assert isinstance(b, Point)
        self.a = a
        self.b = b

    def intersect(self, other, inclusive=False):
        x11, y11, x12, y12 = Num(self.a.i), Num(self.a.j), Num(self.b.i), Num(self.b.j)
        A1 = y12 - y11
        B1 = x11 - x12
        C1 = A1 * x11 + B1 * y11

        x21, y21, x22, y22 = Num(other.a.i), Num(other.a.j), Num(other.b.i), Num(other.b.j)
        A2 = y22 - y21
        B2 = x21 - x22
        C2 = A2 * x21 + B2 * y21

        # A1B2x - A2B1x = B2C1 - B1C2
        det = A1*B2 - A2*B1
        x = (B2*C1 - B1*C2) / det
        y = (A1*C2 - A2*C1) / det

        if not x11 < x12: x11, x12 = x12, x11
        if not y11 < y12: y11, y12 = y12, y11
        if not x21 < x22: x21, x22 = x22, x21
        if not y21 < y22: y21, y22 = y22, y21


        if x == x21 or x == x22 or y == y21 or y == y22:
            return None

        if not inclusive and ((self.get_type() == 'V' and (x == x11 or x == x12)) or (self.get_type() == 'H' and (y == y11 or y == y12))):
            return None

        if x < x11 or x12 < x or x < x21 or x22 < x or y < y11 or y12 < y or y < y21 or y22 < y:
            return None

        return Point(x, y)

    def __str__(self):
        return str(self.a) + '-' + str(self.b)

    def __eq__(self, other):
        if self.a == other.a and self.b == other.b: return True
        if self.a == other.b and self.b == other.a: return True
        return False

    def __hash__(self):
        return (hash(self.a) * 37) ^ hash(self.b)


class Mirror(Line):
    def __init__(self, a, b):
        Line.__init__(self, a, b)

    def get_type(self):
        if self.a.i == self.b.i:
            return 'H'
        if self.a.j == self.b.j:
            return 'V'
        assert False

    def __str__(self):
        return Line.__str__(self)

    def __eq__(self, other):
        return Line.__eq__(self, other)
        

def find_origin(maze, myself):
    for i in range(len(maze)):
        for j in range(len(maze[0])):
            if maze[i][j] == myself:
                return Num(i*2+1, 2), Num(j*2+1, 2)


def transform_maze(maze):
    maze = maze[1:-1]
    maze = [s[1:-1] for s in maze]
    return maze


def get_mirrors(maze, mirror):
    h = len(maze)
    w = len(maze[0])

    horizontal_mirror = set()
    vertical_mirror = set()
    for i in range(h):
        for j in range(w):
            if maze[i][j] == mirror:
                if i-1 >= 0 and maze[i-1][j] != mirror:
                    horizontal_mirror.add(Mirror(Point(i, j), Point(i, j+1)))
                if i+1 < h and maze[i+1][j] != mirror:
                    horizontal_mirror.add(Mirror(Point(i+1, j), Point(i+1, j+1)))
                if j-1 >= 0 and maze[i][j-1] != mirror:
                    vertical_mirror.add(Mirror(Point(i, j), Point(i+1, j)))
                if j+1 < w and maze[i][j+1] != mirror:
                    vertical_mirror.add(Mirror(Point(i, j+1), Point(i+1, j+1)))

    for j in range(w):
        horizontal_mirror.add(Mirror(Point(0, j), Point(0, j+1)))
        horizontal_mirror.add(Mirror(Point(h, j), Point(h, j+1)))
    for i in range(h):
        vertical_mirror.add(Mirror(Point(i, 0), Point(i+1, 0)))
        vertical_mirror.add(Mirror(Point(i, w), Point(i+1, w)))
    return horizontal_mirror, vertical_mirror

def dun(a, b, c):
    Dab = a.dist2(b)
    Dac = a.dist2(c)
    Dbc = b.dist2(c)

    return Dab + Dbc < Dac

def solve(maze, xo, yo, x, y, all_mirror, horizontal_mirror, vertical_mirror):
    Pa = Point(xo, yo)
    Pb = Point(x, y)
    #print list(map(str, all_mirror))
#    print list(map(str, horizontal_mirror))
#    print list(map(str, vertical_mirror))
    #print 'search', x, y
    cnt = 0
    while 'SolveIT software':
        cnt += 1
        #xd = x > xo and 1 or -1
        #yd = y > yo and 1 or -1
        #print 'show', Pa, Pb
        #print 'cnt', cnt

        L = Line(Pa, Pb)

        intersectP = None #
        mirror = None
        for line in all_mirror:
            p = line.intersect(L, False)
            if not p:
                continue
            elif not intersectP or Pa.dist2(p) < Pa.dist2(intersectP):
                intersectP = p
                mirror = line
        intersectP2h = None #
        mirrorH = {}
        cnth = {}
        for line in horizontal_mirror:
            p = line.intersect(L, True)
            if not p:
                continue
            elif p == line.a or p == line.b:
                if p not in cnth:
                    cnth[p] = 0
                cnth[p] = cnth[p] + 1
                if p not in mirrorH:
                    mirrorH[p] = []
                mirrorH[p].append(line)
        for p in cnth.iterkeys():
            if cnth[p] < 2: continue
            if intersectP2h is None or Pa.dist2(p) < Pa.dist2(intersectP2h):
                intersectP2h = p
        intersectP2v = None #
        mirrorV = {}
        cntv = {}
        for line in vertical_mirror:
            p = line.intersect(L, True)
            if not p:
                continue
            elif p == line.a or p == line.b:
                if p not in cntv:
                    cntv[p] = 0
                cntv[p] = cntv[p] + 1
                if p not in mirrorV:
                    mirrorV[p] = []
                mirrorV[p].append(line)
        for p in cntv.iterkeys():
            if cntv[p] < 2: continue
            if intersectP2v is None or Pa.dist2(p) < Pa.dist2(intersectP2v):
                intersectP2v = p

        if intersectP2h is not None and (intersectP is None or Pa.dist2(intersectP2h) < Pa.dist2(intersectP)):
            intersectP = intersectP2h
            mirror = mirrorH[intersectP2h][0]
        if intersectP2v is not None and (intersectP is None or Pa.dist2(intersectP2v) < Pa.dist2(intersectP)):
            intersectP = intersectP2v
            mirror = mirrorV[intersectP2v][0]

        #print 'inter', intersectP

        vertical_intersects = set()
        horizontal_intersects = set()
        corner_mirrors = {}
        for line in horizontal_mirror:
            p = line.intersect(L, True)
            
            if not p:
                continue
            elif p == line.a or p == line.b:
                p.reduce()
                horizontal_intersects.add(p)
                if p not in corner_mirrors:
                    corner_mirrors[p] = []
                corner_mirrors[p].append(line)
#                print 'wow'
        for line in vertical_mirror:
            p = line.intersect(L, True)
            if not p:
                continue
            elif p == line.a or p == line.b:
                p.reduce()
                vertical_intersects.add(p)
                if p not in corner_mirrors:
                    corner_mirrors[p] = []
                corner_mirrors[p].append(line)
#                print 'wow'

        horizontal_intersects = set([a.reduce() for a in horizontal_intersects])
        vertical_intersects = set([a.reduce() for a in vertical_intersects])
        filtered_h = [a.reduce() for a in filter(lambda x: cnth[x] == 2, cnth.iterkeys())]
        filtered_v = [a.reduce() for a in filter(lambda x: cntv[x] == 2, cntv.iterkeys())]
        #print map(str, horizontal_intersects & vertical_intersects)
        #print map(str, filtered_v), map(str, filtered_h), map(str, cnth.iterkeys()), map(str, cntv.iterkeys())
        intersect_of_intersects = (horizontal_intersects & vertical_intersects)# - set(filtered_v) - set(filtered_h)
        #print 'inter inter', map(str, intersect_of_intersects)
        corner_intersect = None
        for i in intersect_of_intersects:
            if len(corner_mirrors[i]) == 4: continue
            got_mirrors = corner_mirrors[i]
            other = []
            for m in got_mirrors:
                if not m.a == i:
                    other.append(m.a)
                if not m.b == i:
                    other.append(m.b)

            outward = 0
            inward = 0
            for p in other:
                if dun(Pa, i, p):
                    outward += 1
                else:
                    inward += 1

            if outward == inward:
                continue

            if corner_intersect is None or Pa.dist2(i) < Pa.dist2(corner_intersect):
                corner_intersect = i
        #print 'corner', corner_intersect


        if not intersectP and not corner_intersect:
            break

        if intersectP is not None and corner_intersect is not None and intersectP == corner_intersect:
            intersectP = None
        if intersectP is not None and (corner_intersect is None or Pa.dist2(intersectP) < Pa.dist2(corner_intersect)):
            if mirror.get_type() == 'H':
                x = intersectP.i * 2 - x
            elif mirror.get_type() == 'V':
                y = intersectP.j * 2 - y
            Pa = intersectP
            Pb = Point(x, y)
        if corner_intersect is not None and (intersectP is None or Pa.dist2(corner_intersect) < Pa.dist2(intersectP)):
            got_mirrors = corner_mirrors[i]
            other = []
            for m in got_mirrors:
                if not m.a == i:
                    other.append(m.a)
                if not m.b == i:
                    other.append(m.b)

            outward = 0
            inward = 0
            for p in other:
                if dun(Pa, i, p):
                    outward += 1
                else:
                    inward += 1
            if outward > inward:
                #print corner_intersect, Pa, Pb
                #print 'ward', inward, outward
                return None

            x = corner_intersect.i * 2 - x
            y = corner_intersect.j * 2 - y
            Pa = corner_intersect
            Pb = Point(x, y)


    return x == xo and y == yo


def cal_straight(maze, xo, yo, mirror, D):
    h = len(maze)
    w = len(maze[0])
    xo = xo.up / xo.down
    yo = yo.up / yo.down
    ret = 0
#up
    tx, ty = xo, yo
    while tx >= 0 and maze[tx][ty] != mirror: tx -= 1
    if (xo - tx) * 2 - 1 <= D: ret += 1
#down
    tx, ty = xo, yo
    while tx < h and maze[tx][ty] != mirror: tx += 1
    if (tx - xo) * 2 - 1 <= D: ret += 1
#left
    tx, ty = xo, yo
    while ty >= 0 and maze[tx][ty] != mirror: ty -= 1
    if (yo - ty) * 2 - 1 <= D: ret += 1
#right
    tx, ty = xo, yo
    while ty < w and maze[tx][ty] != mirror: ty += 1
    if (ty - yo) * 2 - 1 <= D: ret += 1

    return ret

def heihei():
    filename = 'D-small-attempt0.in'
    #filename = 'D-sample.in'
    alltime = None
    f = open(filename)
    T = int(f.readline()[:-1])
    for t in range(T):
        start = datetime.now()
        H, W, D = map(int, f.readline().split())
        maze = [f.readline()[:-1] for i in range(H)]
        maze = transform_maze(maze)
        
        horizontal_mirror, vertical_mirror = get_mirrors(maze, '#')
        all_mirror = horizontal_mirror | vertical_mirror
        #for m in all_mirror:
        #    print m
       # while 1: continue
        xo, yo = find_origin(maze, 'X')
        ans = cal_straight(maze, xo, yo, '#', D)
        s = set()
        for xx in range(1, D+1):
            for yy in range(1, D+1):
                if xx * xx + yy * yy > D * D: continue
                for xd in [-1, 1]:
                    for yd in [-1, 1]:
                        if reduce(xx*xd, yy*yd) in s: continue
                        x = xo + Num(xx * xd)
                        y = yo + Num(yy * yd)
                        if solve(maze, Num(xo), Num(yo), Num(x), Num(y), all_mirror, horizontal_mirror, vertical_mirror):
                            ans += 1
                            s.add(reduce(xx*xd, yy*yd))

        print 'Case #%d: %d' % (t+1, ans)
        end = datetime.now()
        if alltime == None: alltime = end - start
        else: alltime = alltime + end-start
        print end - start, alltime


#################################### All of The above code is useless, Don't Laugh!! ###########################################


T = input()
for t in range(T):
    H, W, D = map(int, raw_input().split())
    maze = [raw_input() for i in range(H)]
    maze = transform_maze(maze)
    H -= 2
    W -= 2
    xo, yo = find_origin(maze, 'X')
    #print 'origin', xo, yo
    x1, y1 = xo, Num(W + W) - yo
    x2, y2 = Num(H + H) - xo, yo
    x3, y3 = Num(H + H) - xo, Num(W + W) - yo
    xs = [xo, x1, x2, x3]
    ys = [yo, y1, y2, y3]
    ans = 0
    s = set()
    for h in range(0, 100, H+H):
        for w in range(0, 100, W+W):
            for hd in [1, -1]:
                for wd in [1, -1]:
                    hh, ww = h * hd, w * wd

                    for i in range(len(xs)):
                        xx, yy = xs[i], ys[i]
                        x, y = xx + Num(hh), yy + Num(ww)
                        delX, delY = (x - xo).reduce().up, (y - yo).reduce().up
                        if delX * delX + delY * delY > D * D: continue
                        #print delX, delY, reduce(delX, delY), xx, yy, x, y
                        if reduce(delX, delY) in s: continue
                        if delX ** 2 + delY ** 2 <= D ** 2:
                            #print x, y
                            ans += 1
                        s.add(reduce(delX, delY))


    print 'Case #%d: %d' % (t+1, ans-1)
