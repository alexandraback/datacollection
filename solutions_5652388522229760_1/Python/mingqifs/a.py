T = int(input())
for i in range(1,T+1):
    s = set()
    n = int(input())
    now = 0
    if n == 0:
        print("Case #{0}: INSOMNIA".format(i))
        continue

    while True:
        now += n
        tmp = now
        while tmp != 0:
            s.add(tmp % 10)
            tmp //= 10

        if len(s) == 10:
            print("Case #{0}: {1}".format(i, now))
            break



