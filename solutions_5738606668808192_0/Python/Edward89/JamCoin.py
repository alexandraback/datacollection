def extendPrimes(primes,limit):
    last = primes[-1]
    for i in range(last+1,limit+1):
        if primTest(i,primes):
            primes.append(i)

def primTest(nbr,primes):
    for i in primes:
        if nbr%i==0:
            return i
        elif i*i>nbr:
            return -1
    return -1

def evalOnRadix(nbr,N,radix):
    if radix==2:
        return nbr
    output = 0
    for i in range(N-1,-1,-1):
        output*=radix
        if (nbr&(1<<i))>0:
            output+=1
    return output

def verify(nbr,N,factors):
    if len(nbr)!=N:
        assert False
    elif nbr[0]!='1':
        assert False
    elif nbr[N-1]!='1':
        assert False
    for radix in range(2,11):
        interpret = 0
        for digit in range(0,N):
            if nbr[digit]=='1':
                interpret+=(radix**(N-1-digit))
            elif nbr[digit]!='0':
                assert False
        if interpret%factors[radix-2]!=0:
            print interpret
            print factors[radix-2]
            assert False

outputFile = open('out.txt','w')
outputFile.write('Case #1:\n')
N = 16
J = 50
primes = [2]
extendPrimes(primes,10**5)
nbr = (1<<(N-1))+1
jamCoinsFound = 0
while jamCoinsFound<J and nbr<(1<<N):
    factors = list()
    for radix in range(2,11):
        interpret = evalOnRadix(nbr,N,radix)
        f = primTest(interpret,primes)
        if f>0:
            factors.append(f)
        else:
            break
    if len(factors)>=9:
        formatted = str()
        for i in range(N-1,-1,-1):
            formatted+=('1' if nbr&(1<<i) else '0')
        outputFile.write(formatted)
        for i in range(9):
            outputFile.write(' '+str(factors[i]))
        outputFile.write('\n')
        print formatted
        verify(formatted,N,factors)
        jamCoinsFound+=1
    nbr+=2
print jamCoinsFound
outputFile.close()
