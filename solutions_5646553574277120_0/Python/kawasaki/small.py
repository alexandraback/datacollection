T = int(raw_input())
for test_index in xrange(1, T + 1):
    C, D, V = map(int, raw_input().split())
    xs = map(int, raw_input().split())

    answer = 0
    payables = set(sum(x for i, x in enumerate(xs) if b & (1 << i)) for b in xrange(1 << D))
    while set(xrange(1, V + 1)) - payables:
        for i in xrange(1, V + 1):
            if i not in payables:
                xs.append(i)
                answer += 1
                payables |= {p + i for p in payables}

    print 'Case #{}: {}'.format(test_index, answer)
