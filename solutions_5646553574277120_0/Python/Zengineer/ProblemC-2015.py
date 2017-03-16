import itertools
data_in = open("C-small-attempt0.in", "r")
data_out = open("Problem.out", "w")

T = int(data_in.readline())

for t in xrange(T):
    data_out.write("Case #%d: "%(t+1))
    #print "Case #%d: "%(t+1)
    args = data_in.readline().split()
    C = int(args[0])
    D = int(args[1])
    V = int(args[2])
    d = [int(x) for x in data_in.readline().split()]
    y = 0

    for v in xrange(1, V+1):
        if v not in d:
            f = False
            c = []
            for e in d:
                if e < v:
                    for i in xrange(C):
                        c.append(e)
            l = len(c)
            for n in xrange(2, l+1):
                p = itertools.combinations(c, n)
                for com in p:
                    if sum(com) == v:
                        f = True
                        break
                if f:
                    break
            if f:
                continue
            d.append(v)
            y += 1
                
    #print
    #print "%d\n"%(y)
    data_out.write("%d\n"%(y))
        

data_in.close()
data_out.close()
