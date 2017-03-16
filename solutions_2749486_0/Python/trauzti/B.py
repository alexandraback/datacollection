getint = lambda: int(raw_input())
getints = lambda: [int(z) for z in raw_input().split()]

def validate(s, fX, fY):
    x,y = 0,0
    H = {'E' : 1, 'W' : -1}
    V = {'N': 1, 'S' : -1}
    num = 0
    for c in s:
        if c in V:
            y += num * V[c]
        else:
            x += num * H[c]
        num += 1


for t in xrange(1, 1+getint()):
    a,b = getints()
    num = 0
    X, Y = 0,0
    s = ""
    if a > 0:
        while  X < a:
            s += "WE"
            X += 1
    else:
        while a < X:
            s += "EW"
            X -= 1
    if b > 0:
        while  Y < b:
            s += "SN"
            Y += 1
    else:
        while  b < Y:
            s += "NS"
            Y -= 1
        num += 1
    #validate(s, a, b)

    print "Case #%d: %s" % (t, s)

