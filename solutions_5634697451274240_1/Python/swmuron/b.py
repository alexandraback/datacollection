
import sys

# if there are happy on top, flip only the first sequence of happy
# then we flip them to the bottom where the happy stay flipped for the rest of the problem
#
# flipStack then flips the entire active stack (i.e. not the happy that we leave as solved at the bottom)
# it ensures that flipStack will flip blank faces to the bottom as happy, reducing the solution to a subproblem
def quickFlip(stack):
  result = -1

  while(stack[result+1] == '+'):
    result += 1

  if (result == -1):
    return -1
  else:
    return result+1

#
# Finds how far we are in our solution, as measured by where the last incorrect pancake is
# everything below it is flipped correctly and ignroed
#
def stackSolutionValue(stack):
  lastBad = -1
  for i in range(len(stack)):
    x = stack[i]
    if (x == '-'):
      lastBad = i
  if (lastBad == -1):
    return lastBad
  else:
    return lastBad+1

# flips everything down to the given index
def flipStack(stack, toIndex):
  tmp = []

  for i in range(toIndex):
    x = stack[i]
    if (x == '-'):
      tmp.append('+')
    else:
      tmp.append('-')

  tmp.reverse()

  tmp = ''.join(tmp)
  stackOld = stack
  stack = tmp + stack[toIndex:]

  print(stackOld+' => '+tmp+' => '+stack)

  return stack

# iteratively solve a stack by flipping pancakes to the bottom as happy
# once they're at the bottom, we can exclude them from further flipping
def solveStack(stack):
  maxI = stackSolutionValue(stack)

  iters = 0

  while(maxI != -1):
    flipNum = quickFlip(stack)
    if (flipNum == -1):
      flipNum = maxI
    stack = flipStack(stack,flipNum)

    iters += 1
    maxI = stackSolutionValue(stack)
    print("iters: "+str(iters)+" maxI: "+str(maxI)+" Stack: "+stack)

  return iters

# actually process the solution file
with open(sys.argv[1]) as file:
  with open("ans_"+sys.argv[1],'w') as outFile:
    lines = file.read().splitlines()

    count = 0
    for line in lines:
      # skip the test count line
      if (line[0] <> '+' and line[0] <> '-'):
        continue
      count += 1
      result = solveStack(line)

      outFile.write('Case #'+str(count)+': '+str(result))
      outFile.write('\n')