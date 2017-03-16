#!/usr/local/bin/python3

import fileinput

for i, n in enumerate(list(fileinput.input())[1:]):
    n = int(n)
    if n == 0:
        result = 'INSOMNIA'
    else:
        letters = set()
        x = 0
        while True:
            x += n
            letters = letters.union(str(x))
            if len(letters) == 10:
                break
            if x > n * 100:
                result = 'INSOMNIA'
        result = x
    print('Case #{}: {}'.format(i + 1, result))
