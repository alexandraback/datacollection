import random
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,
          61, 67, 71, 73, 79, 83, 89, 93, 97]
def getdiv(n):
    for prime in primes:
        if prime * prime > n:
            break
        if n % prime == 0:
            return prime
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
