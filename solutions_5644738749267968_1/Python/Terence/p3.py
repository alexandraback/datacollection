def score(v1, v2):
    j = len(v2)-1
    sc = 0
    for i in range(len(v1)-1, -1, -1):
        while j >= 0 and v2[j] >= v1[i]:
            j -= 1
        if j < 0:
            break
        sc += 1
        j -= 1
    return sc

t = int(raw_input())
for iCase in range(1, t+1):
    n = int(raw_input())
    v1 = map(float, raw_input().split())
    v2 = map(float, raw_input().split())
    v1.sort()
    v2.sort()
    print 'Case #%d: %d %d' % (iCase, score(v1, v2), n-score(v2, v1))
