tests = int(input())

fmt = "Case #{}:"

for t in range(0, tests):
    k, c, kc = [int(x) for x in input().split()]
    if c == 1:
        if kc < k:
            print(fmt.format(t + 1), "IMPOSSIBLE")
        else:
            print(fmt.format(t + 1), *range(1, k + 1))
        continue
    ans = []
    peek = 2
    offset = 0
    while peek <= k:
        ans.append(offset + peek)
        offset = k * peek
        peek += 2
    if peek == k + 1:
        ans.append(k)
    if len(ans) > kc:
        print(fmt.format(t + 1), "IMPOSSIBLE")
    else:
        print(fmt.format(t + 1), *ans)


