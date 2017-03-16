import sys
T=int(input())
for case_id in range(1,T+1):
    K,C,S = map(int,input().split())

    def gen():
        for i in range(K):
            yield i
        while True:
            yield K-1

    if S*C<K:
        ans = 'IMPOSSIBLE'
    else:
        g,res,done = gen(),[],False
        while not done:
            c = 0
            for i in range(C):
                c *= K
                nex = next(g)
                c += nex
                if nex == K-1:
                    done = True
            res.append(c)
        assert(len(res)<=S)
        ans = ' '.join(str(n+1) for n in res)

    print('Case #%d: %s' % (case_id, ans))
    print('Case #%d: %s' % (case_id, ans), file=sys.stderr)
