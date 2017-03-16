import string
import time

startTime=time.time()

testIndex=2

problemRoot="d:/prog/versenyek/googlejam"
problemDir="2015/round1c"
inputFiles= ["A_example.in",  "A-small.in",  "A-large.in"]
outputFiles=["A_example.out", "A-small.out", "A-large.out"]

fileName=string.strip(problemRoot)+"/"+problemDir+"/"+inputFiles[testIndex]
inputData=[map(int, line.split()) for line in open(fileName,'r') if line.strip()]
fileName=string.strip(problemRoot)+"/"+problemDir+"/"+outputFiles[testIndex]
fileToWrite=open(fileName,'w')
# preparing
for iCase in range(inputData[0][0]):
  R,C,W=inputData[iCase+1]
  print "Case: ",iCase+1
  if W==1:
    fileToWrite.write("Case #"+str(iCase+1)+": "+str(R*C)+"\n") # all cells
  elif W==C:
    fileToWrite.write("Case #"+str(iCase+1)+": "+str(R+W-1)+"\n") # all lines ones, and the remaining W-1 cells
  elif C%W==0:
    lineSlice=C/W
    fileToWrite.write("Case #"+str(iCase+1)+": "+str(R*lineSlice+W-1)+"\n") # W sliced for each line and the remaining W-1 cells
  else:
    lineSlice=C/W
    fileToWrite.write("Case #"+str(iCase+1)+": "+str(R*lineSlice+1+W-1)+"\n") # W sliced for each line and 1 for the slice the other and and W-1
fileToWrite.close()
print time.time()-startTime
