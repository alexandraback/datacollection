from collections import Counter

T = input()

for case_num in xrange(T):
    N = input()

    if N == 0:
        ans = 'INSOMNIA'
    else:
        counter = Counter()
        i = 0
        while len(counter) != 10:
            i += 1
            counter += Counter(str(i * N))
        ans = i * N

    print 'Case #%d: %s' % (case_num + 1, ans)
