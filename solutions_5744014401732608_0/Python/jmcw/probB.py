
ts = int(raw_input())

for t in range(ts):
    print "Case #{}:".format(t+1),

    b, m = [int(x) for x in raw_input().split(" ")]

    adj = []
    t = {}
    for i in range(b):
        t[i] = 0
        adj += [[0] * b]
    t[b-1] = 1

    sol = 0
    for i in range(b-2,-1,-1):
        adj[i][i+1] = 1
        c = t[i+1]
        for j in range(i+2, b):
            if c + t[j] <= m:
                adj[i][j] = 1
                c += t[j]
        t[i] = c

    if c == m:
        print "POSSIBLE"
        for x in adj: print "".join(str(y) for y in x)
    else:
        print "IMPOSSIBLE"
