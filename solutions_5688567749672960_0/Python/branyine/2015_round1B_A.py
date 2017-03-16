import string

testIndex=1

problemRoot="d:/prog/versenyek/googlejam"
problemDir="2015/round1b"
inputFiles= ["A_example.in",  "A-small.in",  "A-large.in"]
outputFiles=["A_example.out", "A-small.out", "A-large.out"]

fileName=string.strip(problemRoot)+"/"+problemDir+"/"+inputFiles[testIndex]
inputData=[map(int, line.split()) for line in open(fileName,'r') if line.strip()]
fileName=string.strip(problemRoot)+"/"+problemDir+"/"+outputFiles[testIndex]
fileToWrite=open(fileName,'w')
# preparing
MAX=pow(10,6)
mapToSay={1:1}
actList=[1]
while len(actList)>0:
  last=actList.pop(0)
  if (not last+1 in mapToSay) and last+1<=MAX:
    mapToSay[last+1]=mapToSay[last]+1
    actList.append(last+1)
  rev=int(''.join(reversed(str(last))))
  if (not rev in mapToSay) and rev<=MAX:
    mapToSay[rev]=mapToSay[last]+1
    actList.append(rev)
for iCase in range(inputData[0][0]):
  fileToWrite.write("Case #"+str(iCase+1)+": "+str(mapToSay[inputData[iCase+1][0]])+"\n")
fileToWrite.close()
