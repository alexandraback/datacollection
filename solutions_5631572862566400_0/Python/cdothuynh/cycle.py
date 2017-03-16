from collections import defaultdict


def find_loop(cur_list, cur_set, graph):
    if graph[cur_list[-1]] in cur_set and cur_list[0] == graph[cur_list[-1]]:
        return [], cur_list
    elif graph[cur_list[-1]] in cur_set:
        idx = cur_list.index(graph[cur_list[-1]])
        return cur_list[:idx], cur_list[idx:]
    else:
        cur_set.add(graph[cur_list[-1]])
        return find_loop(cur_list + [graph[cur_list[-1]]], cur_set, graph)

T = int(raw_input())

for t in xrange(T):
    N = int(raw_input())
    graph = defaultdict()
    l = [int(x) for x in raw_input().split()]
    for i in xrange(N):
        graph[i+1] = l[i]

    in_loops = set()
    is_dangling = set()

    loops_dangles = dict()

    loops = []
    for i in xrange(N):
        if (i+1) in in_loops or (i+1) in is_dangling:
            continue
        dangle, loop = find_loop([i+1], set([i+1]), graph)
        in_loops = in_loops.union(loop)
        is_dangling = is_dangling.union(dangle)
        loops.append(len(loop))
        if len(loop) == 2:
            loop.sort()
            if (tuple(loop) not in loops_dangles):
                loops_dangles[tuple(loop)] = {loop[0]: 0, loop[1]: 0}

            if dangle and loops_dangles[tuple(loop)][graph[dangle[-1]]] < len(dangle):
                loops_dangles[tuple(loop)][graph[dangle[-1]]] = len(dangle)

    longuest = max(loops)

    max_dangles = 0

    for key, val in loops_dangles.iteritems():
        max_dangles += val[key[0]] + val[key[1]] + 2

    longuest = max(longuest, max_dangles)

    print "Case #" + str(t+1) + ": " + str(longuest)





