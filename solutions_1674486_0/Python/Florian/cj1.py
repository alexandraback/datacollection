import sys

def solveCase(f):
    nodeNum = int(f.readline())
    graph = []
    g = {}
    for i in xrange(nodeNum):
        if i + 1 not in g:
            g[i+1] = set()
        l = map(int, f.readline().split())
        ancNum = l[0]
        ancestors = l[1:]
        for a in ancestors:
            if a not in g:
                g[a] = set([i+1])
            else:
                g[a].add(i+1)
        graph.append(ancestors)
    allSuccD = {}
    for n in g:
        s = findAllAncs(g, n, allSuccD)
        if s == True:
            return "Yes"
    return "No"
        
    
    
def findAllAncs(g, n, allSuccD):
    if n in allSuccD:
        return allSuccD[n]
    else:
        allSuccs = set(list(g[n]))
        for c in g[n]:
            s = findAllAncs(g, c, allSuccD)
            if s == True:
                return True
            if not allSuccs.isdisjoint(s):
                return True
            allSuccs.update(s)
        allSuccD[n] = allSuccs
    return allSuccD[n]
    
def main(fName):
    f = open(fName, "r")
    cases = int(f.readline())
    for i in xrange(cases):
        print "Case #%d: %s" % (i + 1, solveCase(f))
    f.close()

main(sys.argv[1])
