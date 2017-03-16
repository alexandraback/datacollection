N = 32
J = 500

primes = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97]

import random

done = set()
ans = set()

while len(ans) < J:
    b = bin(random.choice(xrange(2**(N-2))))[2:]
    b = ('0' * (N-2-len(b))) + b
    s = '1' + b + '1'
    done.add(s)

    worker = []
    for i in xrange(2,11):
        num = int(s, i)
        for p in primes:
            if num % p == 0:
                worker.append(p)
                break
        else:
            break
    else:
        ans.add((s, tuple(worker)))

print 'Case #1:'

for (coin, proof) in ans:
    print coin, ' '.join(map(str,list(proof)))
