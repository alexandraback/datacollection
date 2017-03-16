import sys

def main():
  filename = sys.argv[1]
  fileIn = open(filename, 'r')
  fileOut = open("out.txt", 'w')
  T =  int(fileIn.readline())
  for case in range(T):
    N = int(fileIn.readline())
    naomiA = map(float,fileIn.readline().split(' '))
    kenA = map(float,fileIn.readline().split(' '))
    naomiB = naomiA[:]
    kenB = kenA[:]
    warAnswer = solveWar(naomiA,kenA)
    dWarAnswer = solveDeceitfulWar(naomiB,kenB)
    fileOut.write("Case #{:d}: {:d} {:d}\n".format(case+1,dWarAnswer,warAnswer))
  fileOut.close()
  fileIn.close()

def solveWar(naomi,ken):
  n = len(naomi)
  points = 0
  for i in range(n):
    chosenN = naomi.pop()
    optionsK = filter(lambda x: x>chosenN, ken)
    if len(optionsK) == 0:
      chosenK = min(ken)
      points += 1
    else:
      chosenK = min(optionsK)
    ken.remove(chosenK)
  return points

def solveDeceitfulWar(naomi,ken):
  n = len(naomi)
  naomi.sort()
  ken.sort()
  points = 0
  for i in range(n):
    if naomi[0] > ken[0]:
      naomi.pop(0)
      ken.pop(0)
      points += 1
    elif naomi[0] < ken[0]:
      naomi.pop(0)
      ken.pop()
  return points

main()
