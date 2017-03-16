import string

testIndex=1

problemRoot="d:/prog/versenyek/googlejam"
problemDir="2015/quali"
inputFiles= ["B_example.in",  "B-small.in",  "B-large.in"]
outputFiles=["B_example.out", "B-small.out", "B-large.out"]

fileName=string.strip(problemRoot)+"/"+problemDir+"/"+inputFiles[testIndex]
inputData=[map(int, line.split()) for line in open(fileName,'r') if line.strip()]
fileName=string.strip(problemRoot)+"/"+problemDir+"/"+outputFiles[testIndex]
fileToWrite=open(fileName,'w')
MAX_D=1000
for iCase in range(inputData[0][0]):
  num_Pi=[0]*MAX_D
  maxUsed=0
  for Pi in inputData[iCase*2+2]:
    if Pi>maxUsed:
      maxUsed=Pi
    num_Pi[Pi]+=1
  minMinutes=maxUsed
  for eating in range(1,maxUsed):
    specNeeded=0
    for idx in range(eating+1,maxUsed+1):
      specNeeded+=num_Pi[idx]*((idx-1)/eating)
    if specNeeded+eating<minMinutes:
      minMinutes=specNeeded+eating
  fileToWrite.write("Case #"+str(iCase+1)+": "+str(minMinutes)+"\n")
fileToWrite.close()
