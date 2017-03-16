def find_all_paths(graph, start, end, path=[]):
    path = path + [start]
    if start == end:
        return [path]
    if not graph.has_key(start):
        return []
    paths = []
    for node in graph[start]:
        if node not in path:
            newpaths = find_all_paths(graph, node, end, path)
            for newpath in newpaths:
                paths.append(newpath)
    return paths



test_cases = raw_input()
test_cases = int(test_cases)
for l in range(1, test_cases+1):
    key_dict = {}
    no_of_nodes = raw_input()
    no_of_nodes = int(no_of_nodes)
    for i in range(1, no_of_nodes+1):
        text = raw_input()
        text = text.rsplit(' ')
        count = int(text[0])
        list_of_nodes = []
        for loop in range(0, count):
            list_of_nodes.append(text[loop+1])
        key_dict.update({str(i):list_of_nodes})
    ##print key_dict
    path_exist = False
    for i in range(1, no_of_nodes+1):
        for j in range(1, no_of_nodes+1):
            path = []
            path = find_all_paths(key_dict, str(i),str(j), path)
            if len(path) >= 2:
                path_exist = True
                break
            else:
                pass
    if path_exist == True:
        print "Case #%s: Yes" %l
    else:
        print "Case #%s: No" %l
        



