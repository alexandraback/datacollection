import fileinput

def problems(fin):
    T = int(next(fin))
    for _ in range(T):
        C, F, X = list(map(float, next(fin).split()))
        yield C, F, X

def solve(problem):
    C, F, X = problem
    f = 2

    Tf, Tx = 0, X / f
    while True:
        Tf, f = Tf + C / f, F + f
        Tx_ = Tf + X / f
        if Tx_ > Tx:
            return Tx
        Tx = Tx_

def main():
    for i, p in enumerate(problems(fileinput.input())):
        ans = solve(p)
        print("Case #{}: {}".format(i + 1, ans))

if __name__ == '__main__':
    main()