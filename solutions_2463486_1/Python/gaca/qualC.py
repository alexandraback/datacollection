#Generate palindromes

start  = ['0','1','2','3','4','5','6','7','8','9','00','11','22','33','44','55','66','77','88','99']
add = ['0','1','2','3','4','5','6','7','8','9']
palsq = []

for num in start:
   anum = int(num)**2
   calc = str(anum)
   while (calc[0] == calc[-1] and len(calc)>1):
      calc = calc[1:-1]
   if (len(calc)<2 and anum !=0):
      palsq.append(anum)

for x in range(0,4):
   
   ##generate some set of palindromes based on previous set
   current = []
   for each in start:
      for digit in add:
         num = digit+each+digit
         current.append(num)
   start = current
   
   ##palindrome test the squares of generated
   for num in current:
      anum = int(num)**2
      calc = str(anum)
      while (calc[0] == calc[-1] and len(calc)>1):
         calc = calc[1:-1]
      if (len(calc)<2 and anum !=0):
         palsq.append(anum)

raw_input("Press Enter to continue...")

testCases = open("problem.txt")
results = open("results.txt",'a')
numCases = int(testCases.readline().strip('\n'))

for x in range(1,numCases+1):
   results.write("Case #"+str(x)+": ")
   interval = testCases.readline().split(' ')
   count = 0
   lower = int(interval[0])
   upper = int(interval[1])
   for num in palsq:
      if (num>=lower):
         if (num<=upper):
            count+=1
   results.write(str(count)+'\n')

testCases.close()
results.close()
print "Done"
