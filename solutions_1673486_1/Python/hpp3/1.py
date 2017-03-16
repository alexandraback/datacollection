



f = open("A-large.in")
o = open("out.txt", "w")

T = int(f.readline())

def backspace(n):
    return (2*n + (b-a) + 1) + (1-c[a-1-n])*(b+1)

def enter():
    return 2+b

for t in range(1,T+1):
    q = f.readline().split()
    a = int(q[0])
    b = int(q[1])

    p = [float(c) for c in f.readline().split()]
    c = [p[0]]
    #c of success
    for i in xrange(1,a):
        c.append(c[i-1]*p[i])

    n = 0
    m = 2+b
    while 2*n-a < 1:
        bk = backspace(n)
        if bk < m:
            m = bk
        n+=1
    o.write( "Case #%d: %f\n" % (t,m))

    

o.close()
