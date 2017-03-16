T = int(input())

for t in range(T):
    d = int(input())
    ps = list(map(int, input().split()))

    maxp = max(ps)


    results = []
    for h in range(1, maxp+1):
        specials = 0

        for p in ps:
            s = 0
            if h < p:
                s = p // h
                if p % h == 0:
                    s -= 1

            specials += s

        results.append(specials + h)

    print("Case #" + str(t+1) + ": " + str(min(results)))

        



