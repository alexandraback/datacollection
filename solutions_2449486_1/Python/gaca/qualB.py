import numpy

testCases = open("problem.txt")
results = open("results.txt",'a')

numCases = int(testCases.readline().strip('\n'))

for x in range(1,numCases+1):
   results.write("Case #"+str(x)+": ")
   lawnSize = testCases.readline().split(' ')
   mylist = []
   for row in range(0,int(lawnSize[0])):
      mylist.append([int(x) for x in testCases.readline().strip('\n').split(' ')])
   A = numpy.array(mylist)
   possible = True

   while (possible == True):
      if (A.size == 0):
         results.write("YES\n")
         break
      index = numpy.unravel_index(A.argmin(), A.shape)
   
      rowDif = numpy.ptp(A,axis = 0)
      colDif = numpy.ptp(A,axis = 1)

      if (rowDif[index[1]] == 0):
         A = numpy.delete(A, index[1],axis=1)
      elif (colDif[index[0]] == 0):
         A = numpy.delete(A, index[0],axis=0)
      else:
         possible = False
         results.write("NO\n")

testCases.close()
results.close()
print "Done"
