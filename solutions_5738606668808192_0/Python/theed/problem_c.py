import sys

many = 1000000
PRIMES = [2]
for n in range(3, many):
    for p in PRIMES:
        if p * p > n:
            PRIMES.append(n)
            break
        if n % p == 0:
            break
    else:
        PRIMES.append(n)

print('primes computed')


def divisor(number):
    for p in PRIMES:
        if p >= number:
            return False
        if number % p == 0:
            return p
    return False


def jamcoin(n, j):
    result = []
    for candidate in range(2 ** (n - 1) + 1, 2 ** n, 2):
        valid = True
        base_2 = "{0:b}".format(candidate)
        explanation = []
        for base in range(2, 11):
            convert = int(base_2, base)
            div = divisor(convert)
            if div is False:
                valid = False
                break
            explanation.append(div)
        if valid:
            result.append((base_2, explanation))
        if len(result) == j:
            return result
    assert False


def main():
    name = sys.argv[1]
    with open(name, 'r') as f:
        content = f.read()
    lines = content.splitlines()
    num = lines[0]
    result = ''
    for n in range(int(num)):
        s_n, s_j = lines[n + 1].split(' ')
        data = jamcoin(int(s_n), int(s_j))
        result += 'Case #{}:\n'.format(1 + n)
        for coin, explanation in data:
            result += '{} '.format(coin)
            str_exp = [str(x) for x in explanation]
            result += ' '.join(str_exp) + '\n'

    with open(name.replace('in', 'sol'), 'w') as f:
        f.write(result)


def test():
    cases = [
        (6, 3),
        (16, 50),
        (32, 500),
    ]
    for length, number in cases:
        actual = jamcoin(length, number)
        for coin, explanation in actual:
            assert len(coin) == length, 'failed length on {}, {}'.format(length, number)
            assert coin[0] == coin[-1] == '1', 'failed 1 on {}, {}'.format(length, number)
            for i, div in enumerate(explanation):
                assert div != 1 and div < int(coin, i + 2)
                assert int(coin, i + 2) % div == 0, 'failed valid on {}, {}'.format(length, number)


if __name__ == '__main__':
    main()
