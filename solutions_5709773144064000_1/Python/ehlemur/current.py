T = int(input())

for t in range(1, T + 1):
    C, F, X = map(float, input().split())

    time = 0
    cookieProduction = 2
    minTime = float("inf")

    while True:
        timeLeft = X / cookieProduction

        if time + timeLeft < minTime:
            minTime = time + timeLeft
        else:
            break

        time += C / cookieProduction
        cookieProduction += F

    print("Case #{}: {:.7f}".format(t, minTime))

