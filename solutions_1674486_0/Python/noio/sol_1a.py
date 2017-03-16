#! /usr/bin/python

__author__ = 'Thomas "noio" van den Berg'

### IMPORTS ###
import sys

### FUNCTIONS ###    

def do(connectivity):
    ancestors = {}
    
    def ancs(nd, traversed=set()):
        # base case
        if nd in ancestors:
            return ancestors[nd]
        # Break
        if nd in traversed:
            return set()
        # initialize return
        a = set()
        # Iterate through parents and recurse
        for parent in connectivity[nd]:
            a |= ancs(parent, a)
            a.add(parent)
        a.add(nd)
        # Set to keep memory
        ancestors[nd] = a
        # Return
        return a
    
    for node in connectivity:
        if node not in ancestors:
            ancestors[node] = ancs(node)
    
    for node, parents in connectivity.iteritems():
        prs = list(parents)
        # print "NEXT PARENT"
        if len(prs) > 1:
            base = ancestors[prs[0]].copy()
            for p in prs[1:]:
                for a in ancestors[p]:
                    if a in base:
                        # print "at %r <- %r" % (node, parents)
                        # print "from %d <- %r" % (p, ancestors[p])
                        # print "%d already in %r" % (a, base)
                        return True
                    else:
                        # print "added %d in %r" % (a, ancestors[p])
                        base.add(a)
                    
    return False

### PROCESS INPUT FILE ###

f = open(sys.argv[1])
fout = open(sys.argv[1].replace('.in','.out'),'w')



T = int(f.readline())
for case in xrange(T):
    connectivity = {}
    N = int(f.readline().strip())
    for i in xrange(N):        
        line = [int(d) for d in f.readline().split()]
        M = line[0]
        inheritfrom = line[1:]
        assert len(inheritfrom) == M
        connectivity[i+1] = set(inheritfrom)
        
    ans = "Yes" if do(connectivity) else "No"
    print ans
    fout.write('Case #%d: %s\n'%(case+1,ans))
