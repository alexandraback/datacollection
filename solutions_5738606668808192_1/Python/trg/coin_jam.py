import itertools


def coin_in_base(seq, b):
    return sum(b ** i for i, el in enumerate(seq) if el)


def coin_repr(seq):
    return ''.join('1' if el else '0' for el in reversed(seq))


def generate_coins(n):
    for base_seq in itertools.product([True, False], repeat=n - 2):
        seq = (True, ) + base_seq + (True,)
        d_map = {}
        for b in range(2, 11):
            for d in [3, 5, 7, 11, 13, 17, 19, 23]:
                if coin_in_base(seq, b) % d == 0:
                    d_map[b] = d
                    break

        if len(d_map) < 9:
            continue

        yield seq, d_map


def case(n, j):
    for i, (seq, d_map) in enumerate(generate_coins(n)):
        if i == j:
            break
        divisors_str = ' '.join(str(d_map[b]) for b in range(2, 11))
        print('{0} {1}'.format(coin_repr(seq), divisors_str))


def main1():
    print('Case #1:')
    case(16, 50)


def main2():
    print('Case #1:')
    case(32, 500)


if __name__ == '__main__':
    main2()
