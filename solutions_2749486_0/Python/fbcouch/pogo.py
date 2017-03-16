#!/usr/bin/pypy

import fileinput, math, timeit

def find_node(nlist, x, y):
    for n in nlist:
        if n.x == x and n.y == y: return n
    return None

class Node(object):
    dist_from_start = 0
    dist_to_target = 0
    parent = None
    x, y = 0, 0
    pogo = 0
    
    def __init__(self, x, y, tx, ty, pogo, parent = None):
        self.x, self.y = (x, y)
        self.dist_from_start = 0
        self.pogo = pogo
        if parent is not None:
            self.dist_from_start = parent.dist_from_start + 1
        self.dist_to_target = math.fabs(tx - x) + math.fabs(ty - y)
        if (tx != x) and (ty != y):
            self.dist_to_target *= 2
        self.parent = parent
        
    def set_parent(self, parent, pogo):
        self.parent = parent
        self.pogo = pogo
        self.dist_from_start = 0
        if parent is not None:
            self.dist_from_start = parent.dist_from_start + 1
    
    def __str__(self):
        return "[%d ==> (%d, %d) ==> %d]" % (self.dist_from_start, self.x, self.y, self.dist_to_target)
        
    def __int__(self):
        return self.dist_from_start + self.dist_to_target

class Case(object):
    casenum = 0
    target = None
    
    solution = None
    
    def __init__(self, casenum, x, y):
        self.casenum = casenum
        self.target = (x, y)
        
    def solve(self):
        solution = ""
        
        nclosed = []
        nopen = []
        
        nopen.append(Node(0, 0, self.target[0], self.target[1], 0))
        
        target_nclosed = None
        #i = 0
        while (target_nclosed is None):
            #i += 1        
            
            nopen.sort(key=Node.__int__)
            consider = nopen[0]
            nopen = nopen[1:]
            pogo = consider.pogo + 1
            
            conlist = [(consider.x + pogo, consider.y), (consider.x - pogo, consider.y), (consider.x, consider.y + pogo), (consider.x, consider.y - pogo)]    
            
            for target in conlist:
                
                n = find_node(nopen, target[0], target[1])
                if not n:
                #    if not find_node(nclosed, target[0], target[1]): 
                    nopen.append(Node(target[0], target[1], self.target[0], self.target[1], pogo, consider))
                else:
                    if consider.dist_from_start + 1 < n.dist_from_start:
                        n.set_parent(consider, pogo)

            nclosed.append(consider)
            
            target_nclosed = find_node(nclosed, self.target[0], self.target[1])
        
        # figure out path
        #print target_nclosed
        tracen = target_nclosed
        while(tracen.parent is not None):
            #print "%s --> %s" % (tracen.parent, tracen)
            if (tracen.x == tracen.parent.x):
                if (tracen.y > tracen.parent.y):
                    solution = ''.join(["N", solution])
                else:
                    solution = ''.join(["S", solution])
            else:
                if (tracen.x > tracen.parent.x):
                    solution = ''.join(["E", solution])
                else:
                    solution = ''.join(["W", solution])
            tracen = tracen.parent
        self.solution = solution
        
    def __str__(self):
        if self.solution is None:
            self.solve()
            
        return "Case #%i: %s" % (self.casenum, self.solution)


def readcases(lines):
    cases = []
    firstline = True
    for line in lines:
        if firstline:
            firstline = False
            continue
            
        bounds = line.split()
        cases.append(Case(len(cases) + 1, int(bounds[0]), int(bounds[1])))
    return cases
    
cases = []
if __name__ == "__main__":
    cases = readcases(fileinput.input())
    
    #print timeit.timeit(stmt='for case in cases: print case;', setup='from __main__ import cases', number=1)
    
    for case in cases:
        print case
