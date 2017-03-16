# IN = "fractiles.sample.in.txt"
# OUT = "fractiles.sample.out.txt"
#

IN = "D-small-attempt0.in"
OUT = "fractiles.small.out.txt"

# IN = "D-large.in"
# OUT = "fractiles.large.out.txt"


def solve(n):
    if not n:
        return None
    seen = set()
    x = n
    while True:
        seen.update([c for c in str(x)])
        if len(seen) == 10:
            return x
        x += n


TOO_MUCH = 10 ** 18

with open(IN) as f, open(OUT, "w") as fw:
    T = int(f.readline())
    for i in range(1, T + 1):
        K, C, S = map(int, f.readline().split())
        assert K == S  # Small dataset
        assert K ** C <= TOO_MUCH
        n = K ** (C - 1)
        print("Case #{}: {}".format(i, " ".join(
            str(x * n + 1) for x in range(K))), file=fw)

print("Done.")
