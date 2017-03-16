# link: https://code.google.com/codejam/contest/dashboard?c=6254486#s=p3
import string
import time

testIndex=1

problemRoot="d:/prog/versenyek/googlejam"
problemDir="2016/quali"
problemName="D"
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
  K,C,S=inputData[iLineNum]
  if K>C*S:
    fileToWrite.write("Case #"+str(iCase+1)+": IMPOSSIBLE\n")
  else:
    fileToWrite.write("Case #"+str(iCase+1)+":")
    for i in xrange(0,K,C):
      tileToClean=0
      for j in xrange(C):
        tileToClean=tileToClean*K+(i+j) % K # modulo for the remainings (if K>C*S)
      fileToWrite.write(" "+str(tileToClean+1))
    fileToWrite.write("\n")
  iLineNum+=1
fileToWrite.close()
print 'Total time:   ', time.time() - time1
print 'Solving time: ', time.time() - time2
