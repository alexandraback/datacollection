#~ f = open('0b.in')
#~ f = open('B-small-attempt0.in')
f = open('B-large.in')

T = int(f.readline().strip())
for case in range(T):
    numbers = [int(x) for x in f.readline().strip().split()]
    N = numbers[0]
    S = numbers[1]
    p = numbers[2]
    scores = numbers[3:]
    assert N == len(scores)
    scores.sort(reverse=True)
    result = 0
    for s in scores:
        # a) 3 3 3
        if s / 3 >= p:
            result += 1
        # b) 2 3 3
        # b) 2 2 3
        elif s / 3 == p - 1 and s % 3:
            result += 1
        # c) 2 2 2 => 1 2 3
        elif s / 3 == p - 1 and S and p > 1:
            S -= 1
            result += 1
        # d) 1 2 2 => 1 1 3
        elif s / 3 == p - 2 and (s % 3 == 2) and S:
            S -= 1
            result += 1
    print "Case #%s: %s" % (case + 1, result)
