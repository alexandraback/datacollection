
import sys
import math
import random


def keyEquation(k,c,s):
  if (s < k):
    return ["IMPOSSIBLE"] # this is the hard case worth 20 lol

  # we exploit the small set constraint of K = S
  # in the expected manner. despite any value of C if S >= K then
  # we can define the mathematical distribution of key tiles given K C
  # where a tile perfectly reflects the state of an original sequence tile

  ans = []

  i = 0
  xp = c-1
  xpSum = 0
  while(xp >= 0):
    xpSum += k**xp
    xp -= 1

  index = 0
  while (i < k):
    # ith thing
    #
    # the outer fan we want to get to is k**(c-1)*i+k**(c-2)*i...
    #
    # I visualize it like an arbitrary k-tree --- look at the problem name, after all
    #
    # we factored out the i and just precalculate xpSum once
    # 
    
    
    ans.append(str(index+1))
    index += xpSum
    i += 1

  return ans

with open(sys.argv[1]) as file:
  with open("ans_"+sys.argv[1],'w') as outFile:
    lines = file.read().splitlines()

    count = -1
    for line in lines:
      # skip the test count line
      count += 1
      if (count == 0):
        continue

      lineSplit = line.split(' ')

      result = keyEquation(int(lineSplit[0]),int(lineSplit[1]),int(lineSplit[2]))

      outFile.write('Case #'+str(count)+': '+' '.join(result))
      outFile.write('\n')