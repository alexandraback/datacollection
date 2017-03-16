import string

testIndex=1

problemRoot="d:/prog/versenyek/googlejam"
problemDir="2015/quali"
inputFiles= ["A_example.in",  "A-small.in",  "A-large.in"]
outputFiles=["A_example.out", "A-small.out", "A-large.out"]

fileName=string.strip(problemRoot)+"/"+problemDir+"/"+inputFiles[testIndex]
inputData=[map(str, line.split()) for line in open(fileName,'r') if line.strip()]
fileName=string.strip(problemRoot)+"/"+problemDir+"/"+outputFiles[testIndex]
fileToWrite=open(fileName,'w')
for iCase in range(int(inputData[0][0])):
  S=[int(c) for c in inputData[iCase+1][1]]
  iStanding=0
  iNeeded=0
  for idx in range(len(S)):
    if iStanding<idx:
      iNeeded+=idx-iStanding
      iStanding=idx+S[idx]
    else:
      iStanding+=S[idx]
  fileToWrite.write("Case #"+str(iCase+1)+": "+str(iNeeded)+"\n")
fileToWrite.close()
