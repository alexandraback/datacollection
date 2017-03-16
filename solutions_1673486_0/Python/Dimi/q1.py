f = open("A-small-attempt0.in", "r")
T = int(f.readline())
for X in range(T):
    line = f.readline().strip().split()
    A = int(line.pop(0))
    B = int(line.pop(0))
    line = f.readline().strip().split()
    P = []
    keep = 1
    for p in range(A):
        P.append(float(line.pop(0)))
        keep *= P[p]
    L = []
    L.append( ((B-A)+1)*keep + (1-keep)*(B + (B-A) + 2) )
    P.reverse()
    jOne = (1-P[0])
    i=1
    while i < len(P):
        jOne *= P[i]
        i += 1
    L.append( (keep + jOne)*((B-A) + 2 + 1) + (1-(keep + jOne))*((B-A) + 2 + 1 + B + 1) )
    jTwo = 0
    if A >= 2:
        jOneA = P[0]*(1-P[1])
        i=2
        while i < len(P):
            jOneA *= P[i]
            i+=1
        jOne += jOneA
        jTwo = (1-P[0]) * (1-P[1])
        i=2
        while i < len(P):
            jTwo *= P[i]
            i+=1
        L.append( (keep+jOne+jTwo)*((B-A) + 4 + 1) + (1-(keep+jOne+jTwo))*((B-A) + 4 + 1 + B + 1) ) 
    L.append( (B + 2) )
    L.sort()
    Y = L[0]
    print "Case #%d: %f" % (X+1, Y)