
memo = {}
def best(e, r, v):
    v = tuple(sorted(v))
    key = tuple([e, r, v])
    if key in memo:
        return memo[key]

    if len(v) == 0:
        return 0

    result = 0
    for i in range(e+1):
        payoff_first = v[0] * i
        payoff = payoff_first + best(min(e - i + r, e), r, v[1:])
        result = max(result, payoff)

    memo[key] = result
    return result

assert best(5, 2, [2, 1]) == 12, best(5, 2, tuple([2, 1]))
assert best(5, 2, [1, 2]) == 12, best(5, 2, tuple([1, 2]))
assert best(3, 3, [4, 3, 1, 5]) == 39


def main():
    import sys
    data = open(sys.argv[1] + '.in').readlines()

    out = open(sys.argv[1] + '.out', 'w')

    num = int(data[0])

    data = data[1:]

    for i in range(num):
        e, r, n = map(int, data[0].split())
        v = map(int, data[1].split())

        b = best(e, r, v)
        print 'Case #%i: %i' % (i + 1, b)
        out.write('Case #%i: %i\n' % (i + 1, b))

        data = data[2:]

    out.close()


main()
