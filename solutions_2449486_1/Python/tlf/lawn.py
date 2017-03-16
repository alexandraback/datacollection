#! /usr/bin/python
fp = open("input.txt","r")

outputList = []
for caseNo in range(int(fp.readline())):
   NM = fp.readline().split()
   N = int(NM[0])
   M = int(NM[1])
   grassList = []
   for x in range(N):
      line = fp.readline()
      line = line.split(" ")
      intLine = []
      for y in range(M):
         intLine.append(int(line[y]))
      grassList.append(intLine)
   currGrass = []
   for x in range(N):
      line = []
      for y in range(M):
         line.append(100)
      currGrass.append(line)
   for x in range(N):
      max = 0
      for y in range(M):
         if grassList[x][y] > max:
            max = grassList[x][y]
      for y in range(M):
         if currGrass[x][y] > max:
            currGrass[x][y] = max
   for y in range(M):
      max = 0
      for x in range(N):
         if grassList[x][y] > max:
            max = grassList[x][y]
      for x in range(N):
         if currGrass[x][y] > max:
            currGrass[x][y] = max
   for x in range(N):
      max = 0
      for y in range(M):
         if grassList[x][y] > max:
            max = grassList[x][y]
      for y in range(M):
         if currGrass[x][y] > max:
            currGrass[x][y] = max
   print currGrass
   print grassList 
   if currGrass == grassList:
      outputList.append("YES")
   else:
      outputList.append("NO")

fp.close()
outputString = ""
for x in range(len(outputList)):
   outputString += "Case #" + str(x + 1) + ": " + outputList[x] + "\n"

fp = open("output.txt","w")
fp.write(outputString)
fp.close()
