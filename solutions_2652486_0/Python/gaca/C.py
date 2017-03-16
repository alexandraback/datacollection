from operator import itemgetter

testCases = open("problem.txt")
results = open("results.txt",'a')

numCases = int(testCases.readline().strip('\n'))

for x in range(1,numCases+1):
   results.write("Case #"+str(x)+": \n")
   case = [int(z) for z in testCases.readline().split()]
   for z in xrange(case[0]):
      products = [int(z) for z in testCases.readline().split()]
      numberArray = []
      count3 = 0
      count5 = 0
      for product in products:
         if (product %3==0):
            count3=max(1,count3)
         if (product % 9==0):
            count3=max(2,count3)
         if (product % 27==0):
            count3=max(3,count3)
         if (product %5==0):
            count5=max(1,count5)
         if (product % 25==0):
            count5=max(2,count5)
         if (product % 125==0):
            count5=max(3,count5)
      while (count3>0):
         numberArray.append(3)
         count3-=1
      while (count5>0):
         numberArray.append(5)
         count5-=1

      remaining = 3-len(numberArray)
      while (remaining >0 ):
         if (remaining == 1):
            for product in products:
               if (product %4==0 and remaining == 1):
                  numberArray.append(4)
                  remaining = 0
            if (remaining == 1):
               numberArray.append(2)
               remaining = 0
         if (remaining == 2):
            for product in products:
               if (product %16==0 and remaining == 2):
                  numberArray.append(4)
                  numberArray.append(4)
                  remaining = 0
            if (remaining == 2):
               i=0
               j=0
               for product in products:
                  i+=1
                  if (product %4 !=0):
                     j+=1
               if (i==j):
                  numberArray.append(2)
                  numberArray.append(2)
                  remaining = 0
            if (remaining == 2):
               numberArray.append(4)
               numberArray.append(2)
               remaining = 0
         if (remaining == 3):
            fours = 0
            for product in products:
               if (product %64==0):
                  fours = 3
               if (product %32==0):
                  fours = max(fours,2)
               if (product %16==0):
                  fours = max(fours,1)
            for i in xrange(fours):
               numberArray.append(4)
            for i in xrange(3-fours):
               numberArray.append(2)
            remaining = 0
      astring = ""
      for each in numberArray:
         astring=astring+str(each)
      results.write(astring+"\n")

testCases.close()
results.close()
print "Done"
