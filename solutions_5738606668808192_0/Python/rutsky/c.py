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


def solve(N, J):
    g = gen(N)

    res = []
    for i in range(J):
        binary, divisors = next(g)

        s = binary + " " + " ".join(map(str, divisors))
        res.append(s)

    return "\n" + "\n".join(res)

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
