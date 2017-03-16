def get_all_coins(number, divisor, coins):
    if number not in coins:
        coins[number] = divisor
    elif divisor == coins[number]:
        return # already looked at this tree
    
    bn = to_bin(number)
    dn = to_bin(divisor)
    search_str = "0" * len(dn)
    start = 0
    bn = bn[::-1]
    while True:
        idx = bn.find(search_str, start)
        if idx == -1:
            break
        get_all_coins(number | divisor << idx, divisor, coins)
        start = idx + 1
    
to_bin = lambda x: bin(x)[2:]
to_base = lambda x, base: int(to_bin(x), base)
    
import sys
f = sys.stdin
T = int(f.readline())
for case in xrange(T):
    N, J = map(int, f.readline().split())
    start = (2 ** (N-1)) + 1
    end = 2 ** N
    coins = {}
    i = start
    while i < end:
        for j in xrange(3, 2**(N / 2), 2):
            if all(to_base(i, base) % to_base(j, base) == 0 for base in xrange(2, 11)):
                get_all_coins(i, j, coins)
                if len(coins) >= J:
                    break
        if len(coins) >= J:
            break
        i += 2
    print "Case #%d: " % (case + 1,)
    for coin, div in coins.items()[:J]:
        assert all(to_base(coin, base) % to_base(div, base) == 0 for base in xrange(2, 11))
        print to_bin(coin), " ".join(str(to_base(div, base)) for base in xrange(2, 11))
    
        