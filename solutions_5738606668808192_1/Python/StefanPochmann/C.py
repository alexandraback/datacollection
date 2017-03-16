from __future__ import print_function

def div(i):
    return next((p for p in (2, 3, 5, 7, 11) if i % p == 0), 0)

for x in range(1, input() + 1):
    N, J = map(int, raw_input().split())
    print('Case #%d:' % x)
    c = 2**(N-1) + 1
    while J:
        coin = bin(c)[2:]
        divs = [div(int(coin, base)) for base in range(2, 11)]
        if all(divs):
            print(coin, *divs)
            J -= 1
        c += 2
