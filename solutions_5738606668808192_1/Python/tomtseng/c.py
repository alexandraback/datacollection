N = 32
J = 500
MAXDIV = 1000

def conv(n, base):
    num = 1

    for _ in xrange(N-2):
        num = num*base + (n & 1)
        n >>= 1

    return num*base + 1

n = 0

print "Case #1:"

while J != 0:
    divs = []
    success = True

    for b in xrange(2, 11):
        c = conv(n, b)

        if c % 2 == 0:
            divs.append(2)
            continue

        bs = False

        m = min(MAXDIV, int(c ** 0.5))

        for i in xrange(3, m+1, 2):
            if c % i == 0:
                divs.append(i)
                bs = True
                break

        if not bs:
            success = False
            break

    if success:
        J -= 1

        print conv(n, 10),
        for d in divs:
            print d,
        print ""

    n+=1
