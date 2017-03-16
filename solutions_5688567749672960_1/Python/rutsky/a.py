# Google Code Jam
# Vladimir Rutsky <vladimir@rutsky.org>

import sys


def count_to_10_in_k(k):
    assert k >= 1

    if k == 1:
        return 10

    res = count_to_10_in_k(k - 1)

    if k % 2 == 0:
        c = k // 2
        res1 = 10 ** c
        res2 = 10 ** c - 1
    else:
        c = (k - 1) // 2
        res1 = 10 ** c
        res2 = 10 ** (c + 1) - 1

    return res + res1 + res2


def solve_old(N):
    dist = [0] + list(range(1, N + 1))

    for cur in range(1, N + 1):
        rev = int(str(cur)[::-1].lstrip("0"))

        dist[cur] = min(dist[cur], dist[cur - 1] + 1)

        if rev >= 1 and rev <= N:
            dist[rev] = min(dist[rev], dist[cur] + 1)

    return dist[N]


def solve(N):
    if N < 10:
        return N

    k = len(str(N))
    c0 = count_to_10_in_k(k - 1)

    part1 = str(N)[:k // 2]
    part2 = str(N)[k // 2:]

    if part1 == str(10 ** (k // 2 - 1)):
        c2 = int(part2)
        return c0 + c2

    elif int(part2) == 0:
        res = solve(N - 1) + 1
        return res

    else:
        c1 = int(part1[::-1])
        c2 = int(part2)

        res = c0 + c1 + c2

        return res


def main():
    if len(sys.argv) > 2:
        print(
            "Usage:\n"
            "    {} [input.in]".format(sys.argv[0]))
        sys.exit(1)

    elif len(sys.argv) == 2:
        suffix = ".in"

        input_path = sys.argv[1]
        assert input_path.endswith(suffix)

        output_path = input_path[:-len(suffix)] + ".out"

        print("DEBUG: Reading from '{}', writing to '{}'.".format(
                input_path, output_path),
            file=sys.stderr)

        sys.stdin = open(input_path, "rt")
        sys.stdout = open(output_path, "wt")

    else:
        print("DEBUG: Reading from STDIN, writing to STDOUT.", file=sys.stderr)

    #old = solve_old(10000)
    #new = solve(10000)
    #assert old == new

    #solve(10**4)
    #assert False

    T = int(input())
    
    for case_idx in range(T):
        N = int(input())

        result = solve(N)
        
        sys.stdout.write("Case #{0}: {1}\n".format(case_idx + 1, result))


if __name__ == "__main__":
    main()
