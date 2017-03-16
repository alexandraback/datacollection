#!/usr/bin/env python2.6

import sys

def checkCase(C):
    "Checks one case"
    
    # get all start points
    starts = []
    for c, links in C.items():
        if len(links) >= 2:
            starts.append(c)
    
    # check each start
    while starts:
        start = starts.pop()
        
        # init to visit queue
        to_visit = []
        for next in C[start]:
            to_visit.append([next, [start]])
        
        # iterate
        paths = []
        while to_visit:
            # get first items
            (point, path) = to_visit[0]
            del to_visit[0]
            
            # add point to path
            path.append(point)
            
            # iterate over options
            for next in C[point]:
                to_visit.append([next, path])
                
            # add to paths
            if not C[point]:
                paths.append(path)
        
        # check paths
        for path1 in paths:
            for path2 in paths:
                if path1 == path2:
                    continue
                r = filter(set(path1).__contains__, path2)
                if len(r) >= 2:
                    return 'Yes'
                    
    return 'No'


# get number of cases
num = int(sys.stdin.readline())

# iterate over cases
for t in xrange(num):
    # read number of classes
    N = int(sys.stdin.readline()) 
    
    # read links and init
    C = {}
    for row in xrange(N):
        C[row+1] = [int(i) for i in sys.stdin.readline().split(' ')]
        del C[row+1][0]
        
    # check case 
    res = checkCase(C)
    
    # print output
    print "Case #%d: %s" % (t+1, res)

    