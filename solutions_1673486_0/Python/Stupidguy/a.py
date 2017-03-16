t = input()
for testcase in range(1, t+1):
    a, b = map(int, raw_input().split())
    p = map(float, raw_input().split())
    currp, currmin = 1, float(b + 2)
    for k in range(a):
        currp *= p[k]
        currmin = min(currmin, 
            a + b - 2 * k - 1 + (b + 1) * (1 - currp))
    print "Case #" + str(testcase) + ": " + str(currmin)


