from Queue import LifoQueue as Stack
from collections import defaultdict

inputlines = open('A-small-attempt2.in', 'r').read().splitlines()
num_testcases = inputlines[0]

outputlist = []
testcasenum = 1

i = 1
while i < len(inputlines):
    graphsize = int(inputlines[i])
    adj_list = dict()
    
    i += 1
    
    for j in range(1, graphsize+1):
        adj_list[j] = map(int, inputlines[i].split()[1:])
        i += 1 # at loop end, i is positioned at start of next testcase
    
    # make the graph undirected
    #for j in range(1, graphsize+1):
    #    for k in adj_list[j]:
    #        if j not in adj_list[k]:
    #            adj_list[k].append(j)
    
    cycle_detected = False
    for j in range(1, graphsize+1):
        to_visit = Stack()
        visited = defaultdict(lambda: False)
        to_visit.put(j)
    
        while not to_visit.empty():
            top = to_visit.get()
            if visited[top] == True:
                cycle_detected = True
                break
            else:
                visited[top] = True
                for node in adj_list[top]:
                    to_visit.put(node)
                    #try:
                    #    adj_list[node].remove(top)
                    #except ValueError:
                    #    pass
            
    if cycle_detected:
        outputlist.append('Case #%i: Yes' % (testcasenum))
    else:
        outputlist.append('Case #%i: No' % (testcasenum))
    testcasenum += 1

outputfile = open('DiamondInheritanceSmallOutput.txt', 'w')
outputfile.write( '\n'.join(outputlist) )