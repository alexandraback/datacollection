def solve(problem):
    A, B, ps = problem
    
    p0 = [1.0 for _ in xrange(A + 1)]
    es = [0 for _ in xrange(A + 1)]
    for i, p in enumerate(ps):
        p0[i + 1] = p * p0[i]

    es = [A + B - 2 * i + 1 + (1 - p) * (B + 1) for i, p in enumerate(p0)]
    es.append(B + 2)
    return min(es)

def problems(fin):
    N = int(fin.next())
    for _ in xrange(N):
        line = fin.next()
        A, B = map(int, line.split(" "))
        line = fin.next()
        ps = map(float, line.split(" "))
        yield A, B, ps

def main():
    with open("problem_1_large.in") as fin:
        with open("problem_1_large.out", "w") as fout:
            for i, problem in enumerate(problems(fin)):
                ans = solve(problem)
                ans = "Case #{0}: {1}\n".format(i + 1, ans)
                print ans,
                fout.write(ans)

if __name__ == "__main__":
    main()
