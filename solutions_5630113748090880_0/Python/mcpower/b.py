cases = int(input())
for case in range(cases):
    n = int(input())
    x = [0 for i in range(2567)]
    for i in range(2*n-1):
        for num in map(int, input().split()):
            x[num] += 1
    out = []
    for i, thing in enumerate(x):
        if thing % 2 == 1:
            out.append(i)
    out.sort()
    ans = " ".join(map(str, out))
    print("Case #{}: {}".format(case+1, ans))
