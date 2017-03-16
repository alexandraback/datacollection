import sys

# Call with positive integer n.
def get_digits(n):
    ret = []

    while n:
        ret.append(n % 10)
        n = n / 10
    
    return ret

def solve(N):
    if N == 0:
        return 'INSOMNIA'

    X = N
    seen = set(get_digits(X))
    
    while True:
        if len(seen) == 10:
            break
        X += N
        seen.update(get_digits(X))

    return X
        

def main():
    T = int(sys.stdin.readline().strip())

    for i in xrange(T):
        N = int(sys.stdin.readline().strip())
        SOL = solve(N)
        print 'Case #%s: %s' % (i+1, SOL)

if __name__ == '__main__':
    main()
