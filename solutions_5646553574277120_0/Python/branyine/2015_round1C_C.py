import string
import itertools
import time

startTime=time.time()

testIndex=1

problemRoot="d:/prog/versenyek/googlejam"
problemDir="2015/round1c"
inputFiles= ["C_example.in",  "C-small.in",  "C-large.in"]
outputFiles=["C_example.out", "C-small.out", "C-large.out"]

fileName=string.strip(problemRoot)+"/"+problemDir+"/"+inputFiles[testIndex]
inputData=[map(int, line.split()) for line in open(fileName,'r') if line.strip()]
fileName=string.strip(problemRoot)+"/"+problemDir+"/"+outputFiles[testIndex]
fileToWrite=open(fileName,'w')
for iCase in range(inputData[0][0]):
  print "Case: ",iCase+1
  C,D,V=inputData[iCase*2+1]
  listDenom=inputData[iCase*2+2]
  setAll=set([0])
  for num in listDenom:
    actSet=setAll.copy()
    for act in actSet:
      for mul in range(1,min(C,(V-act)/num)+1):
        if act+mul*num not in actSet :
          setAll.add(act+mul*num)
  num=1
  needed=0
  while num<=V:
    if num not in setAll:
      needed+=1
      actSet=setAll.copy()
      for act in actSet:
        for mul in range(1,min(C,(V-act)/num)+1):
          if act+mul*num not in actSet :
            setAll.add(act+mul*num)
    num+=1
  fileToWrite.write("Case #"+str(iCase+1)+": "+str(needed)+"\n")
fileToWrite.close()
print time.time()-startTime
