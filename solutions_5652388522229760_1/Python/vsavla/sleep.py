t = int(input())

for i in range(1, t+1):
    original = int(input())
    n = original
    if original == 0:
        print("Case #%d: INSOMNIA" % i)
        continue
    seen_bool = [False] * 10
    while False in seen_bool:
        n_digits = list(str(n))
        for digit in n_digits:
            seen_bool[int(digit)] = True
        n += original
    print("Case #%d: %d" % (i, n-original))