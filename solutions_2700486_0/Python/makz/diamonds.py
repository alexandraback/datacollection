def fill_row(n):
    return (2 * n + 1) * (n + 1)

def binomial(N,k):
    if (k > N) or (N < 0) or (k < 0):
        return 0L
    N,k = map(long,(N,k))
    top = N
    val = 1L
    while (top > (N-k)):
        val *= top
        top -= 1
    n = 1L
    while (n < k+1L):
        val /= n
        n += 1
    return val

for t in range(input()):
    print "Case #%s:" % str(t + 1),
    n, x, y = map(int, raw_input().split())
    r = (x + y) / 2
    if fill_row(r) <= n:
        print "1.0"
    elif fill_row(r - 1) >= n:
        print "0.0"
    else:
        remaining = n - fill_row(r - 1)
        if remaining > 2 * r + y:
            print "1"
        elif y == 2 * r:
            print "0.0"
        else:
            sum = 0
            for i in range(y + 1, remaining + 1):
                sum += binomial(remaining, i)
            print sum / float(2 ** remaining)
