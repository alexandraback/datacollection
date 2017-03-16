corpus = ['']*2000001
for i in xrange(1,2000001):
    st = str(i)
    best = "99999999999999999999"
    n = len(st)
    for j in xrange(len(st)):
        test = st[j:] + st[:j]
        if test < best:
            best = test
    corpus[i] = best
T = int(raw_input())
for t in xrange(T):
    A, B = map(int,raw_input().split(" "))
    d = {}
    answer = 0
    for i in xrange(A, B+1):
        small = corpus[i]
        c = d.get(small,0)
        answer += c
        d[small] = c + 1
    print "Case #%d: %d" % (t + 1, answer)

