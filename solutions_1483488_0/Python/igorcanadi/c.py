t = int(raw_input())

for tt in range(t):
    (a, b) = map(int, raw_input().split(' '))
    sol = 0

    for i in range(a, b):
        n = str(i)
        pairs = dict()
        for j in range(1, len(n)):
            new_n_j = int(n[j:] + n[0:j])
            if new_n_j > i and new_n_j <= b:
                pairs[new_n_j] = 1
        sol = sol + len(pairs)
    print "Case #%d: %d" % (tt + 1, sol)



