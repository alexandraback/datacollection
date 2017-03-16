primes = []
for line in file('shortprimelist.txt'):
    for prime in line.split():
        primes.append(int(prime))
    if len(primes) > 100:
        break

def checkAllBasePrimality(binstrlist):
    retlist = []
    binstr = ''.join(binstrlist)
    for base in range(2, 11):
        # print int(binstr, base)
        baseprime = True
        for divisor in primes:
            if int(binstr, base) % divisor == 0:
                baseprime = False
                retlist.append(divisor)
                break;
        if baseprime:
            return False
    return retlist

def checkPotentialJams(n, j, binstr, curProgress):
    if curProgress == j:
        return curProgress
    if len(binstr) == 0:
        binstr.append('1')
    if len(binstr) == n - 1:
        binstr.append('1')
        primalityval = checkAllBasePrimality(binstr)
        if len(binstr) != n:
            "HEHLFWHLIEHFILHWELIHFLWEHFILWEHFLWEFH"
        binstr.pop()
        if primalityval == False:
            return curProgress
        curProgress += 1
        print ''.join(binstr) + "1 " + " ".join(str(i) for i in primalityval)
        
        return curProgress
    binstr.append('0')
    curProgress = checkPotentialJams(n, j, binstr, curProgress)
    binstr.pop()

    binstr.append('1')
    curProgress = checkPotentialJams(n, j, binstr, curProgress)
    binstr.pop()

    return curProgress

numtests = int(raw_input())
for testnum in range(1, numtests+1):
    testparams = raw_input()
    n,j = (testparams.split())
    n = int(n)
    j = int(j)
    print "Case #" + str(testnum) + ":"
    # print checkAllBasePrimality('100011')  
    checkPotentialJams(n, j, [], 0)

