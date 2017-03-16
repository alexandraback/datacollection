# IN = "sheep.sample.in.txt"
# OUT = "sheep.sample.out.txt"

# IN = "A-small-attempt0.in"
# OUT = "sheep.small.out.txt"

IN = "A-large.in"
OUT = "sheep.large.out.txt"


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


# for n in range(1, 1000001):
#     print(n, solve(n))



with open(IN) as f, open(OUT, "w") as fw:
    T = int(f.readline())
    for i in range(1, T + 1):
        N = int(f.readline())
        print("Case #{}: {}".format(i, solve(N) or "INSOMNIA"), file=fw)

print("Done.")