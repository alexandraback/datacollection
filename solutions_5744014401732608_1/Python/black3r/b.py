T = int(input())
for I in range(1, T+1):
    result = ""
    b, m = [int(x) for x in input().split()]

    buildings = [i for i in range(0, b)]
    adj = None
    if m > 2**(b-2):
        result = "IMPOSSIBLE"
    else:
        result = "POSSIBLE"

        # vybuildi graf
        adj = [[0 for i in range(0, b)] for j in range(0, b)]
        for i in range(0, b-1):
            for j in range(i+1, b-1):
                adj[i][j] = 1

        for i in range(0, b-2):
            if m & (2**i):
                adj[i+1][b-1] = 1

        if m == 2**(b-2):
            for i in range(0, b-1):
                adj[i][b-1] = 1

    print("Case #%d: %s" % (I, str(result)))
    if adj:
        # vyprinti graf
        for row in adj:
            print(''.join([str(x) for x in row]))
