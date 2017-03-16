def addItr(b, c, currP, maxP):
    if c == 1:
        for i in range(1, len(b)-1):
            b[0][i] = "1"
            b[i][-1] = "1"
            currP += 1
            if currP == maxP:
                break
    else:
        for i in range(1, len(b)-1):
            j = i + c - 1
            if j < len(b)-1:
                b[i][j] = "1"
                currP += 1
                if currP == maxP:
                    break
            else:
                break
    return (b, currP)


cases = int(input())

for c in range(cases):
    n, p = map(int, input().split())

    maxP = 1 + (((n - 2) * (n - 1)) / 2)

    if p > maxP:
        print("Case #" + str(c+1) + ":", "IMPOSSIBLE")
        continue
    else:
        print("Case #" + str(c+1) + ":", "POSSIBLE")

    # Construct buildings.
    b = []
    for i in range(n):
        b2 = ["0" for j in range(n)]
        b.append(b2)

    b[0][-1] = "1"

    currP = 1
    curr = 1
    while currP < p:
        b, addP = addItr(b, curr, currP, p)
        currP = addP
        curr += 1

    # Print buildings.
    for i in range(len(b)):
        print("".join(b[i]))
