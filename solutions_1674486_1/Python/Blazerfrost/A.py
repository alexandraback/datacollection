'''
Created on 06 May 2012

@author: dirk-b
'''

inp = open('data/A-large.in', 'r')
out = open('data/A-large.out', 'w')

T = int(inp.readline())
for t in xrange(1, T + 1):
    print t
    N = int(inp.readline())
    
    paths = {}
    edges = {}
    
    q = []
    
    for i in xrange(N):
        nums = map(int, inp.readline().split())
        edges[i + 1] = nums[1:]
        paths[i + 1] = []
        q.append([i + 1])
    
    ans = False
    
    while len(q) and not ans:
        currPath = q.pop()
        pathStart = currPath[0]
        pathCurr = currPath[-1]
        
        # check for win condition here
        for p in paths[pathCurr]:
            if len(currPath) > 1 and len(p) > 1 and p[0] == currPath[0] and p[-1] == currPath[-1] and p != currPath:
                ans = True
                break
        
        paths[pathCurr].append(currPath)
        
        for dest in edges[pathCurr]:
            newPath = [x for x in currPath]
            newPath.append(dest)
            q.append(newPath)
            
    #print paths
    out.write("Case #%d: %s\n" % (t, "Yes" if ans else "No"))

inp.close()
out.close()
