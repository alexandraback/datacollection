def coin_to_base(coin, b):
    return reduce(lambda a, n: b * a + int(n), coin, 0)

def first_factor(x):
    for i in range(2, 20):
        if not x % i:
            return i

def jamcoin(n, j):
    results = []
    for i in xrange(2 ** (n - 2)):
        coin = '1{{:0{}b}}1'.format(n - 2).format(i)
        factors = []
        for i in range(2, 11):
            factors.append(first_factor(coin_to_base(coin, i)))
        if all(factors):
            results.append(' '.join([coin] + map(str, factors)))
        if len(results) == j:
            break
    return '\n'.join(results)

if __name__ == '__main__':
    cases = int(raw_input())
    for i in range(cases):
        print("Case #%s:\n%s" %
              (i+1, jamcoin(*map(int, raw_input().split()))))
