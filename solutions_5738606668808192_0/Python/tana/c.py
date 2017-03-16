import random

def getdiv(n):
    i = 2
    while i * i <= n:
        if n % i == 0:
            return i
        i += 1
    return None

random.seed(179425943)
tt = int(raw_input())
for t in xrange(1, tt+1):
    print 'Case #%d:' % t
    coins = dict()
    n, j = map(int, raw_input().strip().split())
    for i in xrange(j):
        while True:
            x = random.getrandbits(n-2)
            y = []
            for i in xrange(n-2):
                y.append(x % 2)
                x /= 2
            y = [1] + y + [1]
            prime = False
            divisors = []
            for base in xrange(2, 11):
                num = 0
                for i in xrange(n):
                    num *= base
                    num += y[i]
                div = getdiv(num)
                if div is None:
                    prime = True
                    break
                else:
                    divisors.append(div)
            if not prime:
                ans = ''.join(map(str, y))
                if ans not in coins:
                    break
        coins[ans] = divisors
        print '%s %s' % (ans, ' '.join(map(str, divisors)))
