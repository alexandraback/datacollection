cases = input()
# Small 1
def factor(n):
    # Include 0
    primes = [2, 3, 5]
    f = []
    for p in primes:
        count = 0
        while n % p == 0:
            count += 1
            n //= p
        f.append((p, count))
    return f

for case in xrange(1, cases + 1):
    r, n, m, k = [int(t) for t in raw_input().split()]
    print "Case #1:"
    primes = [2,3,5]
    for _ in range(r):
        products = [int(t) for t in raw_input().split()]
        min_req = dict() # 3 and 5 only
        known = list()
        for i in range(k):
            f = factor(products[i])
            num_2, num_3, num_5 = f[0][1], f[1][1], f[2][1]
            while num_3 > known.count(3):
                known.append(3)
            while num_5 > known.count(5):
                known.append(5)
            num_4 = num_2 - (n - num_3 - num_5)
            while num_4 > known.count(4):
                known.append(4)
        # Fill with 2s
        while len(known) < n:
            known.append(2)
        print ''.join([str(t) for t in known])
               