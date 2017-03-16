from fractions import Fraction

MAX_DEPTH = 40

def solve(problem):
    P, Q = problem
    x = 1 - Fraction(P, Q)
    m, n = x.numerator, x.denominator

    if n & (n - 1) != 0:
        # n is not power of 2
        return None

    assert x != 0
    for d in range(1, MAX_DEPTH + 1):
        x = 2 * x
        if x <= 1:
            return d
        x -= 1

def parse_problems():
    import fileinput
    fin = fileinput.input()

    def parse_number(type):
        line = next(fin)
        return type(line)

    def parse_list(type, sep=' '):
        line = next(fin)
        nums = line.split(sep)
        return list(map(type, nums))

    T = parse_number(int)
    for _ in range(T):
        P, Q = tuple(parse_list(int, '/'))
        yield P, Q

def main():
    for i, p in enumerate(parse_problems()):
        ans = solve(p)
        res = ans is None and 'impossible' or ans
        print("Case #{}: {}".format(i + 1, res))

if __name__ == '__main__':
    main()