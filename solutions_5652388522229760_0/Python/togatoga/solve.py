T = int(input())
for i in range(T):
    N = int(input())
    if (N == 0):
        print ("Case #%d: INSOMNIA" % (i + 1))
        continue
    digits = set()
    base = N
    while (True):
        for x in str(N):
            digits.add(x)
        if (len(digits) == 10):
            break
        N += base
    print ("Case #%d: %d" % (i + 1, N))
