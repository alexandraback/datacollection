#This problem deals with functional graphs. The function BFF is represented by a dictionary called "bff", where bff[key] is the BFF of key.

def altmax(list):
    if list == []:
        return 0
    else:
        return max(list)

def maximum_circle(graph):
    unexplored = {key: graph[key] for key in graph}
    bff_pairs = []
    for node in graph:
        if graph[graph[node]] == node:
            if node in unexplored:
                bff_pairs.append([node, graph[node]])
                del unexplored[node]
                del unexplored[graph[node]]
    admire_chains = {}
    for pair in bff_pairs:
        for friend in pair:
            admire_chains[friend] = []
    max_cycle_length = 0
    while unexplored != {}:
        curr_node = unexplored.keys()[0]
        generated = []
        while curr_node not in generated:
            generated.append(curr_node)
            if curr_node in unexplored:
                del unexplored[curr_node]
            curr_node = graph[curr_node]
        if curr_node in admire_chains:
            admire_chains[curr_node].append(len(generated)-2)
        else:
            max_cycle_length = max(max_cycle_length, len(generated) - generated.index(curr_node))
    max_admire_circle = sum([1+altmax(admire_chains[friend]) for friend in admire_chains])
    return max(max_admire_circle, max_cycle_length)

i = open("input.txt", "r")
o = open("output.txt", "w")

num_cases = int(i.readline().strip())
for case in range(1, num_cases+1):
    i.readline()
    kids = map(lambda x: int(x), i.readline().strip().split())
    graph = {ind+1: kids[ind] for ind in range(len(kids))}
    o.write("Case #" + str(case) + ": " + str(maximum_circle(graph)) + "\n")
