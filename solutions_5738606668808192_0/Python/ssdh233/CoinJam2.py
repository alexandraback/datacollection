
def primes(n):
    sieve = [True for i in range(int(n))]
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i]:
            sieve[i*i::2*i] = [False for i in range(int((n-i*i-1)/(2*i))+1)]
    return [2] + [i for i in range(3,n,2) if sieve[i]]

primeslist = primes(2**16)

def tran(num, base):
    number = 0
    num = str(num)
    length = len(num)
    for i in range(length):
        number += int(num[i])*base**(length-i-1)
    return number

def large(N,J):
    count = 0
    for i in range(2**(N-1)+1,2**N,2):
        out = str(bin(i))[2:]
        for j in range(2,11):
            num = tran(str(bin(i))[2:],j)
            div = divisor(num)
            if not div:
                out = None
                break
            else:
                out = out + " " + str(div)
        if out:
            print(out)
            count += 1
            if count >= J:
                break
    return

def divisor(num):
    for i in primeslist:
        if num % i == 0 and i < num:
            return i
    return None


T = int(input())

for index in range(T):
    N, J = map(int, input().split())
    print("Case #"+str(index+1)+": ")
    large(N,J)



