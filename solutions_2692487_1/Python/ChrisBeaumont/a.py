def memoize(fun):
    memo = {}
    def result(*args):
        if args not in memo:
            memo[args] = fun(*args)
        return memo[args]
    return result

@memoize
def solve(a, other):
    if len(other) == 0: # all absorbed
        return 0

    if a > other[0]: # can absorb next guy
        return solve(a + other[0], other[1:])

    #option 1: add a helper
    if a > 1:
        o1 = 1 + solve(2 * a - 1, other)
    else:
        o1 = 9999999999999

    #option 2: remove largest
    o2 = 1 + solve(a, other[:-1])

    return min([o1, o2])


assert solve(2, tuple([1, 2])) == 0
assert solve(2, tuple([1, 1, 2, 6])) == 1
assert solve(10, tuple([9, 20, 25, 100])) == 2, solve(25, tuple([9, 20, 25, 100]))
assert solve(1, tuple([1, 1, 1, 1])) == 4

ms = tuple([1000000] * 100)
a = 1
solve(a, ms)


def main():
    import sys
    data = open(sys.argv[1] + '.in').readlines()

    outfile = open(sys.argv[1] + '.out', 'w')

    t = int(data[0])
    data = data[1:]

    for i in range(1, t+1):
        a, n = map(int, data[0].split())
        ms = map(int, data[1].split())
        ms = tuple(sorted(ms))
        data = data[2:]
        print 'Case #%i: %i' % (i, solve(a, ms))
        outfile.write('Case #%i: %i\n' % (i, solve(a, ms)))

    outfile.close()

if __name__ == '__main__':
    main()
