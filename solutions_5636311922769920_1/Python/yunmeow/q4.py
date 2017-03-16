import random
def permute(oldStr):
  for idx in range(26):
    temp = oldStr[idx]
    randIndex = random.randint(0, 25) 
    oldStr[idx] = oldStr[randIndex]
    oldStr[randIndex] = temp

def check(oldStr, wordList):
  inputStr = "".join(oldStr)
  for oneStr in wordList:
    if inputStr.find(oneStr) >= 0:
      return True

  return False

#f = open("./D-large.in", "r")
f = open("./D-small-attempt0.in", "r")
#f = open("./test.in", "r")
inputList = list(f)
numTest = int(inputList[0])
#print (numTest)
counter = 1
numLabel = -1
for line in inputList[1:]:
  numbers = line.split(" ")
  K = int(numbers[0])
  C = int(numbers[1])
  S = int(numbers[2])
  if C == 1:
    if S < K:
      print ("Case #{}: IMPOSSIBLE".format(counter))
    else:
      numList = range(1, K+1)
      final = [str(pos) for pos in numList]
      print ("Case #{}: {}".format(counter, " ".join(final)) )

  else:
    if S < K-1:
      print ("Case #{}: IMPOSSIBLE".format(counter))
    else:
      numList = range(2, K+1)
      final = [str(pos) for pos in numList]
      print ("Case #{}: {}".format(counter, " ".join(final)) )
  counter+=1

