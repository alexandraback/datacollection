

t = int(input())
for ii in range(1, t+1):
    k, c, s = map(int, input().split())
    if k == s:
        print("Case #{}:".format(ii), " ".join(map(str, range(1, k+1))))
    else:
        print("Case #{}: IMPOSSIBLE".format(ii))
