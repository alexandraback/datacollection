import sys
T = int(sys.stdin.readline())


def main():
    for case in range(1, T + 1):
        res = solve(case)
        sys.stdout.write("Case #{}: {}\n".format(case, res))


def solve(case):
    ins = sys.stdin.readline().split()

    r = int(ins[0])
    c = int(ins[1])
    w = int(ins[2])

    count = w + c / w

    if c % w == 0:
        count -= 1

    return count

main()
