from sets import Set 
from hopcroftkarp import HopcroftKarp
filein = open('C-small-attempt0.in.txt', 'r')
fileout = open('C-small-attempt0.out.txt', 'w')

T = int(filein.readline())
for t in range(T):
    fileout.write('Case #%d: ' % (t + 1)) 
    TT = int(filein.readline())
    graph = {}
    first = set()
    second = set()
    for i in range(TT):
        inp = filein.readline().split(" ")
        first.add(inp[0])
        second.add(inp[1])
        if inp[0] not in graph:
            graph[inp[0]] = set()
            graph[inp[0]].add(inp[1])
        else:
            graph[inp[0]].add(inp[1])
    temp = HopcroftKarp(graph).maximum_matching()
    # print temp
    # print TT
    # print len(temp)
    # print (len(first)+len(second) - 2*len(temp))
    rst = TT - len(temp)/2-(len(first)+len(second) - len(temp))


    fileout.write(str(rst))
    fileout.write("\n")
    # fileout.write("\n")       

    
 
filein.close()
fileout.close()