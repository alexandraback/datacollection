def process(c, f, x):
    if x <= c:
        return x / 2.0

    ans = x / 2.0

    rate = 2.0
    cuml = 0.0

    for i in range(800000):
        if ans > cuml + x / rate:
            ans = cuml + x / rate
        cuml += c / rate
        rate += f

    return ans

for i in range(1, input()+1):
    print "Case #{}: {}".format(
            i,
            process(*map(float, raw_input().split()))
        )

