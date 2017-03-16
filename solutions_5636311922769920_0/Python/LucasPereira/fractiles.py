import itertools

def genSeq(A, K, C):
    ret = []
    for i in xrange(C):
        for j in A:
            if j == 'g':
                ret.append(['g'] * K)
            else:
                ret.append(A)
        A = ret
    return ret

t = int(raw_input())
for i in xrange(1, t + 1):
    tempIn = raw_input().split(" ")
    k = int(tempIn[0])
    c = int(tempIn[1])
    s = int(tempIn[2])
    patterns = []
    ans = []
    if s == k:
        for j in xrange(k):
            ans.append(j + 1)
    else:
        for pattern in itertools.product(['g','l'], repeat = k):
            patterns.append(genSeq(pattern, k, c))
    print "Case #{}: {}".format(i, " ".join(str(x) for x in ans))
