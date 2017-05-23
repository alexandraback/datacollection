for case in range(int(raw_input())):
    c, d, v = map(int, raw_input().split(' '))
    vals = map(int, raw_input().split(' '))

    n_required = 0

    largest_reachable = 0
    while True:
        if largest_reachable >= v:
            break
        if len(vals) > 0:
            smallest = vals[0]
            if smallest <= largest_reachable + 1:
                largest_reachable = largest_reachable + smallest
                vals.pop(0)
                continue
        n_required += 1
        largest_reachable = 2* largest_reachable + 1

    print 'Case #%d: %d' % (case + 1, n_required)



