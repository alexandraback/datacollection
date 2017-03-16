n_case = int(input())
for index in range(0, n_case):
    C, F, X = map(float, input().split())
    ans = X / 2
    time = 0
    speed = 2
    while True:
        wait = time + X / speed
        ans = min(ans, wait)
        if wait > ans: break
        time += C / speed
        speed += F
    print("Case #%d: %.10f" % (index + 1, ans))
