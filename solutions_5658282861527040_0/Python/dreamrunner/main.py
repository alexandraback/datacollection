T = int(input())
test = 1

while test <= T:
    print("Case #" + str(test) + ": ", end="")
    test += 1
    line = input().split()
    m = int(line[0])
    n = int(line[1])
    k = int(line[2])
    count = 0
    for i in range(m):
        for j in range(n):
            if i&j < k:
                count += 1
    print(count)