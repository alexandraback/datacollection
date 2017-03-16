import re

library = {} # False means prime, otherwise it maps numbers to divisors
primes = []

def getDivisor(n):
  if (n in library):
    return library[n]
  test = 0
  while (test < len(primes) and primes[test] < n ** (0.5)):
    if (n % primes[test] == 0):
      library[n] = primes[test]
      return primes[test]
    test += 1
  library[n] = False
  if (n < 50000):
    primes.append(n)
  return False

def buildPrimes():
  for a in range(2,50000):
    getDivisor(a) #just populated the library with some initial values

def getDivisors(s):
  ret = ""
  for n in range(2,11):
    a = getDivisor(int(s,n))
    if (not a):
      return False
    #print str(int(s,n)) + " can be divided by " + str(a) 
    ret += " " + str(a)
  return ret

readTests = False
numTests = 0
buildPrimes()
with open("C:/Users/codetaku/Documents/input.txt","r") as file1, open("C:/Users/codetaku/Documents/output.txt","w") as file2:
  testCase = 0
  for line in file1.readlines():
    if (not readTests):
      readTests = True
      numTests = int(line)
      continue
    testCase += 1
    if (testCase > numTests):
      break
    arr = line.split(" ")
    n = int(arr[0])
    j = int(arr[1])
    vals = ""
    success = 0
    val = -1
    while (success < j):
      val += 1
      cur = "{0:b}".format(val)
      cur = "0" * (n - len(cur) - 2) + cur
      cur = "1" + cur + "1"
      test = getDivisors(cur)
      if (test):
        vals += str(cur) + test + "\n"
        success += 1
        print "Found " + str(success) + ", it is " + cur
    ret = "Case #" + str(testCase) + ":\n" + vals
    file2.write(ret)
    print ret
