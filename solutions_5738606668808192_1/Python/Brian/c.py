TESTED = 0

def value(coin, base):
    return sum([base**i * int(coin[-(i+1)]) for i in xrange(len(coin))])

def get_divisor(val):
    i = 2
    while i*i <= val and i < 1000:
        if val % i == 0:
            return i
        i += 1
    return None

def search(coins, n, j, coin):
    if len(coins) == j:
        return

    if len(coin) == n-1:
        global TESTED
        TESTED = TESTED + 1

        coin = coin+"1"
        divisors = []
        for i in xrange(9):
            d = get_divisor(value(coin, i+2))
            if d is None:
                break
            divisors.append(d)
        if len(divisors) == 9:
            coins[coin] = " ".join([str(d) for d in divisors])
        return

    search(coins, n, j, coin+"0")
    search(coins, n, j, coin+"1")

with open("c.in") as f:
    t = int(next(f))
    for case in xrange(t):
        vals = next(f).split(" ")
        n = int(vals[0])
        j = int(vals[1])

        coins = {}
        search(coins, n, j, "1")

        print "Case #{}:".format(case+1)
        for coin, divisors in coins.iteritems():
            print "{} {}".format(coin, divisors)
