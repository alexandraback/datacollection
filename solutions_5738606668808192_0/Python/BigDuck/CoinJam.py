def isPrime(a): #if yes return 0 else returna divider
    if a == 2 or a == 1:
        return 0
    else:
        for i in xrange(2,a ** 0.5+1):
            if a % i == 0:
                return i
        return 0

def primes_sieve2(limit):#0: if is prime, 1: prime
    a = [0] * limit                          # Initialize the primality list
    a[0] = a[1] = 1

    for (i, isprime) in enumerate(a):
        if isprime==0 :
            yield i
            for n in xrange(i*i, limit, i):     # Mark factors non-prime
                a[n] = i

littlePrimes = [i for i in primes_sieve2(100)]

def partialPrime(a):
    for i in littlePrimes:
        if a % i == 0:
            return i
    return 0


with open("input") as f:
    x = f.read().splitlines()

nOfCase = int(x[0])
testCases = x[1]
testCases = [int(x) for x in testCases.split()]
N,J = testCases[0], testCases[1]


def permutateString(N): #given N digits, return list of permutations
    for i in xrange(2**(N-2)):
        s = bin(i)[2:]
        s = "0" * (N-2-len(s)) + s
        s = "1" + s + "1"
        yield s

def digitize(s,x):#x = 1,2,3,...10
    n = len(s)
    value = 0
    for i in s:
        if int(i) != 0:
            value += (x ** (n-1))*int(i)
        n -= 1
    return value



#pList = primes_sieve2(5 ** 16)
#print pList


print "Case #1:"
CNT = 0
for i in permutateString(N):
    #print i
    digiList = [digitize(i,x) for x in xrange(2,11)]
    goodList = []
    flag = True
    for x in digiList:
        p = partialPrime(x)
        if p==0:
            flag = False
            break
        else:
            goodList.append(p)
    if flag == True:
        CNT += 1
        
        #print "good"
        goodList = [str(x) for x in goodList]
        output  = ' '.join(goodList)
        print "%s %s" % (i,output)
    if CNT == J:
        break


