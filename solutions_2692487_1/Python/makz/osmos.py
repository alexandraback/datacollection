for t in range(input()):
    print "Case #%s:" % str(t + 1),
    a, n = map(int, raw_input().split())
    motes = map(int, raw_input().split())
    motes.sort()
    print motes
    changes = 0
    needed = [0 for _ in range(n)]
    i = 0
    while i < n:
        needed[i] = changes
        if motes[i] < a:
            a += motes[i]
            i += 1
            changes = 0
        else:
            changes += 1
            if changes > n - i:
                break
            a = 2 * a - 1
    print needed
    for i in range(n - 2, -1, -1):
        needed[i] += needed[i + 1]
        needed[i] = min(n - i, needed[i])
    print needed
    print needed[0]
