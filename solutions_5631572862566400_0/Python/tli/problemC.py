n = input()
for i in xrange(n):
    m = input()
    graph = map(lambda a: int(a) - 1, raw_input().split(" "))
    in_flows = [0 for j in xrange(m)]
    for v in graph:
        in_flows[v] += 1

    sources = []
    for k in xrange(m):
        if in_flows[k] == 0:
            sources.append(k)

    if len(sources) == 0:
        print "Case #" + str(i + 1) + ": " + str(m)
        continue

    visited_count = 0
    visited = [0 for j in xrange(m)]

    cycles = []
    in_cycle = [0 for j in xrange(m)]
    in_length_two_cycle = [0 for j in xrange(m)]
    max_in_flows = [0 for j in xrange(m)]

    cur_length = 0

    cur_node = sources.pop()
    stack = []
    while cur_node is not None:
        if visited[cur_node] > 0 or in_cycle[cur_node] > 0:
            if in_cycle[cur_node] == 0:
                cycle_length = cur_length - visited[cur_node] + 1
                cycle = stack[-cycle_length:]
                cycles.append(cycle)

                for k in cycle:
                    in_cycle[k] = 1

                if len(cycle) == 2:
                    in_length_two_cycle[cycle[0]] = 1
                    in_length_two_cycle[cycle[1]] = 1
                    pre_flows = cur_length - cycle_length
                    if max_in_flows[cur_node] < pre_flows:
                        max_in_flows[cur_node] = pre_flows
            elif in_length_two_cycle[cur_node]:
                if max_in_flows[cur_node] < cur_length:
                    max_in_flows[cur_node] = cur_length


            cur_length = 0
            cur_node = sources.pop() if len(sources) > 0 else None
            visited = [0 for j in xrange(m)]
            stack = []
            continue

        stack.append(cur_node)
        visited[cur_node] = cur_length + 1
        cur_node = graph[cur_node]
        cur_length += 1

    ans = 0
    len_2_ans = 0
    for cycle in cycles:
        if len(cycle) > 2:
            if len(cycle) > ans:
                ans = len(cycle)

        if len(cycle) == 2:
            len_2_ans += max_in_flows[cycle[0]] + max_in_flows[cycle[1]] + 2

    if len_2_ans > ans:
        ans = len_2_ans

    print "Case #" + str(i + 1) + ": " + str(ans)

