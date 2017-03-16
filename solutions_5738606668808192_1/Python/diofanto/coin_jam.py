import random

def get_random_coin(N):
    res = ''
    for j in range(1, N - 1):
        res += str(random.randint(0, 1))
    return res

def coin_to_value(coin, base, N):
    n = base**(N-1) + 1
    for ex, d in enumerate(coin):
        if d == '1':
            n += base**(ex + 1)
    return n

def update_coin(nn, N):
    res = []

    random_coin = get_random_coin(N)

    for i, n in enumerate(nn):
        base = i + 2

        res.append(coin_to_value(random_coin, base, N))

    return res

def are_all_composite(nn):
    for n in nn:
        if pow(2, n - 1, n) == 1:
            return False
    return True

def to_binary(c):
    n = c[0]
    return bin(n)[2:]

def get_divisor(n):
    for cnt, i in enumerate(range(2, n)):
        if cnt > 10**6:
            return -1
        if n % i == 0:
            return i
    print("nope", n, i)
    exit(0)

def get_divisors(c):
    res = []
    for n in c:
        d = get_divisor(n)
        if d == -1:
            return []
        res.append(d)
    return res

input()
N, J = map(int, input().split())
nn = [1 + x**(N-1) for x in range(2, 11)]
jam_coins = []
divisors = []
c_map = {}
while len(jam_coins) < J:
    if are_all_composite(nn):
        div = get_divisors(nn)
        if div and nn[0] not in c_map:
            c_map[nn[0]] = True
            divisors.append(' '.join(map(str, div)))
            jam_coins.append(nn[:])
    nn = update_coin(nn, N)

print("Case #1:")
for c, d in zip(jam_coins, divisors):
    print("{0} {1}".format(to_binary(c), d))
