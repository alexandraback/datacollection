def gcd(x, y):
    if y == 0:
        return x
    else:
        return gcd(y, x % y)
        
def small(t, P, Q):
    factor = gcd((1<<40) * P, Q)
    P = (1<<40) * P / factor
    Q /= factor
    if Q != 1:
        print 'Case #{0}: impossible'.format(t)
    else:
        i = 40
        while P & (1<<i) == 0:
            i -= 1
        print 'Case #{0}: {1}'.format(t, 40 - i)
 
 
def main():
    T = int(raw_input())
    for t in xrange(1, T + 1):
        (P, Q) = map(int, raw_input().split('/'))
        small(t, P, Q)
 
 
if __name__ == '__main__':
    main()
