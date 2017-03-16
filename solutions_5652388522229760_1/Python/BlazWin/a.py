n = int(input())

for t in range(0, n):
    num = int(input())
    if num == 0:
        print("Case #{}: {}".format(t + 1, "INSOMNIA"))
        continue
    m = set()
    it = 1
    while len(m) < 10:
        for c in str(num * it):
            m.add(c)
        it += 1
    print("Case #{}: {}".format(t + 1, num * (it - 1)))
