import sys
t = int(sys.stdin.readline())
for i in range(t):
    n = int(sys.stdin.readline())
    m = {}
    for j in range(2*n - 1):
        h = [int(x) for x in sys.stdin.readline().strip().split()]
        for number in h:
            if not number in m:
                m[number] = 0
            m[number] += 1
    res = []
    for k in m:
        if m[k] % 2 == 1:
            res.append(k)
    res.sort()
    res = [str(x) for x in res]
    print("Case #" + str(i+1) + ": " + " ".join(res))
