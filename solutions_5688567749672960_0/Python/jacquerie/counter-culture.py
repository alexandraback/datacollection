import sys


def parse(f):
    return int(f.readline())


MEMO = {}


def solve(N):
    if N in MEMO:
        return MEMO[N]

    if N == 1:
        result = 1
    else:
        if N % 10 == 0:
            result = 1 + solve(N-1)
        else:
            reverse = int("".join(reversed(str(N))))

            if reverse < N:
                result = 1 + min(solve(N-1), solve(reverse))
            else:
                result = 1 + solve(N-1)

    MEMO[N] = result
    return result


def main():
    with open(sys.argv[1], "r") as input_file:
        for i in xrange(1, 1000001):
            solve(i)

        T = int(input_file.readline())

        for i in xrange(T):
            N = parse(input_file)
            result = MEMO[N]

            print "Case #%d: %d" % (i+1, result)


if __name__ == "__main__":
    main()
