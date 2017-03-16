with open("input") as f:
    x = f.read().splitlines()

nOfCase = int(x[0])
testCases = x[1:]

def lstPosition(x):#x = [0 1 2] layer = len            
    layer = len(x)
    if layer==1:
        return x[-1]+1
    else:
        return (lstPosition(x[:-1])-1) * K + x[-1] + 1

for i,a in enumerate(testCases):
    K,C,S = (int(x) for x in a.split())
    if C+S*C-1<K:
        print "Case #%d: IMPOSSIBLE" % (i+1)
    else: #K=4,C=2,S=2
        lst = []  
        for numOfStudent in xrange((K-1)/C+1):
            lst.append([j%K for j in xrange(numOfStudent*C,numOfStudent*C+C)])
        lPosition = [lstPosition(l) for l in lst]
        print "Case #%d: %s" % (i+1,' '.join([str(x) for x in lPosition]))
