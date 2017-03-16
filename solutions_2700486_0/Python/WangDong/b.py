n = []
x = []
y = []
t = 0

def init():
    f = open('B-small-attempt0.in')
    global n
    global x
    global y
    global t
    t = int(f.readline())
    for i in range(t):
        l0, l1, l2 = f.readline().strip().split()
        n.append(int(l0))
        x.append(int(l1))
        y.append(int(l2))
        
p = 0
d = {}
def work(n, x, y, cur):
    global p
    global d
    if n==0:
        if (x, y) in d:
            p += cur
        return
    
    cx = 0
    cy = 0
    while (cx, cy) in d:
        cy += 2
        
    lx = cx
    ly = cy
    while True:
        if ly == 0 or ((lx - 1, ly - 1) in d and (lx + 1, ly - 1) in d):
            break
        lx -= 1
        ly -= 1
        
    rx = cx
    ry = cy
    while True:
        if ry == 0 or ((rx - 1, ry - 1) in d and (rx + 1, ry - 1) in d):
            break
        rx += 1
        ry -= 1
    
    if cy == 0 or ((cx - 1, cy - 1) in d and (cx + 1, cy - 1) in d):
        d[(cx, cy)] = n
        work(n - 1, x, y, cur)
        del d[(cx, cy)]
    elif (cx - 1, cy - 1) in d:
        d[(rx, ry)] = n
        work(n - 1, x, y, cur)
        del d[(rx, ry)]
    elif (cx + 1, cy - 1) in d:
        d[(lx, ly)] = n
        work(n - 1, x, y, cur)
        del d[(lx, ly)]
    else:
        d[(rx, ry)] = n
        work(n - 1, x, y, cur * 0.5)
        del d[(rx, ry)]
        d[(lx, ly)] = n
        work(n - 1, x, y, cur * 0.5)
        del d[(lx, ly)]


output = open('output.txt', 'w')
init()
for i in range(t):
    p = 0
    d = {}
    work(n[i], x[i], y[i], 1.0)
    output.write("Case #%d: %f\n" % (i + 1, p))
    print p
output.close()
