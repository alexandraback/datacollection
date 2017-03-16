test = int(input())

for t in range(1, test+1):
    print("Case #" + str(t) + ": ", end="")
    d = int(input())
    p = [int(i) for i in input().split(" ")]
    ans = 1000000
    for i in range(1, max(p)+1):
        tmp = 0
        for n in p:
            tmp += (n-1) // i
        tmp += i
        if tmp < ans:
            ans = tmp
    print(ans)
