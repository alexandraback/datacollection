from sys import stdout

inf = open("A-small-attempt0.in", "r")
ouf = open("a.out", "w")
T = int(inf.readline())
for t in range(T):
    print("Case #", (t + 1), ": ", sep="", end="", file=ouf)
    [x, n] = [int(x) for x in inf.readline().split()]
    a = [int(x) for x in inf.readline().split()]
    if x == 1:
        print(n, file=ouf)
        continue
    a = sorted(a)
    res = n
    added = 0
    cur = x
    num = 0
    while num < n:
        if a[num] < cur:
            cur += a[num]
            num += 1
        else:
            cur += cur - 1
            added += 1

        if res > added + (n - num):
            res = added + (n - num)
    print(res, file=ouf)

inf.close()
ouf.close()    

