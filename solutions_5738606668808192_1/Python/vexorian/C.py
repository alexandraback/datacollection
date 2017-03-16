N = 32
J = 500

NUM_THREADS = 4

EASY_PRIMES = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71]

import random
import threading
import sys

mutex = threading.Lock()

seen_coins = dict()

def add_if_new(coin, divisors):
    with mutex:
        if coin not in seen_coins and len(seen_coins) < J:
            seen_coins[coin] = divisors
            sys.stderr.write( str(len(seen_coins)) + ' already!\n' )
            sys.stderr.write( str(attempt_count[0]) + ' attempts\n' )
            sys.stderr.flush()
            
            
def work_done():
    with mutex:
        if len(seen_coins) >= J:
            return True
        else:
            return False

def random_coin():
    x = [ random.randint(0,1) for i in range(N) ]
    x[0] = 1
    x[-1] = 1
    return tuple(x)


def is_divisor(coin, b, d):
    m = 0
    p = 1
    for x in reversed(coin):
        if x == 1:
            m = (m + p) % d
        p = (p * b) % d
    if m == 0:
        return True
    else:
        return False

def get_divisors(coin):
    divisors = []
    for b in xrange(2,10 + 1):
        for d in EASY_PRIMES:
            if is_divisor(coin, b, d):
                 divisors.append(d)
                 break
        else:
            return None
    return divisors

attempt_count = [0]

def worker():
    while not work_done():
        coin = random_coin()
        divisors = get_divisors(coin)
        if divisors != None:
            add_if_new(coin, divisors)
        with mutex:
            attempt_count[0] = attempt_count[0] + 1
            #sys.stderr.write( str(attempt_count[0]) + ' attempts\n' )
    
threads = [ threading.Thread(name='worker%d'%i, target=worker) for i in range(NUM_THREADS) ]

for t in threads:
    t.start()

for t in threads:
    t.join()

sys.stdout.write( 'Case #1:\n')
for x in seen_coins:
    for y in x:
        sys.stdout.write( str(y) )
    for div in seen_coins[x]:
        sys.stdout.write( ' ' + str(div) )
    sys.stdout.write( '\n')
    sys.stdout.flush()
    