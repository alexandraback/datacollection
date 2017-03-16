import re

testCases = open("problem.txt")
results = open("results.txt",'a')

xhwon = re.compile('[TX]{4}')
xvwon = re.compile('([TX].{4}){3}[TX]')
xd1won = re.compile('([TX].{5}){3}[TX]')
xd2won = re.compile('...([TX].{3}){3}[TX]')

ohwon = re.compile('[OT]{4}')
ovwon = re.compile('([OT].{4}){3}[OT]')
od1won = re.compile('([OT].{5}){3}[OT]')
od2won = re.compile('...([OT].{3}){3}[OT]')

draw = re.compile('[OTXa]{19}')

numCases = int(testCases.readline().strip('\n'))

for x in range(1,numCases+1):
   results.write("Case #"+str(x)+": ")
   grid = testCases.readline().strip('\n')+'a' + testCases.readline().strip('\n')+'a'+ testCases.readline().strip('\n') +'a' + testCases.readline().strip('\n')

   if (None != xhwon.search(grid)):
      results.write("X won\n")
   elif (None != xvwon.search(grid)):
      results.write("X won\n")
   elif (None != xd1won.match(grid)):
      results.write("X won\n")
   elif (None != xd2won.match(grid)):
      results.write("X won\n")
   elif (None != ohwon.search(grid)):
      results.write("O won\n")
   elif (None != ovwon.search(grid)):
      results.write("O won\n")
   elif (None != od1won.match(grid)):
      results.write("O won\n")
   elif (None != od2won.match(grid)):
      results.write("O won\n")
   elif (None != draw.search(grid)):
      results.write("Draw\n")
   else:
      results.write("Game has not completed\n")
   testCases.readline()

testCases.close()
results.close()
print "Done"
