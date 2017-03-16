def add(s, n):
    while n:
        s.add(n % 10)
        n /= 10

def calc(n):
    if n == 0:
        return 'INSOMNIA'
    s = set()
    m = n
    while True:
        add(s, n)
        if len(s) == 10:
            return str(n)
        n += m

T = int(raw_input())
for i in xrange(T):
    n = int(raw_input())
    print 'Case #%d: %s' % (i + 1, calc(n))
