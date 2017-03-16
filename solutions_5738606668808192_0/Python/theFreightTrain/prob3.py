import numpy as np

compositeList = {}
primeList = []

def renderInBase(testCoin,i):
    result = 0;
    for index in range(1,1+len(testCoin)):
        result += int(testCoin[-index])*(i**(index-1))
    return result
    
def isPrime(test,compositeList,primeList):
    if(test in compositeList): return compositeList[test]
    if(test in primeList): return -1
    for i in range(2,int(np.sqrt(test))+1):
        if test % i == 0:
            compositeList[test]=i
            return i
    primeList += [test]
    return -1

def isJamCoin(testCoin,compositeList,primeList):
    divisors = ''
    for i in range(2,11):
        nextDivisor = isPrime(renderInBase(testCoin,i),compositeList,primeList)
        if nextDivisor==-1:
            return ''
        else:
            divisors += ' '+ str(nextDivisor)
    return divisors
    
def toBaseTwo(i):
    result = ''
    place = int(np.log(i)/np.log(2))
    while(place>=0):
        if i>=2**place:
            result += '1'
            i -= 2**place
        else:
            result += '0'
        place -= 1
    return result
    
def incrementJamCoin(currentJamCoin):
    return toBaseTwo(int(currentJamCoin,2)+2)

def findNextJamCoin(currentJamCoin,compositeList,primeList):
    jamCoin = currentJamCoin.split(' ')[0]
    #print(jamCoin)
    testCoin = incrementJamCoin(jamCoin)
    divisors = isJamCoin(testCoin,compositeList,primeList)
    while(not divisors):
        testCoin = incrementJamCoin(testCoin)
        #print(testCoin)
        divisors = isJamCoin(testCoin,compositeList,primeList)
    return testCoin + divisors
    
    
t = int(input())
for i in range(1, t + 1):
  s = input().split(' ')
  N = int(s[0])
  J = int(s[1])
  print("Case #{}:".format(i))
  currentJamCoin = '1'+'0'*(N-2)+'1'
  for i in range(J):
      currentJamCoin = findNextJamCoin(currentJamCoin,compositeList,primeList)
      print("{}".format(currentJamCoin))
  

