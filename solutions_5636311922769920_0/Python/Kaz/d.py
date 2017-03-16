#!/usr/local/bin/python3

import fileinput

# k: len base sequence
# c: exponent
# s: number of values that can be selected

def val(k, c, tests):
    x = 0
    for n in sorted(tests):
        x *= k
        x += n
    return x

for cs, case in enumerate(list(fileinput.input())[1:]):
    k, c, s = (int(x) for x in case.split())

    if s * c < k:
        result = 'IMPOSSIBLE'
    else:
        ks = range(k)
        i = 0
        tests = []
        while i < k:
            tests += [val(k, c, ks[i:i+c]) + 1]
            i += c
        result = ' '.join(str(x) for x in tests)

    print('Case #{}: {}'.format(cs + 1, result))
