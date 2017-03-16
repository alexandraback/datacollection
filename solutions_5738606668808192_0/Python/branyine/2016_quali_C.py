# link: https://code.google.com/codejam/contest/dashboard?c=6254486#s=p2
import string
import time

testIndex=2

problemRoot="d:/prog/versenyek/googlejam"
problemDir="2016/quali"
problemName="C"
inputFiles= ["-example.in",  "-small.in",  "-large.in"]
outputFiles=["-example.out", "-small.out", "-large.out"]

time1=time.time()
fileName=string.strip(problemRoot)+"/"+problemDir+"/"+problemName+inputFiles[testIndex]
inputData=[map(int, line.split()) for line in open(fileName,'r') if line.strip()]
fileName=string.strip(problemRoot)+"/"+problemDir+"/"+problemName+outputFiles[testIndex]
fileToWrite=open(fileName,'wb')
time2=time.time()
iLineNum=1
# easy to use for the small, needs to be extended for the large
primes=[3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,
        151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251]
if testIndex==2:
  toTest=257
  while toTest<65536:
    numPrimes=len(primes)
    idx=1
    while idx<numPrimes and toTest%primes[idx]!=0:
      idx+=1
    if idx==numPrimes:
      primes.append(toTest)
    toTest+=2
  print "Primes generated"
storedPrimes=len(primes)
possFalseNeg=[]
for iCase in xrange(inputData[0][0]):
  N,J=inputData[iLineNum]
  solutions=[]
  toTest=(1<<(N-1))+1
  while len(solutions)<J and toTest<(1<<N):
    numbers=[0]*11
    binStr=bin(toTest)[2:]
    allOK=True
    for baseNum in xrange(2,11):
      numConverted=int(binStr,baseNum)
      numbers[0]=numConverted
      numbers[1]=binStr
      # test
      maxPrime=pow(numConverted,0.5)
      idx=0
      while idx<storedPrimes and primes[idx]<=maxPrime and numConverted % primes[idx]!=0:
        idx+=1
      if idx==storedPrimes:
        # we stop here... let's hope there are enough jamcoins without these false negatives
        possFalseNeg.append((toTest,baseNum))
        allOK=False
      elif primes[idx]>maxPrime:
        allOK=False
      else:
        numbers[baseNum]=primes[idx]
    if allOK:
      solutions.append(numbers)
#      print len(solutions)
    # create next jam
    toTest+=2
  if len(solutions)<J:
    print "NEM NYERT!!! ",len(solutions),"<",J
  print "Lehetseges hibas dontesek szama: ",len(possFalseNeg)
  fileToWrite.write("Case #"+str(iCase+1)+":\n")
  for numbers in solutions:
    lineStr=""
    for subStr in numbers[1:]:
      lineStr+=str(subStr)+" "
    fileToWrite.write(lineStr[:-1]+"\n")
  iLineNum+=1
fileToWrite.close()
print 'Total time:   ', time.time() - time1
print 'Solving time: ', time.time() - time2
