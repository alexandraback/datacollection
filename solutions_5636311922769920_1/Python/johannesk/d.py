def solve(k, c, s):
    def index(p): return 1+sum(x*(k**i) for i, x in enumerate(p))
    a = [index(((j if j<k else 0) for j in reversed(range(i, i+c)))) for i in range(0, k, c)]
    return "IMPOSSIBLE" if len(a)>s else ' '.join(map(str, a))

for t in range(int(input())):
    print("Case #{}: {}".format(t+1, solve(*map(int, input().split()))))
