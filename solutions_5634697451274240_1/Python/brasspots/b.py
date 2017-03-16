#!/usr/bin/python
results = []
with open('b.in') as f:
    T = int(f.readline())
    print 'there are {} cases'.format(T)
    for TC in range(1, T+1):
        queue = f.readline().strip() + '+'
        
        n = len(queue)
        flips = sum([queue[i] != queue[i+1] for i in range(n-1)])

        results.append(flips)

with open('b_large.out', 'w') as f:
    for TC, flips in enumerate(results):
        f.write('Case #{}: {}\n'. format(TC+1,flips))

