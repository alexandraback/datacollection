for t in range(int(input())):
    C, D, V = [int(x) for x in input().split()]
    denominations = [int(x) for x in input().split()]

    values = [False for x in range(V)]

    for d in denominations:
        for i in range(V, 0, -1):
            if values[i-1] == True and i + d <= V:
                values[i + d - 1] = True
        values[d - 1] = True

    taken = 0

    while not all(values):
        pd = values.index(False) + 1
        taken += 1

        for i in range(V, 0, -1):
            if values[i-1] == True and pd + i <= V:
                values[i + pd - 1] = True

        values[pd - 1] = True

    print('Case #{0}: {1}'.format(t + 1, taken))
