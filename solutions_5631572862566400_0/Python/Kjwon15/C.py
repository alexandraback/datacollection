from collections import defaultdict

def get_loop_size(connected_map, start, group=None):
    if not group:
        group = [start]

    next_friends = (
        val
        for val in connected_map[start]
        if val not in group
    )

    try:
        return max(
            get_loop_size(connected_map, next_friend, group+[next_friend])
            for next_friend in next_friends
        )
    except ValueError:
        return len(group)

def solve():
    n = int(input())
    line = input().split()
    bffs = {
        i+1:int(line[i])
        for i in range(n)
    }
    connected_map = defaultdict(set)
    for key, val in bffs.items():
        connected_map[key].add(val)
        connected_map[val].add(key)

    return max(
        get_loop_size(connected_map, i)
        for i in range(1, n+1)
    )

round = int(input())
for r in range(1,round+1):
    print('Case #{}: {}'.format(r, solve()))
