T = int(input())
maxk = 0
for t in range(1, T + 1):
    N = int(input())

    bio = 0

    for k in range(100):
        x = k * N
        while x > 0:
            bio |= 1 << (x % 10)
            x //= 10
        if bio == 1023:
            break
    maxk = max(maxk, k)

    if bio == 1023:
        print("Case #{}: {}".format(t, k * N))
    else:
        print("Case #{}: INSOMNIA".format(t))
