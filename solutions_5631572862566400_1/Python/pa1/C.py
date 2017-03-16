import sys
sys.setrecursionlimit(1500)

def dfs(cur_node, bffs, group):
    if group[cur_node] == -1:
        group[cur_node] = 0
        return dfs(bffs[cur_node], bffs, group)
    else:
        target_node = cur_node
        start_node = bffs[cur_node]
        cycle_len = 1
        while not start_node == target_node:
            cycle_len += 1
            start_node = bffs[start_node]
        return cycle_len, target_node

def get_path_len(source_node, dest_node, bffs):
    if source_node == dest_node:
        return 0
    return 1 + get_path_len(bffs[source_node], dest_node, bffs)

def f(bffs):
    N = len(bffs)
    max_pure_cycle_len = 0
    two_cycle_end_lengths = {}
    for node in range(1, N + 1):
        two_cycle_end_lengths[node] = 0
    for unvisited_node in range(1, N + 1):
        group = {}
        for i in range(1, N + 1):
            group[i] = -1

        cycle_len, cycle_node = dfs(unvisited_node, bffs, group)
        #print unvisited_node, cycle_node, cycle_len
        if cycle_len > 2:
            max_pure_cycle_len = max(max_pure_cycle_len, cycle_len)
        elif cycle_len == 2:
            two_cycle_end_lengths[cycle_node] = max(two_cycle_end_lengths[cycle_node], get_path_len(unvisited_node, cycle_node, bffs))

    pure_two_cycles = 0
    max_two_cycle_len = 0
    for node in range(1, N + 1):
        if bffs[bffs[node]] == node:
            max_two_cycle_len += two_cycle_end_lengths[node] + two_cycle_end_lengths[bffs[node]] + 2

    return max(max_pure_cycle_len, max_two_cycle_len / 2)

def main():
    T = int(raw_input())
    for t in range(1, T + 1):
        N = raw_input()
        L = raw_input().strip().split()
        bffs_list = [int(fr) for fr in L]
        #bffs_list = [2, 1, 1, 5, 6, 4, 2]#[7, 8, 10, 10, 9, 2, 9, 6, 3, 3]
        bffs = {}
        for i in range(len(bffs_list)):
            bffs[i + 1] = bffs_list[i]
        print "Case #{0}: {1}".format(t, f(bffs))

if __name__ == "__main__":
    main()