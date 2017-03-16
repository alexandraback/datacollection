for c in xrange(int(raw_input())):
    N = int(raw_input())
    m = [map(int,raw_input().split()) for _ in xrange(2*N-1)]

    k = [0]*2503
    for l in m:
        for e in l:
            k[e] += 1

    ans = []
    for i in xrange(len(k)):
        if k[i]%2 != 0:
            ans.append(i)

    print "Case #%d:"%(c+1), ' '.join(map(str,ans))
