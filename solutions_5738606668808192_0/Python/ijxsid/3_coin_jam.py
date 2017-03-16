import math
def interpret(n):
    cb = bin(n)[2:]
    vals = [n]
    for i in range(3, 10):
        r = cb[::-1]
        val, exp = 0, 0
        for j in r:
            if j == '1':
                val += i**exp
            exp += 1
        vals.append(val)
    vals.append(int(cb))
    return vals

def try_divide(v):
    if v % 2 == 0:
        return 2
    max_div = int(math.sqrt(v)) + 1
    for i in range(3, max_div):
        if v % i == 0:
            return i
    return -1

def get_divisors(vals, divisors):
    divs = []
    for v in vals:
        if v not in divisors:
            div = try_divide(v)
            divisors[v] = div
        divs.append(divisors[v])
    return divs

def jam_coins(N, K):
    coins = []
    divisors = {}
    min_coin = 2**(N-1) + 1
    max_coin = 2**(N) - 1
    for c in range(min_coin, max_coin + 1, 2):
        vals = interpret(c)
        divs = get_divisors(vals, divisors)
        if -1 not in divs:
            coins.append((bin(c)[2:], divs))
            if len(coins) == K:
                return coins

def main():
    T = int(input().strip())
    for i in range(T):
        N, K = map(int, input().strip().split())
        print("Case #1:")
        coins = jam_coins(N, K)
        for c in coins:
            print(c[0], ' '.join(str(e) for e in c[1]))



if __name__ == '__main__':
    main()