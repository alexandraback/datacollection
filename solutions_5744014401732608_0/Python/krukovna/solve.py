import sys
import copy
import random


class Solved(Exception):
    pass


def explain(config, end):
    output = ['POSSIBLE']
    for i in range(1, end+1):
        o = []
        if i not in config:
            o.append('0' * end)
        else:
            for j in range(1, end+1):
                if j in config[i]:
                    o.append('1')
                else:
                    o.append('0')

        output.append(''.join(o))

    return '\n'.join(output)


def remove_any(config, end, limit):
    a = amount(config, 1, end)
    if a < limit:
        return

    if a == limit:
        raise Solved(explain(config, end))

    for i, arr in config.items():
        for index, j in enumerate(arr):
            if j != end:
                c = copy.deepcopy(config)
                c[i].remove(j)
                remove_any(c, end, limit)


def solve(a, limit):
    MAXES = {2: 1, 3: 2, 4: 5, 5: 16, 6: 65}
    if limit > MAXES[a]:
        raise Solved('IMPOSSIBLE')

    q = {}
    for j in range(1, a):
        q[j] = [x for x in range(2, a+1) if x != j]

    remove_any(q, a, limit)
    raise Solved('IMPOSSIBLE')

def amount(cfg, start_node, end_node, visited = None, s = None):
    if s is None:
        s = [0]
    if visited is None:
        visited = [start_node]

    for i in cfg[start_node]:
        if i not in visited:
            if i == end_node:
                s[0] += 1
            else:
                amount(cfg, i, end_node, copy.copy(visited) + [i], s)

    return s[0]

if __name__ == '__main__':
    for i in range(int(sys.stdin.readline())):
        try:
            solve(*map(int, sys.stdin.readline().strip().split(' ')))
        except Solved as e:
            print('Case #{}: {}'.format(i+1, e))
