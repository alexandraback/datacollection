import sys

sys.setrecursionlimit(2000)

next = {}
used = {}
pair = {}

def find_longest_cycle(x, current_cycle):
    used[x] = True
    y = next[x]

    if (y == current_cycle): return 1
    elif (used[y]): return -1

    future = find_longest_cycle(y, current_cycle)
    if (future == -1): return -1
    else: return future + 1

T = int(input(""))

for i in range(1,T+1):
    next = {}
    N = int(input(""))

    y = [int(x) for x in input("").split()]
    next = {x+1:y[x] for x in range(N)}

    longest = {}

    for x in range(1,N+1):
        used = {x:False for x in range(1,N+1)}
        answer = find_longest_cycle(x,x)
        longest[x] = -1 if (answer == False) else answer

    longest_cycle_length = 0
    for x in range(1,N+1): longest_cycle_length = max(longest_cycle_length, longest[x])

    pair_num = 0
    pair = {}
    for k in range(1,N+1):
        if (next[next[k]] == k):
            pair_num += 1
            pair[k] = True
        else: pair[k] = False

    # For each element in pair, find longest path to that element
    for x in range(1, N+1):
        # Find longest path to x
        best_so_far = 0
        if pair[x]:
            for y in range(1,N+1):
                # Find length of path from y to x
                path_length = 0
                z = y
                works = True
                while (z != x):
                    path_length += 1
                    if (next[next[z]] == z):
                        works = False
                        break
                    z = next[z]
                    if (path_length > N): break

                if (works and path_length <= N and next[next[y]] != y):
                    best_so_far = max(best_so_far, path_length)

            pair_num += best_so_far

    print("Case #%d: %d" % (i, max(pair_num, longest_cycle_length)))