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
        
      S = line.strip('\n')
      T = []
      
      for i in range(0,len(S)):
         if S[i] == '-':
            T.append('-')
         else:
            T.append('+')        
      
      T.reverse()     
        
      while T.count('-') != 0:
      
         for i in range(0,len(T)):
         
            if T[i] == '-':
            
               result += 1
            
               for k in range(i,len(T)):
            
                  if T[k] == '-':
                     T[k] = '+'
                  else:
                     T[k] = '-'            
        
      resultFile.write("Case #"+str(case)+": "+str(result)+"\n")
      
inputFile.close()
resultFile.close()      
