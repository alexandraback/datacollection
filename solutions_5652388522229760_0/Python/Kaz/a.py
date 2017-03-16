#!/usr/local/bin/python3

import fileinput

# N up to 10^6

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
        result = x
    print('Case #{}: {}'.format(i + 1, result))
