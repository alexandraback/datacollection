t = int(input())
for i in range(1, t+1):

    original = int(input())
    n = original
    if original == 0:
        print("Case #%d: INSOMNIA" % i)
        continue
    seen_set = set()

    while len(seen_set) != 10:
        n_digits = list(str(n))
        for digit in n_digits:
            seen_set.add(digit)
        n += original
    print("Case #%d: %d" % (i, n-original))