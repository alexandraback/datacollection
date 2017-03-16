def runCases(fname,outname):
    case = 0
    with open(fname,'rU') as f:
        for line in f:
            if case == 0: 
                cases = int(line)
                case+=1
                continue
            if case > cases: break
            ans = slides(line)
            outputCase(ans,outname,case)
            case+=1

def outputCase(ans,outname,case):
    if case == 1: f = open(outname,'w')
    else: f = open(outname,'a')
    f.write("Case #"+str(case)+": "+str(ans)+"\n")
    
def slides(line):
    params = [int(x) for x in line.split()]
    B = params[0]
    P = params[1]
    g,p = drawDAG(B)
    while p < P:
        g,p,f = addPaths(g,p,B,P)
        if not f: return "IMPOSSIBLE"
    return "POSSIBLE" + outputGraph(g,B)
    
def numPaths(g,s,t):
    """number of paths from s to t"""
    if s == t: return 0
    paths = [0 for i in range(s,t+1)]
    paths[-1] = 1
    for i in range(t,s-1,-1):
        for j in range(i-1,s-1,-1):
            try: 
                if g[(j,i)] == 1:
                    paths[j-s] += paths[i-s]
            except KeyError: continue
    return paths[0]
    
def addPaths(g,p,B,P):
    for i in range(1,B):
        for j in range(i+1,B):
            if g[(i,j)] == 0: 
                g[(i,j)] = 1
                p = numPaths(g,1,B)
                if p <= P: return g,p,True
                else: g[(i,j)] = 0
    return 0,0,False
       
def outputGraph(g,B):
    s = ""
    for i in range(1,B+1):
        s += "\n"
        for j in range(1,B+1):
            if (i,j) in g.keys():
                s += str(g[(i,j)])
            else:
                s += "0"
    return s              
    
def drawDAG(B):
    g = {}
    p = 1
    for i in range(1,B+1):
        for j in range(i+1,B+1):
            if j == i+1:
                g[(i,j)] = 1
            else: 
                g[(i,j)] = 0
    return g,p
    
runCases("B-small-attempt1.in","B-small.out")