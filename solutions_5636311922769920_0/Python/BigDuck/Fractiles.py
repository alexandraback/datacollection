with open("input") as f:
    x = f.read().splitlines()

nOfCase = int(x[0])
testCases = x[1:]

def position(x,layer):
    if layer == 0:
        return x+1
    else:
        return position(x,layer-1) + (K**layer) * x

for i,a in enumerate(testCases):
    K,C,S = (int(x) for x in a.split())
    #print K,C,S
    lst = []
    for j in xrange(0,K):
        lst.append(position(j,C-1))
    print "Case #%d: %s" % (i+1,' '.join([str(x) for x in lst]))

