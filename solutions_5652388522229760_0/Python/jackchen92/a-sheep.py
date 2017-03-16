def get_digits(x, digits):
    while x:
        digits.add(x % 10)
        x /= 10

def solve(n):
    if n == 0: return None
    digits = set()
    x = n
    while True:
        get_digits(x, digits)
        if len(digits) == 10:
            return x
        x += n

def main():
    T = int(raw_input())
    for t in xrange(1, T+1):
        n = int(raw_input())
        r = solve(n)
        print 'Case #%d: %s' % (t, r if r else 'INSOMNIA')

main()
