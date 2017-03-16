def solve(problem):
    ps = problem
    def possible_breakfast_durations():
        p_max = max(ps)
        for eating_time in range(1, p_max + 1):
            required_special_minutes = sum((p - 1) // eating_time for p in ps)
            yield eating_time + required_special_minutes
    return min(t for t in possible_breakfast_durations())

def parse_problems():
    import fileinput
    fin = fileinput.input()

    T = int(next(fin))
    for _ in range(T):
        D = int(next(fin))
        Ps = list(map(int, next(fin).split()))
        assert(len(Ps) == D)
        assert(D > 0)
        assert(all(p > 0 for p in Ps))
        yield Ps

def main():
    for i, p in enumerate(parse_problems()):
        ans = solve(p)
        print("Case #{}: {}".format(i + 1, ans))

if __name__ == '__main__':
    main()