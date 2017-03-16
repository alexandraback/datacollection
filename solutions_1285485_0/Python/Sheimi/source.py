#/usr/bin/env python

man = 0
rect = 0
mirrors = 0
points = []
points_in = {}

def find_true():
    k = [(k, v) for k, v in points_in.items() if v]
    return k

def get_len():
    global man
    k = [k for k, v in points_in.items() if v]
    result = {}
    cxl = lambda x, y: (y - man[1]) * 1.0 / (x - man[0])
    
    for i in k:
        x, y = i
        hx, hy = man
        if x == hx:
            if hy > y:
                result['xup'] = 1
            else:
                result['xdown'] = 1
        elif hy == y:
            if hx > x:
                result['yup'] = 1
            else:
                result['ydown'] = 1
        elif hy > y:
            result[(cxl(x, y), 'up')] = 1
        else:
            result[(cxl(x, y), 'down')] = 1
    return result

def check_point(p, d):
    global man
    p = (int(p[0]), int(p[1]))
    px, py = p
    
    if p in points_in.keys():
        return False

    hx, hy = man
    r = (px - hx) ** 2 + (py - hy) ** 2
    d = d ** 2
    result = d >= r
    if result:
        points.insert(0, p)
        points_in[p] = True
    else:
        points_in[p] = False
    return result 


def find_reflect(p, d):
    x1, x2, y1, y2 = mirrors
    px, py = p
    re = []

    if px > x1:
        r1 = (2*x1-px, py)
        re.append(r1)
    if px < x2:
        r2 = (2*x2-px, py)
        re.append(r2)
    if py > y1:
        r3 = (px, 2*y1-py) 
        re.append(r3)
    if py < y2:
        r4 = (px, 2*y2-py) 
        re.append(r4)
    re = [i for i in re if check_point(i, d)]

def compute(d):
    while points:
        p = points.pop()
        find_reflect(p, d)

def get_input(w, h):
    global man, rect, mirrors, xl
    rect = (w, h)
    mirrors = (0.5, w - 1.5, 0.5, h - 1.5)
    for i in range(h): 
        r = raw_input()
        for index, j in enumerate(r):
            if j == 'X':
                man = (index, i)
                points.append(man)
 
def cal(i):
    i += 1
    r = raw_input().split()
    get_input(int(r[1]), int(r[0]))
    compute(int(r[2]))
    r = len(get_len())
    print "Case #%d: %d" % (i, r)


if __name__ == '__main__':
    i = int(raw_input())
    for x in range(i):
        man = 0
        rect = 0
        mirrors = 0
        points = []
        points_in = {}
        cal(x)

