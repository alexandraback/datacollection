import itertools


def read_n_int(n):
    ints = [int(s) for s in input().split(" ")]
    if len(ints) != n:
        raise ValueError('Expected %i ints, got %i' % (n, len(ints)))
    if n == 1:
        return ints[0]
    return ints


def get_div(n):
    for i in range(2, 10000):
        if (n % i) == 0:
            return i
    return None


def get_primes(length, count):
    cnt = 0
    for i in itertools.product('01', repeat=length - 2):
        n = ''.join(('1',) + i + ('1',))
        ds = []
        for b in range(2, 11):
            nb = int(n, b)
            d = get_div(nb)
            if d is None:
                break
            ds.append(str(d))
        else:
            print(' '.join([n] + ds))
            cnt += 1
            if cnt == count:
                return


t = read_n_int(1)
for i in range(1, t + 1):
    n, j = read_n_int(2)
    print("Case #%i:" % i)
    get_primes(n, j)
