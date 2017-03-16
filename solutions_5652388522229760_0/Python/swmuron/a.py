

import sys


def solveIt(firstNum):
  num = 0
  count = 0
  # edge case, 0*x = 0
  if (firstNum == 0):
    return 'INSOMNIA'
  seen = set()

  running = True

  while(running):
    count += 1
    num += firstNum
    numStr = str(num)
    for i in range(len(numStr)):
      seen.add(numStr[i])
    
    running = len(seen) < 10 and count < 1000
    print('count: '+str(count)+' seen: '+''.join(seen))

  return num





# actually process the solution file
with open(sys.argv[1]) as file:
  with open("ans_"+sys.argv[1],'w') as outFile:
    lines = file.read().splitlines()

    count = -1
    for line in lines:
      # skip the test count line
      count += 1
      if (count == 0):
        continue

      result = solveIt(int(line))

      outFile.write('Case #'+str(count)+': '+str(result))
      outFile.write('\n')