import math

K = 10000;

def ComputePrime(primes):
    count = 0
    prime = 2
    primes.append(prime)
    while (count < K):
        isPrime = True
        prime += 1
        for i in range(0, count):
            sqrt_num = math.sqrt(prime)
            if primes[i] > sqrt_num: 
                break
            if prime % primes[i] == 0:
                isPrime = False
                break
        if (isPrime):
            primes.append(prime)
            count += 1
            if count % 1000 == 0:
                print(count, prime)
        

def isPrime(num, primes):
    for i in range(0, K):
        sqrt_num = math.sqrt(num);
        if (primes[i] > sqrt_num):
            break
        if (num % primes[i] == 0):
            return primes[i]
    return 0

def main():
    primes = []
    ComputePrime(primes)

    N = 32
    J = 500
    count = 0

    digit = []
    digit.append(1)
    for i in range(1, N-1):
        digit.append(0)
    digit.append(1)

    fout = "C-large.out"
    with open(fout,'w') as output:
        ln = "Case #1:"
        output.write('{}\n'.format(ln))
        while True:
            for i in range(1, N-1):
                if (digit[i] == 1):
                    digit[i] = 0
                else:
                    digit[i] = 1
                    break
            isCoin = True
            divisor = [0 for i in range(0,11)]
            for b in range(2, 11):
                num = 0
                base = 1
                for i in range(0, N):
                    num += digit[i] * base
                    base *= b
                divisor[b] = isPrime(num, primes)
                if (divisor[b] == 0):
                    isCoin = False;
                    break;

            if (isCoin):
                count += 1
                ln = ""
                for i in range(0, N):
                    ln += str(digit[N-i-1])
                for b in range(2,11):
                    ln += " "
                    ln += str(divisor[b])
                output.write('{}\n'.format(ln))
            if (count == J):
                break;

main()
