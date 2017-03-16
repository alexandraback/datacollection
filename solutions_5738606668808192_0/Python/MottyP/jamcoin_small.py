import random
import math

def getDivider(num):
    top = math.sqrt(num)
    if top == int(top):
        return top
    for d in xrange(2, int(top)+1):
        if num % d == 0:
            return d

def getAllDividersIfGood(numstr):
    divs = []
    for base in range(2,11):
        num = int(numstr, base)
        d = getDivider(num)
        if not d:
            return None
        divs.append(d)
    return divs

def solve():
    N = 16
    J = 50

    seen = set()
    r = random.Random()
    mask = (1 << (N-1)) + 1
    while J > 0:
        coin = r.randint(0, 2**N - 1) | mask
        if coin in seen:
            continue
        seen.add(coin)
        coinstr = bin(coin).replace('0b', '')
        assert len(coinstr) == N and coinstr.startswith('1') and coinstr.endswith('1')
        divs = getAllDividersIfGood(coinstr)
        if divs:
            print coinstr, ' '.join(str(d) for d in divs)
            J -= 1
