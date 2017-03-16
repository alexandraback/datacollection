

def area(r0, r1):
    return r1 * r1 - r0 * r0

def handle(r, t):
    t -= area(r, r + 1)
    count = 1
    r += 2

    while True:
        attempt = area(r, r + 1)
        if attempt > t:
            break
        t -= attempt
        count += 1
        r += 2

    return count

for case in xrange(int(raw_input())):
    parts = [int(x) for x in raw_input().split()]
    print 'Case #%d: %s' % (case + 1, handle(parts[0], parts[1]))

