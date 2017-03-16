def solve(problem):
    s_max, counts = problem
    ans = 0
    standing = 0
    for s in range(s_max + 1):
        if standing < s:
            ans += s - standing
            standing = s
        standing += counts[s]
    return ans

def parse_problems():
    import fileinput
    fin = fileinput.input()

    T = int(next(fin))
    for _ in range(T):
        S, H = next(fin).split()
        S, H = int(S), list(map(int, H))
        yield S, H

def main():
    for i, p in enumerate(parse_problems()):
        ans = solve(p)
        print("Case #{}: {}".format(i + 1, ans))

if __name__ == '__main__':
    main()