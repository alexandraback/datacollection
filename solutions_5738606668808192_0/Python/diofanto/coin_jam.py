def update_coin(nn, N):
    res = []
    for i, n in enumerate(nn):
        base = i + 2
        i = 0
        n_temp = n
        diff = -1
        while n_temp % base != 0:
            diff += base**i
            n_temp = n_temp // base
            i += 1
        n += base**i - diff
        res.append(n)
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
    for i in range(2, n):
        if n % i == 0:
            return i
    print("nope", n, i)
    exit(0)

def get_divisors(c):
    return ' '.join([str(get_divisor(n)) for n in c])

input()
N, J = map(int, input().split())
nn = [1 + x**(N-1) for x in range(2, 11)]
jam_coins = []
while len(jam_coins) < J:
    if are_all_composite(nn):
        jam_coins.append(nn[:])
    nn = update_coin(nn, N)

print("Case #1:")
for c in jam_coins:
    print("{0} {1}".format(to_binary(c), get_divisors(c)))
