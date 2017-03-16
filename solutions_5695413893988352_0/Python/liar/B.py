import logging

def solve(problem):
    t1, t2 = problem
    templates = list(zip(t1, t2))
    templates.reverse()
    ns1, ns2 = "", ""
    ps1, ps2 = "", ""
    zs1, zs2 = "", ""

    def abs_diff(scores):
        s1, s2 = scores
        return abs(int(s1) - int(s2))

    for d1, d2 in templates:
        c1, c2 = d1, d2
        if d1 == "?" and d2 == "?":
            candidates = [
                ("0" + zs1, "0" + zs2),
                ("0" + ps1, "1" + ps2),
                ("1" + ns1, "0" + ns2),
            ]
        elif d1 == "?":
            candidates = [
                (d2 + zs1, d2 + zs2),
                (str(int(d2) - 1) + ps1, d2 + ps2),
                (str(int(d2) + 1) + ns1, d2 + ns2),
            ]
        elif d2 == "?":
            candidates = [
                (d1 + zs1, d1 + zs2),
                (d1 + ps1, str(int(d1) + 1) + ps2),
                (d1 + ns1, str(int(d1) - 1) + ns2),
            ]
        else:
            candidates = [
                (d1 + zs1, d2 + zs2),
                (d1 + ps1, d2 + ps2),
                (d1 + ns1, d2 + ns2),
            ]
        zs1, zs2 = min(sorted((s1, s2) for s1, s2 in candidates if len(s1) == len(s2)), key=abs_diff)

        ns1 = (d1 == "?" and "0" or d1) + ns1
        ps1 = (d1 == "?" and "9" or d1) + ps1
        ns2 = (d2 == "?" and "9" or d2) + ns2
        ps2 = (d2 == "?" and "0" or d2) + ps2
    return zs1 + " " + zs2

def parse_problems():
    import fileinput
    fin = fileinput.input()

    T = int(next(fin))
    for _ in range(T):
        t1, t2 = next(fin).strip().split()
        yield t1, t2

def main():
    import time
    logging.basicConfig(level=logging.INFO, format="%(message)s")

    t0 = time.time()
    logging.info("Starting...")
    for i, p in enumerate(parse_problems()):
        ans = solve(p)
        logging.info("Solved #%d", i + 1)
        print("Case #{}: {}".format(i + 1, ans))
    logging.info("Finished in %.2f s", time.time() - t0)

if __name__ == '__main__':
    main()