import sys

def calcIndex(k,c,i):
    e = [k**x for x in range(c-1,-1,-1)]
    return sum([a*b for a,b in zip(i,e)])+1


f = open(sys.argv[1])
f.readline()
casenum = 1
for l in f:
    K,C,S = [int(x) for x in l.split()]

    indices = range(K)

    C = min(K,C)

    i = 0
    output = []
    while i < len(indices):
        y = indices[i:i+C]
        if len(y) < C:
            y = [0]*(len(y)-C) + y
        output.append(calcIndex(K,C,y))
        i += C

    if len(output) > S:
        output = "IMPOSSIBLE"
    else:
        output = " ".join([str(x) for x in output])

    print "Case #{}: {}".format(casenum,output)
    casenum += 1


