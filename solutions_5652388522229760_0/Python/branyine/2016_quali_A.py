# link: https://code.google.com/codejam/contest/dashboard?c=6254486#s=p0
import string
import time

testIndex=1

problemRoot="d:/prog/versenyek/googlejam"
problemDir="2016/quali"
problemName="A"
inputFiles= ["-example.in",  "-small.in",  "-large.in"]
outputFiles=["-example.out", "-small.out", "-large.out"]

time1=time.time()
fileName=string.strip(problemRoot)+"/"+problemDir+"/"+problemName+inputFiles[testIndex]
inputData=[map(int, line.split()) for line in open(fileName,'r') if line.strip()]
fileName=string.strip(problemRoot)+"/"+problemDir+"/"+problemName+outputFiles[testIndex]
fileToWrite=open(fileName,'wb')
time2=time.time()
iLineNum=1
for iCase in xrange(inputData[0][0]):
  N=inputData[iLineNum][0]
  if N==0:
    fileToWrite.write("Case #"+str(iCase+1)+": INSOMNIA\n")
  else:
    num=0
    seens=[0]*10
    while sum(seens)<10:
      num+=N
      for digit in str(num):
        seens[int(digit)]=1
    fileToWrite.write("Case #"+str(iCase+1)+": "+str(num)+"\n")
  iLineNum+=1
fileToWrite.close()
print 'Total time:   ', time.time() - time1
print 'Solving time: ', time.time() - time2
