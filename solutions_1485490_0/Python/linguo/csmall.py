from sys import stdin

for cn in xrange(1,1+int(stdin.readline())):
    [N,M] = [int(z) for z in stdin.readline().split()]
    A = [int(z) for z in stdin.readline().split()]
    B = [int(z) for z in stdin.readline().split()]
    i = 0
    while (2 * i + 3 < len(A)):
        if A[2*i+1] == A[2*i+3]:
            A = A[:2*i] + [A[2*i]+A[2*i+2]] + A[2*i+3:]
        i += 1
    N = len(A) / 2
    v = [0] * (M + 1)
    for i in xrange(N):
        w = [k for k in v]
        for j in xrange(M):
            for t in xrange(j, M):
                w[t + 1] = max(w[t + 1], w[t], v[j] + min(A[2*i],sum([B[2*k] for k in xrange(j, t+1) if B[2 * k + 1] == A[2 * i + 1]])))
        v = [k for k in w]
    score = v[-1]
    if (N == 3) and (A[1] == A[5]):
        score = max(score,min(A[0]+A[4],sum([B[2*k] for k in xrange(M) if B[2*k+1] == A[1]])))
    print "Case #%d: %d" % (cn, score)
