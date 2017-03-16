import sys

iFile = open(sys.argv[1],"r")

cases = int(iFile.readline().strip())

for i in range(cases):

  N = int(iFile.readline().strip())
  
  NString = str(N)

  steps = 0
  currentNumber = 0
  
  if(N < 21):
      steps = N
  else:
    steps = 10
    currentNumber = 10
    if(int(NString[(len(NString)+1)/2:]) == 0):
        steps += 1
        N -= 1
        NString = str(N)
    while(currentNumber != N):

      currentString = str(currentNumber)
      curLen = len(currentString)
      if(curLen == len(NString)):
        if(currentString[:curLen/2] == NString[:curLen/2]):
          steps += N - currentNumber
          currentNumber = N
        else:
          steps += int(NString[curLen/2-1::-1]) + 1
          currentNumber += int(NString[curLen/2-1::-1])
          currentNumber = int(str(currentNumber)[::-1])
      else:
          if(int(currentString[:curLen/2]) == (10**(curLen/2))-1):
              steps += 10**curLen - currentNumber
              currentNumber = 10**curLen
          else:
              steps += 10**(curLen/2)
              currentNumber += 10**(curLen/2) - 1
              currentNumber = int(str(currentNumber)[::-1])


  
  output = str(steps)
  
  print("Case #"+str(i+1)+": "+output)
