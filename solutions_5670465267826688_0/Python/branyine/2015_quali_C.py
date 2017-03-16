import string

testIndex=1

problemRoot="d:/prog/versenyek/googlejam"
problemDir="2015/quali"
inputFiles= ["C_example.in",  "C-small.in",  "C-large.in"]
outputFiles=["C_example.out", "C-small.out", "C-large.out"]

fileName=string.strip(problemRoot)+"/"+problemDir+"/"+inputFiles[testIndex]
inputData=[map(str, line.split()) for line in open(fileName,'r') if line.strip()]
fileName=string.strip(problemRoot)+"/"+problemDir+"/"+outputFiles[testIndex]
fileToWrite=open(fileName,'w')
mul={}
mul['1']={'i':'i','j':'j','k':'k'}
mul['i']={'i':'-1','j':'k','k':'-j'}
mul['j']={'i':'-k','j':'-1','k':'i'}
mul['k']={'i':'j','j':'-i','k':'-1'}
mul['-1']={'i':'-i','j':'-j','k':'-k'}
mul['-i']={'i':'1','j':'-k','k':'j'}
mul['-j']={'i':'k','j':'1','k':'-i'}
mul['-k']={'i':'-j','j':'i','k':'1'}

for iCase in range(int(inputData[0][0])):
  letters=int(inputData[iCase*2+1][0])
  repeats=int(inputData[iCase*2+1][1])
  word=inputData[iCase*2+2][0]
  subProd='1'
  iFound=False
  ijFound=False
  isTested=False
  isOK=repeats%4!=0 # the whole product is 1 for sure, should be -1 == i*j*k
  actRepeat=0
  while ((not isTested) or (not ijFound)) and isOK \
        and actRepeat<min(repeats,8): # the 4th power of any value (wordProduct) is 1, so 4+4 is enough to search i and ij
    for idx in range(letters):
      subProd=mul[subProd][word[idx]]
      if not iFound:
        if subProd=='i': # multiplication of this prefix is 'i'
          iFound=True
      elif (not ijFound) and subProd=='k': # multiplication of this prefix is 'i*j' (first time after 'i' found)
        ijFound=True
    actRepeat+=1
    if actRepeat==repeats%4: # this is same product as the full product
      isTested=True
      if subProd!='-1': # =i*j*k
        isOK=False
  if isOK and iFound and ijFound: # i and i*j exist as prefix-product and the repeated word's product is equal to i*j*k
    fileToWrite.write("Case #"+str(iCase+1)+": YES\n")
  else:
    fileToWrite.write("Case #"+str(iCase+1)+": NO\n")
fileToWrite.close()
