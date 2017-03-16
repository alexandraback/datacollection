MULTIPLY_TABLE = {
    (" ", " "): (+1, " "), (" ", "i"): (+1, "i"), (" ", "j"): (+1, "j"), (" ", "k"): (+1, "k"),
    ("i", " "): (+1, "i"), ("i", "i"): (-1, " "), ("i", "j"): (+1, "k"), ("i", "k"): (-1, "j"),
    ("j", " "): (+1, "j"), ("j", "i"): (-1, "k"), ("j", "j"): (-1, " "), ("j", "k"): (+1, "i"),
    ("k", " "): (+1, "k"), ("k", "i"): (+1, "j"), ("k", "j"): (-1, "i"), ("k", "k"): (-1, " "),
}

ONE = (+1, " ")

def acc_left(acc, x):
    sgn0, val0 = acc
    sgn1, val1 = MULTIPLY_TABLE[(val0, x)]
    return sgn0 * sgn1, val1

def acc_rght(acc, x):
    sgn0, val0 = acc
    sgn1, val1 = MULTIPLY_TABLE[(x, val0)]
    return sgn0 * sgn1, val1

def partial_folds(acc, f, xs):
    yield acc
    for x in xs:
        acc = f(acc, x)
        yield acc

def find_partial_fold(acc, f, xs, match):
    for idx, p in enumerate(partial_folds(acc, f, xs)):
        if p == match:
            return idx
    return None

def product(word):
    acc = ONE
    for x in word:
        acc = acc_left(acc, x)
    return acc

def pow(word, n):
    sgn0, val0 = product(word)
    sgn1, val1 = product(val0 * (n % 4))
    return sgn0 ** (n % 2) * sgn1, val1

def solve(problem):
    w, x = problem
    L = len(w) * x
    if pow(w, x) != product("ijk"):
        return "NO"
    wi, wk = w, w[-1::-1]
    i = find_partial_fold(ONE, acc_left, wi * min(4, x), (+1, "i"))
    k = find_partial_fold(ONE, acc_rght, wk * min(4, x), (+1, "k"))
    if i is None or k is None:
        return "NO"
    if i + k >= L:
        return "NO"
    return "YES"

def parse_problems():
    import fileinput
    fin = fileinput.input()

    T = int(next(fin))
    for _ in range(T):
        L, X = list(map(int, next(fin).split()))
        w = next(fin).strip()
        assert(0 < L <= 10000)
        assert(0 < X)
        assert(len(w) == L)
        yield w, X

def main():
    for i, p in enumerate(parse_problems()):
        ans = solve(p)
        print("Case #{}: {}".format(i + 1, ans))

if __name__ == '__main__':
    main()