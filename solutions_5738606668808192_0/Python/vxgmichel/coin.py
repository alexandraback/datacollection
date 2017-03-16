from solver import solver
from itertools import islice

PRIMES = [2, 3, 5, 7]

def div(x):
    for k in PRIMES:
        if not x%k:
            return k

def gen_coin(n):
    form = '0{}b'.format(n-2)
    for x in range(2**(n-2)):
        coin = '1' + format(x, form) + '1'
        proof = [div(int(coin, base)) for base in range(2, 11)]
        if all(proof):
            yield coin, proof

@solver
def coin(lines):
    n, j = map(int, lines[0].split())
    res = [[c] + p for c, p in islice(gen_coin(n), j)]
    out = [' '.join(map(str, x)) for x in res]
    return '\n' + '\n'.join(map(str, out))

if __name__ == '__main__':
    coin.from_cli()
