# -*- coding: utf-8 -*-

import sys


def make_subcircle(n, bffs, current_circle, next_child):

    best = 0
    child = next_child
    new_circle = current_circle + [child]

    possible_neighbours = set()
    for other_child in bffs:
        if bffs[other_child] == child and other_child not in new_circle:
            possible_neighbours.add(other_child)
    bff = bffs[child]
    if bff not in new_circle:
        possible_neighbours.add(bff)

    if not possible_neighbours:

        best = mesure_circle(new_circle, bffs)
        return best

    for possible_neighbour in possible_neighbours:
        new_best = make_subcircle(n, bffs, new_circle, possible_neighbour)
        if new_best > best:
            best = new_best

    return best



def mesure_circle(circle, bffs):
    for i, child in enumerate(circle):
        if i > 0:
            previous_child = circle[i-1]
        else:
            previous_child = circle[-1]
        if i < len(circle) - 1:
            next_child = circle[i+1]
        else:
            next_child = circle[0]
        if bffs[child] not in [next_child, previous_child]:
            return 0
    return len(circle)




def process(n, bffs):
    results = []
    for child in range(1, n):
        results.append(make_subcircle(n, bffs, [], child))
    return max(results)




def main(path):

    with open(path) as f:
        content = f.readlines()
    t = int(content[0].replace("\n", ""))
    count = 1
    i = 1
    while count <= t:
        n = int(content[i].replace("\n", ""))
        i += 1
        bffs = [int(k) for k in content[i].replace("\n", "").split(" ")]
        bffs = {e + 1: k for e, k in enumerate(bffs)}
        i += 1
        if 4 == count:
            pass
        result = process(n, bffs)
        print("Case #{}: {}".format(count, result))
        count += 1


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print(sys.argv[0] + " <path_to_input_file>")
    else:
        main(sys.argv[1])
