#! /usr/bin/python
import math

fp = open("input.txt","r")

def isPalin(intput):
   inputString = str(intput)
   mid = len(inputString) / 2
   left = inputString[:mid]
   if len(inputString) % 2 == 1:
      right = inputString[mid + 1:]
   else:
      right = inputString[mid:]
   if left == right[::-1]:
      return True 
   else:
      return False


outputList = []
for caseNo in range(int(fp.readline())):
   AB = fp.readline().split()
   A = int(AB[0])
   B = int(AB[1])
   count = 0
   for x in range(A, B + 1):
      if math.sqrt(x) == int(math.sqrt(x)):
         if isPalin(x) and isPalin(int(math.sqrt(x))):
            count += 1
   outputList.append(str(count))
fp.close()
outputString = ""
for x in range(len(outputList)):
   outputString += "Case #" + str(x + 1) + ": " + outputList[x] + "\n"

fp = open("output.txt","w")
fp.write(outputString)
fp.close()
