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
      
      print case
      
      # L = 0
      # G = 1 
      
      K = line.split(' ')[0]
      C = line.split(' ')[1]
      S = line.split(' ')[2].strip('\n')
      
      print "K = "+K+"; C = "+C+"; S = "+S
      
      K = int(K)
      C = int(C)
      S = int(S)
      
      artwork = []
      
      #for i in range(0,2**K):
      
       #  strTiles = bin(i).split('b')[1]
        # while len(strTiles) < K:
         #   strTiles = "0"+strTiles
    #     fillOfG = ''
     #    while len(fillOfG) < K:
      #      fillOfG = "1"+fillOfG   
            
   #      buf = strTiles
         
    #     for j in range(1,C):
     #       temp = ''
      #      for elt in buf[:-1]:
       #        if elt == '0':
        #          temp += strTiles
         #      else: 
          #        temp += fillOfG
           # buf = buf+temp          
            
#         artwork.append(buf)
         
 #     print artwork 
       
      result = ''
      for i in range(0,K):
         result = result+str(i+1)+" "
         
      print result   
            
      resultFile.write("Case #"+str(case)+": "+str(result)+"\n")
      
inputFile.close()
resultFile.close()      
