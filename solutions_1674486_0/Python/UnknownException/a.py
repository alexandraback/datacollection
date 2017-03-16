'''
Created on May 5, 2012

@author: Indra
'''
import sys, os

#filename = "A-large"
filename = "A-small-attempt2"

path = os.path.normpath(os.path.join(os.path.dirname(__file__), filename + ".in"))
reader = open(path, "rb")
path = os.path.normpath(os.path.join(os.path.dirname(__file__), filename + ".out"))
writer = open(path, "w")
T = int(reader.readline().rstrip())

caseno = 1
while caseno <= T:
    N = int(reader.readline().rstrip())
    paths = [[] for i in xrange(N)]
    for i in xrange(N):
        line = reader.readline().rstrip()
        t = [int(x) for x in line.split(' ')]
        M = t[0]
        if M>0:
            parents = t[1:]
            for parent in parents:
                paths[i].append(parent-1)
    print paths
    isDiamond = False
    
    for start in xrange(N):
#        print "starting:",start
        visited = [False for i in xrange(N)]
        stack = [start]
        if isDiamond: break
        while len(stack)>0:
            cur = stack.pop()
#            print cur
            if visited[cur]:
                isDiamond=True
                break
            visited[cur] = True
            for parent in paths[cur]:
                stack.append(parent)
    
    if isDiamond: pret = "Yes"
    else: pret = "No"
    writer.write("Case #%s: %s\n" % (str(caseno), pret))
    caseno += 1

writer.close()
