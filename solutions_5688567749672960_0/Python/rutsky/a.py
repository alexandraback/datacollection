# Google Code Jam
# Vladimir Rutsky <vladimir@rutsky.org>

import sys


def solve(N):
    dist = [0] + list(range(1, N + 1))

    for cur in range(1, N + 1):
        rev = int(str(cur)[::-1].lstrip("0"))

        dist[cur] = min(dist[cur], dist[cur - 1] + 1)

        if rev >= 1 and rev <= N:
            dist[rev] = min(dist[rev], dist[cur] + 1)

    return dist[N]


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

    T = int(input())
    
    for case_idx in range(T):
        N = int(input())

        result = solve(N)
        
        sys.stdout.write("Case #{0}: {1}\n".format(case_idx + 1, result))


if __name__ == "__main__":
    main()
