n = int(input())
for I in range(1, n+1):
    result = 0
    a,b,k = [int(x) for x in input().split()]
    for i in range(0, a):
        for j in range(0, b):
            c = i & j
            if (c < k):
                result += 1
    print("Case #%d: %d" % (I, result))
