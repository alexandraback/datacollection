import math

'''
def miller_rabin(n):
    if n <=2:
        if n == 2:
            return True
        return False
    if n % 2 == 0:
        return False

    u = n - 1   # u is the exponent
    while u % 2 == 0:
        u /= 2

    a16_list = [2,3,5,7,11,13,17,19,23]
    a25_list = [2,3,5,7,11,13,17,19,23,29,31,37,41]
    for a in a16_list:
        x = a**u % n
        while u < n:
            # test a**u, a**2u, a**4u
            y = x**2 % n
            if y == 1 and x !=1 and x != n - 1:
                return False
            x = y
            u *= 2
        if x != 1:
            return False
    return True


def generatePrimeListToFile(max):
    primeList = []
    for i in range(1, int(max) + 1):
        if miller_rabin(i):     # return True if Prime
            primeList.append(i)
    f = open('primeList.txt', 'w')
    for i in primeList:
        f.write(' {}'.format(i))
    f.close()
'''

def generatePrimeListToFile(limit):
    primeList = []
    isPrime = [True] * (limit+1)
    primeCount = 0
    for i in range(2, limit+1):
        if isPrime[i]:
            primeCount += 1
            primeList.append(i)
        for prime in primeList:
            if i * prime > limit:
                break
            isPrime[ i * prime] = False
            if i % prime == 0:
                break
    f = open('primeList.txt', 'w')
    for i in primeList:
        f.write(' {}'.format(i))
    f.close()

def convertByBase(string, base):
    dic = {"1": 1, "0": 0}
    sum = 0
    for i in string:
        sum *= base
        sum += dic[i]
    return sum

def isPrime(n, primeList):
    if n in primeList:
        return True
    sqrt_n = math.sqrt(n)
    for prime in primeList:
        if prime > sqrt_n:
            break
        if n % prime == 0:
            return False
    return True

def main():
    f = open('primeList.txt','r')
    primeList = [int(s) for s in f.read().split(' ')[1:]]
    #print(primeList)
    infile = open('input.in', 'r')
    t = int(infile.readline())
    m, n = [int(s) for s in infile.readline().split(' ')]
    ofile = open('problem_2_res.output', 'w')
    ofile.write("Case #{}:".format(t))
    count = 0
    for num in range(2**(m-1)+1, 2**m, 2):
        isCoinJam = True
        res = ""
        currentString = '{0:b}'.format(num)
        for base in range(2, 11):
            value = convertByBase(currentString, base)
            #print(value)
            if isPrime(value, primeList):
                isCoinJam = False
                break
            else:
                for div in primeList:
                    if value % div == 0:
                        res += str(div) + " "
                        break
        if isCoinJam:
            #print(currentString + " " + res + "\n")
            ofile.write("\n" + currentString + " " + res)
            count += 1
            if count == n:
                break
    ofile.close()
    infile.close()

main()

#int_sqrt_max = int('33333334')
#generatePrimeListToFile(int_sqrt_max)
'''
f = open('primeList.txt','r')
primeList = [int(s) for s in f.read().split(' ')[1:]]
print(isPrime(33333331, primeList))
print(isPrime(111111111111, primeList))
'''