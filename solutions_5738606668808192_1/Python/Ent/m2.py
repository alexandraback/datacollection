from random import randrange

small_primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]


def mrpt(n, k):
    if n < 2:
        return False
    for p in small_primes:
        if n < p * p:
            return True
        if n % p == 0:
            return False
    r, s = [0, n - 1]
    # log
    while s % 2 == 0:
        r += 1
        s //= 2
    for _ in range(k):
        a = randrange(2, n - 1)
        x = pow(a, s, n)
        if x == 1 or x == n - 1:
            continue
        for _ in range(r - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                break
        else:
            return False
    return True


def gd(n):
    if n % 2 == 0:
        return 2
    if n % 3 == 0:
        return 3
    i = 5
    w = 2
    while i * i <= n:
        if n % i == 0:
            return i
        i += w
        w = 6 - w
        if i > 1000000:
            return -1
    return 0


def baseX(n, base):  # n is a int
    temp = list(str(n))
    l = list(range(len(temp)))[::-1]
    return sum([int(temp[i]) * base ** l[i] for i in range(len(temp))])


t = int(input())
[N, J] = [int(i) for i in input().split()]
print('Case #1:')
count = 0

begin = baseX(int('1' + '0' * (N - 1)), 2)
end = baseX(int('1' * N), 2)
for x in range(begin + 1, end + 1, 2):
    fl = 0
    num = int(bin(x)[2:])
    tmp = []
    for b in range(2, 11):
        # [br, dv] = isprime(baseX(num, b))
        br = mrpt(baseX(num, b), 40)
        if br:
            fl = 1
            break
        dv = gd(baseX(num, b))
        if dv == -1:
            fl = 1
        tmp.append([br, dv])
    if fl == 1:
        continue

    print(str(num), end=' ')
    for q in range(8):
        print(str(tmp[q][1]), end=' ')
    print(str(tmp[8][1]))
    count += 1
    if count == J:
        break
