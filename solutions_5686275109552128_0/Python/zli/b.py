mem = {}

def time(P):
    tp = tuple(sorted(P))
    #print tp
    if max(P) == 1:
        return 1
    elif tp in mem:
        return mem[tp]
    else:
        m = mem[tp] = max(P)
        for i in xrange(2, m/2+1):
            newP = P[:]
            newP.remove(m)
            for j in xrange(i-1):
                newP.append(m/i)
            newP.append(m-(i-1)*(m/i))
            mem[tp] = min(mem[tp], time(newP) + (i-1))
        return mem[tp]

for case in range(input()):
    print "Case #"+str(case+1)+":",
    D = int(raw_input())
    P = sorted(map(int,raw_input().split()))
    #print P
    print time(P)
    #print mem
