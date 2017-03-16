# link: https://code.google.com/codejam/contest/dashboard?c=6254486#s=p1
import string
import time

testIndex=1

problemRoot="d:/prog/versenyek/googlejam"
problemDir="2016/quali"
problemName="B"
inputFiles= ["-example.in",  "-small.in",  "-large.in"]
outputFiles=["-example.out", "-small.out", "-large.out"]

time1=time.time()
fileName=string.strip(problemRoot)+"/"+problemDir+"/"+problemName+inputFiles[testIndex]
inputData=[map(str, line.split()) for line in open(fileName,'r') if line.strip()]
fileName=string.strip(problemRoot)+"/"+problemDir+"/"+problemName+outputFiles[testIndex]
fileToWrite=open(fileName,'wb')
time2=time.time()
iLineNum=1
for iCase in xrange(int(inputData[0][0])):
  pancakes=inputData[iLineNum][0]+"+"
  changeNum=0
  for idx in xrange(1,len(pancakes)):
    if pancakes[idx]!=pancakes[idx-1]:
      changeNum+=1
  fileToWrite.write("Case #"+str(iCase+1)+": "+str(changeNum)+"\n")
  iLineNum+=1
fileToWrite.close()
print 'Total time:   ', time.time() - time1
print 'Solving time: ', time.time() - time2
