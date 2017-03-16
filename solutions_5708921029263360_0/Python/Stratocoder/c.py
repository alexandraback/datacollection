from collections import Counter, deque

t = int(raw_input())
for tt in xrange(1, t + 1):
    j, p, s, k = map(int, raw_input().split(' '))
    q = deque()
    cm = Counter()
    for jj in xrange(1, j + 1):
        for pp in xrange(1, p + 1):
            for ss in xrange(1, s + 1):
                if cm[(jj, pp, 0)] == k:
                    continue
                if cm[(jj, 0, ss)] == k:
                    continue
                if cm[(0, pp, ss)] == k:
                    continue
                q.append((jj, pp, ss))
                cm[(jj, pp, 0)] += 1
                cm[(jj, 0, ss)] += 1
                cm[(0, pp, ss)] += 1

    print 'Case #{}: {}'.format(tt, len(q))
    while len(q):
        print ' '.join(map(str, q.popleft()))
