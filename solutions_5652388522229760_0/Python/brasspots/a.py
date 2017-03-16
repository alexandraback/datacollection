#!/usr/bin/python
results =[]

with open('a.in') as f:
    cases = int(f.readline())
    print 'There are {} cases'.format(cases)
    for TC in range (1,cases+1):
        N = int(f.readline())
        if not N:
            N = 'INSOMNIA'
        else:
            _N = N
            dict = {x:0 for x in range(10)}
            while 0 in dict.values():
                n = N
                while n:
                    dict[n%10] = 1
                    n /= 10
                N += _N
            N -= _N
        results.append((TC, N))
with open('a.out', 'w') as f:
    
    for r in results:
        f.write('Case #{}: {}\n'.format(r[0], r[1]))
