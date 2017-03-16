#!/usr/bin/python
results = []
with open('d.in') as f:
    T = int(f.readline())
    print 'There are {} testcases'.format(T)
    for TC in range(1, T+1):
        K, C, S = [int(x) for x in f.readline().strip().split(' ')]
        #assert S == K
        outline = 'Case #{}:'.format(TC)
        for x in range(1, K+1):
            outline += ' {}'.format(x)
        results.append(outline)
with open('d.out', 'w') as f:
    for r in results:
        f.write(r+'\n')
