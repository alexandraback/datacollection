import math

def gcd(a,b):
    x,y = int(math.fabs(a)), int(math.fabs(b))
    if x == 0:
        return y
    if y == 0:
        return x
    while y:
        x, y = y, x % y
    return x

def seen(lst,p):
    """Returns no of elements in lst which are <= p."""
    cnt = 0
    for e in lst:
        if e <= p:
            cnt += 1
    return cnt

# read file
f = open("D-small-attempt0.in", "r")
g = open("D-small-ans0.txt", "w")

N= int(f.readline())  # number of cases
k = 0
while k < N:
    temp = f.readline().split()
    [H,W,D] = [int(e) for e in temp]
    rows = 0
    mirror = []
    # process mirror into a list
    while rows < H:
        temp = (f.readline())[:-1]
        mirror.append(temp)
        if 'X' in temp:
            p, q = rows, temp.index('X')
        rows += 1

    # find distances
    x, y, z, w = p*2-1, q*2-1, (W-q)*2-3, (H-p)*2-3

    masterx = [0]
    t1, t2 = -x, w
    a1, a2 = -w, x
    while t1 >= -D or t2 <= D:
        masterx.append(t1)
        masterx.append(t2)
        t1 += a1
        t2 += a2
        a1, a2 = -a2, -a1

    mastery = [0]
    t1, t2 = -y, z
    a1, a2 = -z, y
    while t1 >= -D or t2 <= D:
        mastery.append(t1)
        mastery.append(t2)
        t1 += a1
        t2 += a2
        a1, a2 = -a2, -a1

    cnt = 0
    maxdist = D*D
    alrseen = {}
    for ix in masterx:
        for iy in mastery:
            if 0 < ix*ix + iy*iy <= maxdist:
                newx, newy = ix/gcd(ix,iy), iy/gcd(ix, iy)
                if (newx, newy) not in alrseen:
                    alrseen[(newx, newy)] = None
                    cnt += 1
    
    g.write("Case #" + str(k+1) + ": " + str(cnt) + "\n")
    k += 1


