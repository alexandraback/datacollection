from sys import stdin

def each_case(S):
    pre = ''
    post = ''
    while S:
        maxletter = max(S)
        p = S.rfind(maxletter)
        pre = pre + maxletter
        post = S[p+1:] + post
        S = S[:p]

    return pre + post

T = int(stdin.readline())
for t in xrange(1,T+1):
    S = stdin.readline().strip()
    print 'Case #{}: {}'.format(t, each_case(S))
