import itertools

def divisor(x):
    for i in range(2, int(x ** 0.5) + 2):
        if x % i == 0:
            return i

    return None


def gen(N):
    for i in range(1 << (N - 2)):
        binary = bin((i << 1) | 1 | (1 << (N - 1)))[2:]

        divisors = []
        for base in range(2, 10 + 1):
            x = int(binary, base)

            d = divisor(x)
            if d is None:
                break

            # XXX
            #divisors.append(x)

            divisors.append(d)
        else:
            yield binary, divisors


def gen2(N):
    for even_comb in itertools.combinations(range((N - 2) // 2), 4):
        for odd_comb in itertools.combinations(range((N - 2) // 2), 4):
            b = [1] + [0] * (N - 2) + [1]
            for idx in even_comb:
                b[idx * 2 + 1] = 1
            for idx in odd_comb:
                b[idx * 2 + 2] = 1

            binary_str = "".join(map(str, b))

            divisors = []
            for base in range(2, 10 + 1):
                x = int(binary_str, base)

                if base in [3, 5, 7, 9]:
                    assert x % 2 == 0
                    divisors.append(2)

                elif base in [2, 8]:
                    assert x % 3 == 0
                    divisors.append(3)

                elif base in [6]:
                    assert x % 5 == 0
                    divisors.append(5)

                elif base in [4]:
                    assert x % 5 == 0
                    divisors.append(5)

                elif base in [10]:
                    assert x % 11 == 0
                    divisors.append(11)

                else:
                    assert False

                # XXX
                # divisors.append(x)

            yield binary_str, divisors


def solve(N, J):
    g = gen2(N)

    res = []
    for i in range(J):
        binary, divisors = next(g)

        s = binary + " " + " ".join(map(str, divisors))
        res.append(s)

        validate(s)

    return "\n" + "\n".join(res)


def validate(line):
    binary_str, *divisors = line.split()
    divisors = map(int, divisors)

    for base, div in zip(range(2, 10 + 1), divisors):
        assert int(binary_str, base) % div == 0

if False:
    assert solve("+") == 0
    assert solve("++") == 0
    assert solve("-") == 1
    assert solve("--") == 1
    assert solve("-+") == 1
    assert solve("+-") == 2
    assert solve("--+-") == 3

else:
    T = int(input())

    for case_idx in range(T):
        N, J = map(int, input().split())

        print("Case #{}: {}".format(case_idx + 1, solve(N, J)))
