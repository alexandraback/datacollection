T = int(input())

for c in range(1, T + 1):
    D = int(input())
    P = [int(i) for i in input().split()]

    best_time = max(P)

    for non_special in range(best_time, 0, -1):

        count_cuts = sum((p - 1) // non_special for p in P)

        if count_cuts >= best_time:
            break

        best_time = min(best_time, count_cuts + non_special)

    print("Case #{}: {}".format(c, best_time))
