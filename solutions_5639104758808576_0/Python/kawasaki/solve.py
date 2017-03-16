T = int(raw_input())
for t in xrange(T):
    Smax, S = raw_input().split()
    Smax = int(Smax)

    answer = 0
    num_standing_persons = 0
    for i, n in enumerate(map(int, S)):
        if 0 < n and num_standing_persons < i:
            plus = i - num_standing_persons
            answer += plus
            num_standing_persons += plus
        num_standing_persons += n

    print 'Case #{}: {}'.format(t + 1, answer)
