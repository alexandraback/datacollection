# -*- coding: utf-8 -*-

def process(N):
    if N == 0:
        return 'INSOMNIA'

    x = N
    check = [False] * 10
    count = 0

    while True:
        for i in str(x):
            if not check[int(i)]:
                check[int(i)] = True
                count += 1
                if count == 10:
                    return str(x)
        x += N


T = input()
for i in xrange(1, T+1):
    N = input()
    print 'Case #%d: %s' % (i, process(N))
