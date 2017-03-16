import sys


def f(incoming, root, exclude, acc):
    best = acc
    for i in incoming[root]:
        if i == exclude:
            continue
        x =  f(incoming, i, exclude, acc + 1)
        if x > best:
            best = x
    return best 



T = int(sys.stdin.readline())
for t in range(1, T+1):
    N = int(sys.stdin.readline())
    line = sys.stdin.readline()
    line = line.rstrip()
    out = list(map(lambda x: int(x) - 1, line.split(" ")))
    incoming = []
    for i in range(0, N):
        incoming.append([])
    for i in range(0, N):
        incoming[out[i]].append(i)
    best_no_cycle = 0
    for i in range(0, N):
        if out[i] > i and out[out[i]] == i:
            j = out[i]
            best_no_cycle += f(incoming, i, j, 1) + f(incoming, j, i, 1)
    best_cycle = 0
    for i in range(0, N):
        cycle_length = 0
        j = out[i]
        for x in range(0, N):
            if j == i:
                cycle_length = x + 1
                break;
            j = out[j]
        if cycle_length > best_cycle:
            best_cycle = cycle_length


    print("Case #{}: ".format(t), end="")
    print(max(best_cycle, best_no_cycle))
