# Python 3.2

from common import *

def compute_needed(adjs, stack, remaining, num_remaining):
    visited = [False] * len(adjs)
    num_visited = 0

    needed = 0
    while num_visited < num_remaining:
        # Flood from stack[needed]
        to_visit = adjs[stack[needed]][:]

        while len(to_visit) > 0:
            cur = to_visit.pop()
            if (not visited[cur]) and remaining[cur]:
                visited[cur] = True
                num_visited += 1
                to_visit.extend(adjs[cur][:])
        needed += 1

    return needed

def main(casenum):
    n, m = readints()
    zips = []
    for i in range(n):
        zips.append(readint())
    zips.append(999999999)

    adjs = [0] * n
    for i in range(n):
        adjs[i] = []

    for i in range(m):
        a, b = readints()
        adjs[a - 1].append(b - 1)
        adjs[b - 1].append(a - 1)


    stack = []
    remaining = [True] * n
    result = ''

    start = 0
    for i in range(n):
        if zips[i] < zips[start]:
            start = i

    # print ("Visiting ", start + 1)
    stack.append(start)
    remaining[start] = False
    result += str(zips[start])
    num_visited = 1

    while num_visited < n:
        # How many do we need to remain connected?
        needed = compute_needed(adjs, stack, remaining, n - num_visited)

        n_origin = None
        n_dest = -1

        for i in range(needed - 1, len(stack)):
            for j in adjs[stack[i]]:
                if remaining[j] and (zips[j] <= zips[n_dest]):
                    n_origin = i
                    n_dest = j

        # We are finished with stack[n_origin + 1:], remove some adjs we no longer need
        for i in range(n_origin + 1, len(stack)):
            for k in adjs[stack[i]]:
                adjs[k].remove(stack[i])
        # if n_origin + 1 < len(stack):
            # print ("Leaving ", [t + 1 for t in stack[n_origin + 1:]])
        stack = stack[:n_origin + 1]

        # Visit n_dest
        # print ("Visiting ", n_dest + 1)
        stack.append(n_dest)
        remaining[n_dest] = False
        result += str(zips[n_dest])
        num_visited += 1

    writeline("Case #{}: {}".format(casenum, result))

run(main)
