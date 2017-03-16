# node class
class node:
    neighbors = []
    ncount = 0
    root = False
    inheritors = []
    name = 0

def BFS(node, nodearray, name):
    for neighbor in node.neighbors:
        if nodearray[neighbor - 1].root:
            nodearray[neighbor-1].inheritors[name - 1] += 1 
        else:
            BFS(nodearray[neighbor-1], nodearray, name)

# returns answer.
def solve(nodearray):
    roots = []
    for node in nodearray:
        if node.root:
            roots.append(node)
    for node in nodearray:
        BFS(node, nodearray, node.name)
        for root in roots:
            if root.inheritors[node.name-1] > 1:
                return "Yes"
    return "No"
        
# grab number of cases
cases = int(raw_input())

#array to store input values
inputs = []

#parse input, store in inputs array
for ncase in range(cases):
    numclass = int(raw_input())
    nodearray = []
    for x in range(numclass):
        stdin = map(int, raw_input().split(' '))
        n = node()
        n.name = x+1
        n.inheritors = [0 for b in range(numclass)]
        n.ncount, n.neighbors = stdin[0], stdin[1:]
        n.root = (n.ncount == 0)
        nodearray.append(n)
    inputs.append((ncase,nodearray))

# calculate answer
for case in inputs:
    ncase, nodearray = case
    ncase += 1
    solution = solve(nodearray)
    print "Case #" + str(ncase) + ": " + solution

