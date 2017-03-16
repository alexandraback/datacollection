INPUT_FILE = "B-large.in"


def solve(case):
    B, M =  [int(x) for x in case.split(' ')]

    res = [[0] * B for _ in range(B)]

    if M > (2 ** (B-2)):
        return "IMPOSSIBLE"

    for i in range(B-1):
        for j in range(i+1, B):
            res[i][j] = 1

    if M < (2 ** (B-2)):
        res[0][B-1] = 0
        for i in range(B-2):
            d = (M >> i) % 2
            res[0][B - 2 - i] = d

    str_res = "POSSIBLE\n" + '\n'.join([''.join([str(c) for c in r]) for r in res])
    return str_res


def main():
    with open(INPUT_FILE) as fh:
        cases = [l.rstrip() for l in fh.readlines()[1:]]

    sol = ''
    for i in range(len(cases)):
        sol += "Case #{}: {}\n".format(i+1, solve(cases[i]))

    with open(INPUT_FILE.replace('.in', '.out'), 'w') as fh:
        fh.write(sol)

if __name__ == '__main__':
    main()