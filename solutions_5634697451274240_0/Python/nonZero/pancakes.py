import re

# IN = "pancakes.sample.in.txt"
# OUT = "pancakes.sample.out.txt"

IN = "B-small-attempt0.in"
OUT = "pancakes.small.out.txt"


# IN = "B-large.in"
# OUT = "pancakes.large.out.txt"

RE = re.compile(r'\++|-+')


def solve(s0: str):
    s = s0.rstrip('+')
    if not(s):
        return 0
    s = RE.sub("!", s)
    return len(s)


with open(IN) as f, open(OUT, "w") as fw:
    T = int(f.readline())
    for i in range(1, T + 1):
        S = f.readline().strip()
        print("Case #{}: {}".format(i, solve(S)), file=fw)

print("Done.")
