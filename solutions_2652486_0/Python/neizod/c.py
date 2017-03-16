from mathapi import factorized
from collections import Counter

def supcase(kset, N, M):
    r = Counter()
    for k in [factorized(k) for k in kset]:
        r |= Counter(k)
    while 1 in r:
        r.pop(1)
    nset = [p for p, e in r.items() for _ in range(e)]
    while len(nset) > N:
        a, b, *rem = nset
        if a * b > M:
            exit('opps')
        nset = rem + [a * b]
    while len(nset) != N:
        nset += [2]
    return nset

for case in range(int(input())):
    R, N, M, K = [int(n) for n in input().split()]
    print('Case #{}:'.format(case+1))

    for _ in range(R):
        kset = [int(n) for n in input().split()]
        answer = supcase(kset, N, M)
        if not answer:
            answer = [2] * N
        print(''.join(map(str, answer)))
