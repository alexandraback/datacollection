import sys

def digits(n):
    if n == 0: return set([0])
    ret = set([])
    while True:
        if n == 0: break
        ret.add(n % 10)
        n = n / 10
    return ret

def solve(n):
    if n == 0: return "INSOMNIA"
    m = n
    seen = digits(m)
    while len(seen) < 10:
        m = m + n
        seen = seen | digits(m)
    return m

readInt = lambda: int(sys.stdin.readline())
def main():
    T = readInt()
    for t in range(1,T+1):
        print 'Case #%s: %s' % (t, solve(readInt()))

if __name__ == '__main__':
    main()
