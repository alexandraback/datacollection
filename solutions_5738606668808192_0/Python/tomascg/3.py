import sympy
#one can find this library in https://pypi.python.org/pypi/sympy/0.7.6.1

firstPrimes = [x for x in range(2,400) if sympy.isprime(x)]

def convertNum(s, b):
    k = len(s)
    num = 0
    for i in range(0,k):
        char = s[i]
        num += int(char) * b**(k-i-1)
    return num

def allNumbers(s):
    return [convertNum(s,i) for i in range(2,11)]


def generateString(k):
    count = 0
    x = ['0','1']
    res = {}
    for i in xrange(k):
        xx = [ '0'+ y for y in x]
        xxx = ['1'+y for y in x]
        x = xx+xxx
    
    x = ['1'+y+'1' for y in x]
    for s in x:
        if count == 50:
            break
        nums = allNumbers(s)
        good = True
        for x in nums:
            good = good and not sympy.isprime(x)
            if good == False:
                break
        if good:
            witnesses = findwitness(nums)
            if witnesses:
                res[s] = witnesses
                count += 1
                                

    return res
    
def findwitness(nums):
    witness = [0 for i in range(9)]
    for i in range(9):
        curr = nums[i]
        found = False
        for prime in firstPrimes:
            if curr % prime == 0:
                witness[i] = prime
                found = True
                break
        if not found:
            return []
    return witness

jamcoins = generateString(13)


##f = open('a.in', 'r')
g = open('a.out', 'w')
print "Case #1:"
g.write("Case #1:"+'\n')
jamcoins = generateString(13)
for s in jamcoins.keys():
    p = ""+ s + " "
    for wit in jamcoins[s]:
        p += str(wit)+ " "
    print p
    g.write(p+'\n')
    
##
##t = int(f.readline())
###least = makeAll2()
####
##for i in range(1,t+1):
##    pan = f.readline().split('\n')[0]
##    ans = eff(pan)
##    pr = "Case #"+str(i)+ ": " + str(ans)
##    print pr
##    g.write(pr + '\n')
##
##
##f.close()
g.close()
