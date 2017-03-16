lines = open("C-small-attempt0 (1).in").readlines()

T = int(lines[0])

caseno = 1

currLineNo = 1
for i in range(0, T):
    
    #line = line.lstrip().rstrip()
    
    N = int(lines[currLineNo])
    #print "%s: %s" % (currLineNo, N)
    currLineNo = currLineNo + 1
    
    ans = ""
    
    uniquea = { }
    uniqueb = { }
    
    for j in range(0, N):
        line = lines[currLineNo]
        #print "%s: %s, %s" % (currLineNo, j, line)
        currLineNo = currLineNo + 1
        line = line.lstrip().rstrip()
        A = (line.split(" ")[0])
        uniquea[A] = 1
        B = (line.split(" ")[1])
        uniqueb[B] = 1
        
    ans = N - len(uniquea)
    if ans > N - len(uniqueb):
        ans = N - len(uniqueb)
    
    
    print 'Case #%s: %s' % (caseno, ans)
    
    caseno = caseno + 1
        
