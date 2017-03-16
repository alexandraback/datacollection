import random

def millerrabin(n):
    if n == 1:
        return False
    if n in [2, 7, 61]:
        return True
    if n % 2 == 0:
        return False
    s = 0
    d = n-1
    while True:
        quotient, remainder = divmod(d, 2)
        if remainder == 1:
            break
        s += 1
        d = quotient

    def try_composite(a):
        if pow(a, d, n) == 1:
            return False
        for i in range(s):
            if pow(a, 2**i * d, n) == n-1:
                return False
        return True

    for i in range(10):
        for a in [2, 7, 61]:
            if try_composite(a):
                return False

    return True

def divisor(n):
    for d in range(2, min(100, int(n ** 0.5) + 1)):
        if n % d == 0:
            return d
    else:
        return -1

def jamcoin(n, j):
    start = 2 ** (n - 1) + 1
    bin_n = bin(start)[2:]
    coins = []
    while len(coins) < j and start < 2 ** n:
        for base in range(2, 11):
            if millerrabin(int(str(bin_n), base)):
                break
        else:
            new_coins = [bin_n]
            for base in range(2, 11):
                d = divisor(int(bin_n, base))
                if d != -1:
                    new_coins.append(d)
            if len(new_coins) == 10:
                coins.append(new_coins)
        start += 2
        bin_n = bin(start)[2:]
    return coins

def main():
    for _ in range(int(input())):
        print('CASE #%d:' % (_ + 1))
        for __ in jamcoin(*tuple(map(int, input().split()))):
            print(' '.join(str(x) for x in __))

if __name__ == '__main__':
    main()
