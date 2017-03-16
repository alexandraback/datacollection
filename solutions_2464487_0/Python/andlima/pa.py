def f(n, r):
    return (2*r+1)*n + 2*n*(n-1)

def solve(r, t):
    lower = 1

    upper = 1
    while f(upper, r) <= t:
        upper *= 2

    while upper - lower > 1:
        n = (lower + upper) / 2
        if f(n, r) <= t:
            lower = n
        else:
            upper = n

    return lower

def main():
    T = int(raw_input())
    for i in range(T):
        r, t = map(int, raw_input().split())
        print 'Case #%d: %d' % (i + 1, solve(r, t))

main()
