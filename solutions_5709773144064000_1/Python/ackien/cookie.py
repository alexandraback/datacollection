import sys

def main():
  filename = sys.argv[1]
  fileIn = open(filename, 'r')
  fileOut = open("out.txt", 'w')
  T =  int(fileIn.readline())
  for case in range(T):
    C,F,X = map(float,fileIn.readline().split(' '))
    answer = solveCase(C,F,X)
    fileOut.write("Case #{:d}: {:.7f}\n".format(case+1, answer))
  fileOut.close()
  fileIn.close()

def solveCase(C,F,X):
  timeTotal = 0
  curRate = 2
  while True:
    timeLeftFarm = X/(curRate+F)
    timeLeftNoFarm = (X-C)/curRate
    if timeLeftFarm < timeLeftNoFarm:
      timeToNextFarm = C/curRate
      timeTotal += timeToNextFarm
      curRate += F
    if timeLeftNoFarm <= timeLeftFarm:
      timeTotal += X/curRate
      return timeTotal

main()
