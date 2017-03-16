def cycle(n, bffs_dict, start):
    cycle = [start]
    while bffs_dict[start] not in cycle:
        cycle.append(bffs_dict[start])
        start = bffs_dict[start]
    if len(cycle) == n:
        return n
    elif bffs_dict[cycle[-1]] != cycle[-2]:
        return len(cycle) - cycle.index(bffs_dict[start])
    else:
        for i in range(1, n + 1):
            if bffs_dict[i] != start or i in cycle:
                continue
            else:
                return len(cycle) + 1
        else:
            return len(cycle)

def biggest(n, bffs_dict):
    max_cycle = 0
    for i in range(1, n + 1):
        max_cycle = max(max_cycle, cycle(n, bffs_dict, i))
    return max_cycle

def main():
    for _ in range(int(input())):
        n = int(input())
        bffs = list(map(int, input().split()))
        bffs_dict = {i + 1: bffs[i] for i in range(n)}
        print('Case #%d: %d' % (_ + 1, biggest(n, bffs_dict)))

if __name__ == '__main__':
    main()
