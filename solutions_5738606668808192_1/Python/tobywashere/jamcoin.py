
import math

def isPrime(n):
    if n == 2:
        return 0
    if n % 2 == 0:
        return 2
    for i in xrange(3, int(math.sqrt(n))+1, 2):
        if n % i == 0:
            return i
        if i > 11:
            return 0
    return 0

def convertTo2(num):
    res = ''
    while num > 0:
        if num % 2 == 1:
            res = '1' + res
        else:
            res = '0' + res
        num //= 2
    return res

def baseConverter(s, base):
    Pow = 1
    Sum = 0
    for i in xrange(len(s)-1, -1, -1):
        if s[i] == '1':
            Sum += Pow
        Pow *= base
    return Sum

if __name__ == '__main__':
    N = 32
    J = 500
    counter = 0
    print("Case #1:")
    start = (1 << (N-1)) + 1
    end = 1 << N
    for i in xrange(start, end, 2):
        rep = convertTo2(i)
        prime = False
        this_divisors = []
        for base in xrange(2, 11):
            converted = baseConverter(rep, base)
            res = isPrime(converted)
            if res == 0:
                prime = True
                break
            this_divisors.append(res)
        if prime:
            continue
        ans = rep
        for i in xrange(9):
            ans += ' ' + str(this_divisors[i])
        print(ans)
        counter += 1
        if counter == J:
            break
