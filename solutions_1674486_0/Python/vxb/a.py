class DiamondInheritance(Exception):
    pass

def is_diamond(inheritances):
    """docstring for is_diamond"""
    roots = []
    for node in inheritances:
        if not inheritances[node]:
            roots.append(node)
    try:
        for node in inheritances:
            dfs(inheritances, node, [])
    except DiamondInheritance:
        return True
    return False

def dfs(graph, node, visited):
    """docstring for dfs"""
    #print node, visited
    if node in visited:
        raise DiamondInheritance
    visited.append(node)
    for child in graph[node]:
        dfs(graph, child, visited)
    #return visited

for case in range(1,input()+1):
    classes = input()
    inherits = []
    for i in range(classes):
        a = map(int, raw_input().split()[1:])
        a = map(lambda x: x-1, a)
        inherits.append(a)
    structure = dict(enumerate(inherits))
    #print structure
    print "Case #{0}: {1}".format(case, "Yes" if is_diamond(structure) else
            "No")
