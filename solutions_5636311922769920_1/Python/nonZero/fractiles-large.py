# IN = "fractiles.sample.in.txt"
# OUT = "fractiles.sample.out.txt"

# IN = "D-small-attempt0.in"
# OUT = "fractiles.small.out.txt"


IN = "D-large.in"
OUT = "fractiles.large.out.txt"


def solve(k, c):
    solution = []
    i = 0
    while True:
        n = 0
        for j in range(c):
            n += i * (k ** (c - j - 1))
            i += 1
            if i == k:
                break
        solution.append(n + 1)
        if i == k:
            return solution


TOO_MUCH = 10 ** 18

# for K in range(1, 101):
#     for C in range(1, 101):
#         print(K, C, end=": ")
#         if K ** C >= TOO_MUCH:
#             print("too much")
#             break
#         n = K ** (C - 1)
#         sol = solve(K, C)
#         print(len(sol), sol)

with open(IN) as f, open(OUT, "w") as fw:
    T = int(f.readline())
    for i in range(1, T + 1):
        K, C, S = map(int, f.readline().split())
        assert 1 <= S <= K
        assert K ** C <= TOO_MUCH
        n = K ** (C - 1)
        sol = solve(K, C)
        # print(K, C, S, sol)
        solution = " ".join(str(x) for x in sol) if S >= len(
            sol) else "IMPOSSIBLE"
        print("Case #{}: {}".format(i, solution), file=fw)

print("Done.")
