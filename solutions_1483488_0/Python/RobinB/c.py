
def Solve(A,B):
    c = 0
    cache = {}
    aint = int(A)
    bint = int(B)
    if aint < 10:
        return 0

    length = len(A)
    current = aint
    while current <= bint:
        perm = cuts(str(current),aint, bint)

        cache[current] = True
        c0 = 0
        for p in perm:
            if not p in cache:
                c0 = c0 + 1
                cache[p] = True
        c = c + (c0+1)*c0/2
        current = current + 1
        
        while current in cache and current <= bint:
            current = current + 1
    return c


def cuts(c,A,B):
    intc =int(c)
    a = []

    for le in range(1,len(c)):
        new = int(c[le:]+c[:le])
        #
        #print c, new
        if new != intc and A <= new and new <= B and not new in a:
            a.append(new)
            #print "pair!",c, new
    #if len(a) > 0:
    #    a.append(intc)
    return a


        
        




f = open('c.in')
print "start..."
T = int(f.readline())
for t in range(T):
    A,B = f.readline().split()
    #print freq
    result = Solve(A,B)
    print "Case #%d: %s" % (t+1, result)
print "finish!"