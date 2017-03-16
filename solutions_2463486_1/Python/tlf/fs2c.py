#! /usr/bin/python
import math

def allPalins():
   apalinList = []
   for x in range(1, 10000):
      buff = genPalins(x, False)
      if isPal(buff ** 2):
         apalinList.append(buff)
      buff = genPalins(x, True)
      if isPal(buff ** 2):
         apalinList.append(buff)
   return apalinList

def isPal(intput):
   s = str(intput)
   return (s == s[::-1])

def genPalins(intput, even):
   strput = str(intput)
   if even:
      return int(strput + strput[::-1])
   else:
      return int(strput + strput[:-1][::-1])

fp = open("input.txt","r")

outputList = []
aPalinList = allPalins()
for caseNo in range(int(fp.readline())):
   AB = fp.readline().split()
   A = int(AB[0])
   B = int(AB[1])
   palinList = []
   for x in range(len(aPalinList)):
      if isPal(aPalinList[x] ** 2) and (aPalinList[x] ** 2 >= A) and (aPalinList[x] ** 2 <= B):
         palinList.append(aPalinList[x])
   outputList.append(str(len(palinList)))
fp.close()
outputString = ""
for x in range(len(outputList)):
   outputString += "Case #" + str(x + 1) + ": " + outputList[x] + "\n"

fp = open("output.txt","w")
fp.write(outputString)
fp.close()
