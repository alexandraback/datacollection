'''
Created on May 6, 2012

@author: mchesley
'''

def path(start, end):
    if start == end: return 1
    if not graph.has_key(start): return 0
    answer = 0
    for step in graph[start]:
        answer += path(int(step), end)
    return answer

def multiple(starts, classes):
    for start in starts:
        for end in range(1, classes+1):
            paths = path(start, end)
            if paths > 1:
                return "Yes"
    return "No"

handle = open("cj.in", "r")
cases = int(handle.readline())

s = ""

for case in range(cases):
    s += "Case #" + str(case+1) + ": "
    graph = {}
    
    classes = int(handle.readline())
    
    starts = []
    
    for c in range(1, classes+1):
        line = handle.readline()
        line = line.split()
        graph[c] = line[1:]
        if line[0] > 1: starts.append(c)
    
    answer = multiple(starts, classes)
    
    
    s += answer + '\n'

handle = open("cj.out","w")
handle.write(s)
handle.close()