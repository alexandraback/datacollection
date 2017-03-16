from random import randint
import random
from fractions import gcd


def PollardRho(n, cutoff):
    i = 0
    xi = randint(0, n - 1)
    k = 2
    y = xi
    steps = 0
    while i < n:
        steps += 1
        if steps == cutoff:
            return None
        i = i + 1
        xi = ((xi ^ 2) - 1) % n
        d = gcd(y - xi, n)
        if d != 1 and d != n:
            return d;
        if i == k:
            y = xi
            k = 2 * k


N = 32
J = 500

found = []

while len(found) < J:
    max_ones_mult = (N - 2) / 6
    ones = randint(1, max_ones_mult) * 6 - 2
    assert (ones + 2) % 6 == 0
    l = list('1' * ones + '0' * (N-2-ones))
    random.shuffle(l)
    s = '1' + ''.join(l) + '1'
    reps = False
    for fs, _ in found:
        if fs == s:
            reps = True
            break
    if reps:
        continue

    whitnesses = []
    for base in [2, 6, 8]:
        n = int(s, base=base)
        d = PollardRho(n, cutoff=10000)
        if d is None:
            s = None
            break
        else:
            whitnesses.append(d)

    if len(whitnesses) == 3:
        found.append((s, whitnesses))

print 'Case #1:'
for s, (w2, w6, w8) in found:
    whitnesses = [w2, 2, 3, 2, w6, 2, w8, 2, 3]
    for base in range(2, 10 + 1):
        assert int(s, base) % whitnesses[base - 2] == 0
    print s, ' '.join(str(n) for n in whitnesses)



