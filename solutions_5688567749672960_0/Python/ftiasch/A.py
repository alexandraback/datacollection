def solve(n):
    result = 0
    while n > 10:
        if n % 10 == 0:
            n -= 1
            result += 1
        l = len(str(n))
        high = str(n)[:l / 2]
        low  = str(n)[l / 2:]
        if int(high) == pow(10, l / 2 - 1):
            result += int(low)
        else:
            result += 1
            result += int(''.join(reversed(high)))
            result += int(low) - 1
        n = pow(10, l - 1)
    return result + n

for t in xrange(input()):
    print "Case #%d: %d" %(t + 1, solve(input()))
