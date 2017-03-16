# -*- coding: utf-8 -*-

inputFile = open("input.in","r")
resultFile = open("result.out","w")

nbCase = 0
case = 0
result = 0

for line in inputFile:
   # Result type : For each case -> "Case #X: resultValue" 
   # Don't parse the first line containing the number of cases
   if nbCase == 0:
      nbCase = int(line.strip('\n'))
   else:
      case += 1
      
      resultFile.write("Case #"+str(case)+":\n")
            
      N = int(line.split(' ')[0])
      print(N)
      J = int(line.split(' ')[1].strip('\n'))
      print(J)
      
      
      jamcoin = 2**(N-1)+1+2
      
      while jamcoin <= 2**N-1 and result < J:
      
         jamcoinBin = bin(jamcoin)

         listOfDivider = [0,0,0,0,0,0,0,0,0]
         
         for base in range(2,11):
         
            jamcoinRebased = 0
            k = 0
         
            for elt in jamcoinBin[::-1]:
               if elt == 'b':
                  break
               else:
                  jamcoinRebased += (base**k)*int(elt)
                  k += 1
            
            for i in range(2,2000):
               if jamcoinRebased % i == 0 and i < jamcoinRebased:
                  listOfDivider[base-2] = i
                  break       
             
         print listOfDivider
         
         if listOfDivider.count(0) == 0:
         
            result += 1
         
            buf = ''
            
            for elt in listOfDivider:
               buf += " "+str(elt)
         
            resultFile.write(str(jamcoinBin.split('b')[1])+buf+"\n")
             
         jamcoin += 2
        
      # resultFile.write("Case #"+str(case)+": "+str(result)+"\n")
      
inputFile.close()
resultFile.close()      
