from solver import solver

def gen_indexes(k, c):
    for s in range(0, k, c):
        yield 1 + sum(
            (x % k) * k ** i
            for i, x in enumerate(range(s, s+c)))

@solver
def fractile(lines):
    k, c, s = map(int, lines[0].split())
    if c * s < k:
        return 'IMPOSSIBLE'
    return ' '.join(map(str, gen_indexes(k, c)))

if __name__ == '__main__':
    fractile.from_cli()
