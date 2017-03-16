# -*- coding: utf-8 -*-

inputFile = open("input.in","r")
resultFile = open("result.out","w")

nbCase = 0
case = 0

for line in inputFile:
   # Result type : For each case -> "Case #X: resultValue" 
   # Don't parse the first line containing the number of cases
   if nbCase == 0:
      nbCase = int(line.strip('\n'))
   else:
      case += 1
      result = 0   
      tab = [0,0,0,0,0,0,0,0,0,0]
      if int(line.strip('\n')) == 0:
         result = "INSOMNIA"
      else:
         i = 1
         N = int(line.strip('\n'))
         strN = line.strip('\n')   
         while True:      
            for elt in strN:
               tab[int(elt)] = 1
            if tab.count(0) == 0:
               result = N
               break
            else:
               i += 1
               N = i*int(line.strip('\n'))
               strN = str(N)      
        
      resultFile.write("Case #"+str(case)+": "+str(result)+"\n")
      
inputFile.close()
resultFile.close()      
