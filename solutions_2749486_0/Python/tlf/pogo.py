fp = open("input.txt","r")
outputString = ""
for caseno in range(int(fp.readline())):
   #do stuff here
   inputS = fp.readline().split()
   outputList = []
   x = int(inputS[0])
   y = int(inputS[1])
   if y > 0:
      for i in range(y):
         outputList.append("SN")
   elif y < 0:
      for i in range(-y):
         outputList.append("NS")
   if x > 0:
      for i in range(x):
         outputList.append("WE")
   elif x < 0:
      for i in range(-x):
         outputList.append("EW")
   outputString += "Case #" + str(caseno + 1) + ": " + "".join(outputList) + "\n"
fp.close()
fp = open("output.txt","w")
fp.write(outputString)
fp.close()
