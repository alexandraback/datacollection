from sys import stdin

def work(S):
    if len(S) == 0:
        return ''
    m = max(S)
    i = S.index(m)
    c = S.count(m)
    return m*c + work(S[:i]) + S[i:].replace(m, '')

T = int(stdin.readline())
for case in xrange(1, T+1):
    S = stdin.readline().strip()
    print 'Case #{}: {}'.format(case, work(S))
