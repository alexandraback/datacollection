def solve(p, s, scores):
    certain, probable = 0, 0
    A, B = 3 * p - 4, 3 * p - 2
    for score in scores:
        if score >= B:
            certain += 1
        elif score >= A:
            probable += score >= 2
    return certain + min(s, probable)

def main():
    N = 0
    with open("problem2.out", "w") as f:
        for case, line in enumerate(open("problem2.in", "r")):
            if case == 0:
                N = int(line)
                continue
            elif case > N:
                break
            nums = map(int, line.split(" "))
            n, s, p = nums[:3]
            scores = nums[3:]
            assert(n == len(scores))
            f.write("Case #{0}: {1}\n".format(case, solve(p, s, scores)))

if __name__ == "__main__":
    main()
