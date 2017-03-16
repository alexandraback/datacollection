import copy

import sys

sys.setrecursionlimit(50000)

T = int(input(""))
B = 0
M = 0

def paths(graph):
    path_count = {B:1}
    for i in range(B-1,0,-1): path_count[i] = sum(path_count[j] for j in range(i+1,B+1) if j in graph[i])
    return path_count[1]

def reachable(graph, initial, final):
    seen = set()
    stack = [initial]

    while (len(stack) > 0):
        next = stack.pop()
        if (next == final): return True
        seen.add(next)
        for i in graph[next]:
            if i not in seen: stack.append(i)

    return False

def find_answer(graph, target, current_node, to_remove):
    #print(graph, paths(graph), target)
    if (current_node == -1): return None
    if (to_remove <= current_node): return find_answer(graph, target, current_node-1, B)

    current_paths = paths(graph)
    #print(graph)
    #print(current_paths, target, current_node, to_remove)

    if current_paths == target: return graph
    if current_paths < target: return None

    # Removing edges will not decrease number of paths, since the target must be reachable
    if (not reachable(graph, to_remove, B)): return find_answer(graph, target, current_node, to_remove-1)

    # Either remove or do not remove
    new_graph = copy.deepcopy(graph)
    new_graph[current_node].remove(to_remove)

    answer1 = find_answer(new_graph, target, current_node, to_remove-1)
    if (answer1 != None): return answer1
    else: return find_answer(graph, target, current_node, to_remove - 1)

for a in range(1,T+1):
    (B,M) = (int(x) for x in input("").split(" "))

    if (M > 2**(B-2)): print(("Case #%d: IMPOSSIBLE") % a)
    else:
        # Remove all unneeded vertices
        lower_bound = 0
        for b in range(B-2,-1,-1):
            if (2**b <= M):
                lower_bound = b + 3
                break
#        lower_bound = B+1

        graph = {i : set(j for j in range(i+1,B+1) if (j == 1 or j > B - lower_bound + 1)) if (i == 1 or i > B - lower_bound + 1) else {} for i in range(1,B+1)}

        answer = find_answer(graph, M, B-1, B)
        if (answer == None): print("ERROR")

        else:
            print("Case #%d: POSSIBLE" % a)
            for i in range(1,B+1): print("".join(["1" if j in answer[i] else "0" for j in range(1,B+1)]))