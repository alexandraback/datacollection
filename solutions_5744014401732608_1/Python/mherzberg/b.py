T = int(input())
for t in range(T):
    (B, M) = [int(x) for x in input().split()]

    if (2**(B-2) < M):
        print("Case #" + str(t+1) + ": IMPOSSIBLE")
        continue
    print("Case #" + str(t+1) + ": POSSIBLE")

    firstline = "0"
    tmp = M - 1
    for b in range(B - 3, -1, -1):
        if (tmp >= (2**b)):
            firstline += "1"
            tmp -= (2**b)
        else:
            firstline += "0"
    firstline += "1"
    print(firstline)

    for b in range(B - 1):
        print("0" * (b + 2) + "1" * (B - 2 - b))

