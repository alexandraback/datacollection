import fileinput

def read_floats(fin):
    line = next(fin)
    nums = line.split()
    return list(map(float, nums))

def problems(fin):
    T = int(next(fin))
    for _ in range(T):
        N = int(next(fin))
        w1 = read_floats(fin)
        w2 = read_floats(fin)
        assert len(w1) == N
        assert len(w2) == N
        yield w1, w2

def play0(w1, w2):
    lost = 0
    lo, hi = 0, len(w2) - 1
    for m1 in w1:
        if m1 > w2[hi]:
            break
        if m1 > w2[lo]:
            lo = lo + 1
            continue
        if m1 < w2[lo]:
            lost, hi = lost + 1, hi - 1
            continue
        assert False
    return len(w1) - lost

def play1(w1, w2):
    lost = 0
    i1, i2 = len(w1) - 1, len(w2) - 1
    while i1 >= 0 and i2 >= 0:
        m1, m2 = w1[i1], w2[i2]
        if m2 > m1:
            i1, i2, lost = i1 - 1, i2 - 1, lost + 1
            continue
        if m2 < m1:
            i1 = i1 - 1
            continue
        assert False

    return len(w1) - lost

def solve(problem):
    w1, w2 = problem
    w1, w2 = sorted(w1), sorted(w2)
    return "{} {}".format(play0(w1, w2), play1(w1, w2))

# def test(l):
#     import bisect
#     def war(w1, w2):
#         ans = 0
#         w2 = list(w2)
#         for m1 in w1:
#             i = bisect.bisect_left(w2, m1)
#             if i >= len(w2):
#                 ans += 1
#                 w2.pop(0)
#             else:
#                 w2.pop(i)
#         return ans

#     from itertools import permutations, combinations
#     s = set(range(2 * l))
#     for c in combinations(s, l):
#         w1 = sorted(c)
#         w2 = sorted(s - set(c))
#         R1 = max(war(w, w2) for w in permutations(w1))
#         R2 = play1(w1, w2)
#         print("{} vs {}: {} = {}".format(w1, w2, R1, R2))
#         assert R1 == R2

def main():
    for i, p in enumerate(problems(fileinput.input())):
        ans = solve(p)
        print("Case #{}: {}".format(i + 1, ans))

if __name__ == '__main__':
    main()