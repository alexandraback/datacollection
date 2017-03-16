def solve(problem):
    A, B, K = problem
    ans = 0
    for x in range(A):
        for y in range(B):
            if (x & y) < K:
                ans += 1
    return ans


def parse_problems():
    import fileinput
    fin = fileinput.input()

    def parse_number(type):
        line = next(fin)
        return type(line)

    def parse_list(type):
        line = next(fin)
        nums = line.split()
        return list(map(type, nums))

    T = parse_number(int)
    for _ in range(T):
        A, B, K = tuple(parse_list(int))
        yield A, B, K

def main():
    for i, p in enumerate(parse_problems()):
        ans = solve(p)
        print("Case #{}: {}".format(i + 1, ans is None and 'NOT POSSIBLE' or ans))

if __name__ == '__main__':
    main()