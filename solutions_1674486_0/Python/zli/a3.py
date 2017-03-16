import sys
#http://www.ics.uci.edu/~eppstein/PADS/
#David Eppstein's python library
sys.path.append("PADS")
from DFS import search, preorder
from PartialOrder import TopologicalOrder

def reverse(g,(u,w)):
    #print u,w,g
    if w in g[u]:
        g[w].append(u)
        g[u].remove(w)
    else:
        g[w].remove(u)
        g[u].append(w)

def getpath(w,parent):
    path=[]
    while parent[w]:
        path.append((parent[w],w))
        w=parent[w]
    return path

for case in range(input()):
    print "Case #"+str(case+1)+":",
    N=input()
    #classes=[[]]
    classes={}
    for i in xrange(N):
        #classes.append(map(int,raw_input().split())[1:])
        classes[i+1]=map(int,raw_input().split())[1:]
    #print classes

    order=TopologicalOrder(classes)
    found=False
    for v in order:
        parent={}
        parent[v]=None
        for u,w,edgetype in search(classes,v):
            if edgetype==1 and u!=w:
                parent[w]=u
        for u in parent:
            #print v,u
            if u is not v:
                path=getpath(u,parent)
                #print path
                for edge in path:
                    reverse(classes,edge)
                if u in preorder(classes,v):
                    #print "found",v,u
                    found=True
                for edge in path:
                    reverse(classes,edge)
    if not found:
        print "No"
    else:
        print "Yes"
                

