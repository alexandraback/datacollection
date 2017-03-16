T = int(raw_input())

for t in xrange(T):
    m, S = raw_input().split(' ')
    m = int(m)
    S = [int(c) for c in S]

    max_diff = 0
    cumulative_sum = 0
    for i in xrange(m + 1):
        if cumulative_sum < i:
            max_diff = max(max_diff, i - cumulative_sum)
        cumulative_sum += S[i]

    print 'Case #' + str(t + 1) + ': ' + str(max_diff)
