import sys

#print sys.argv[1]


def diamond_check(graph):
    for el in xrange(len(graph)):
        visited = set([])
        queue = [el]
        while len(queue):
            c = queue.pop()
            if c in visited:
                return True
            visited.add(c)
            for n in graph[c]:
                queue.append(n)
    return False

f = open(sys.argv[1],'r')
T = int(f.readline())

for case in xrange(T):
    nodes = int(f.readline())
    nodelist=[]
    for node in xrange(nodes):
        neighbours  = [int(i)-1  for i in f.readline().strip().split(' ')][1:]        
        nodelist.append(neighbours)
    #print nodelist

    a = "Yes" if diamond_check(nodelist) else "No"
    print "Case #"+ str(case+1) + ": " + a
