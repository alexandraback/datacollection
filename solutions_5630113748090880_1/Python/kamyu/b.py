from collections import Counter

def rank_and_file():
    N = input()
    lists = []
    for _ in xrange(2 * N - 1):
        lists += list(map(int, raw_input().strip().split()))
    cnt = Counter(lists)
    res = []
    for k, v in cnt.iteritems():
        if v % 2 == 1:
            res.append(k)
    res.sort()
    return " ".join(map(str, res))


for case in xrange(input()):
    print 'Case #%d: %s' % (case+1, rank_and_file())
