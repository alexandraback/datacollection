primes = []

def get_prime(N):
    global primes
    f = [0] * (N + 1)
    for i in range(2, N):
        if f[i] == 0:
            primes.append(i)
            for j in range(N // i + 1):
                f[j * i] = 1

def get(x, base):
    res = 0
    t = 0
    while x > 0:
        t = (t << 1) + (x & 1)
        x >>= 1
    while t > 0:
        res = res * base + (t & 1)
        t >>= 1
    return res

def main():
    get_prime(1000000)
    global primes
    print('Case #1:')
    length = 16
    goal_num = 50
    num = 0
    for i in range(1 << (length-2)):
        legitimate = True
        result = ''
        t = (1 << (length-1)) + (i << 1) + 1
        while t > 0:
            result = str(t & 1) + result
            t >>= 1
        for base in range(2, 11):
            x = get((1 << (length-1)) + (i << 1) + 1, base)
            divisor = 0
            for p in primes:
                if p >= x:
                    break
                if x % p == 0:
                    divisor = p
                    break
            if divisor:
                result += ' %d' % divisor
            else:
                legitimate = False
                break
        if legitimate:
            print(result)
            num += 1
            if num == goal_num:
                break


if __name__ == '__main__':
    main()
