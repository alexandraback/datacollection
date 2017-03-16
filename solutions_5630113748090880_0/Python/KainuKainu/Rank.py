T = int(input())
D = 1
while (D<=T):
    N = int(input())
    d = {}
    ans = []
    for _ in range(2*N-1):
        l = [int(num) for num in input().split()]
        for x in l:
            if x in d: d[x] += 1
            else: d[x] = 1
    for x in d:
        if d[x]%2: ans.append(x)
    ans.sort()
    print("Case #" + str(D) + ":", end="")
    for x in ans:
        print(" " + str(x),end="")
    print("")
    D += 1
