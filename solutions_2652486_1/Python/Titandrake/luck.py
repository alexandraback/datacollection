cases = input()
# Small 2
def factor(n):
    # Include 0
    primes = [2, 3, 5, 7]
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
    for _ in range(r):
        products = [int(t) for t in raw_input().split()]
        min_req = dict() # 3 and 5 only
        known = list()
        min_3 = 0
        min_2 = 0
        min_extra_2 = 0
        for i in range(k):
            f = factor(products[i])
            num_2, num_3, num_5, num_7 = f[0][1], f[1][1], f[2][1], f[3][1]
            while num_5 > known.count(5):
                known.append(5)
            while num_7 > known.count(7):
                known.append(7)
            min_3 = max(min_3, num_3)
            min_2 = max(min_2, num_2)
            extra = num_2 - (n - num_5 - num_7)
            min_extra_2 = max(min_extra_2, extra)
        # Guess based on number of 3s and 2s
        # Combine half of 3 with 2
        num_6 = min(min_2, min_3)
        for _ in range(num_6):
            known.append(6)
        min_2 -= num_6
        min_3 -= num_6
        for _ in range(min_3):
            known.append(3)
        space = n - len(known)
        while min_extra_2 > 0:
            if min_extra_2 >= 2:
                known.append(8)
                min_extra_2 -= 2
            elif min_extra_2 == 1:
                known.append(4)
                min_extra_2 -= 1
        space = n - len(known)
        for i in range(space):
            if i % 2 == 0:
                known.append(2)
            else:
                known.append(3)
        print ''.join([str(t) for t in known])
               