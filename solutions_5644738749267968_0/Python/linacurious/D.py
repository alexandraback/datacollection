attempt = "D-small-attempt0"

import time
time.clock()

# NB: irl sequence of checks would be different

def solveDWar(naomi, ken):
  naomiwins = 0
  for ni in naomi:
    # if Naomi cannot win, she lies and Ken gives the heaviest block
    if ni < ken[0]:
      ken.pop()
    # if Naomi can win, she wins
    else:
      ken.pop(0)
      naomiwins = naomiwins + 1
  return str(naomiwins)

def solveWar(naomi, ken2):
  naomiwins = 0
  for ni in naomi:
    # Ken places heavier block if he has one
    for ki in ken2:
      if ki > ni:
        ken2.remove(ki)
        break
    # Naomi wins if Ken doesn't have a heavier block
    if ki < ni:
      naomiwins = naomiwins + 1
      ken2.pop(0)
  return str(naomiwins)

fin = open(attempt + ".in", 'r')
fout = open(attempt + ".out",'w')

numcases = int(fin.readline())

for casenum in range(1,numcases+1):
  # read case
  fin.readline()
  naomi = list(float(n) for n in fin.readline().split())
  ken = list(float(n) for n in fin.readline().split())
  naomi.sort()
  ken.sort()
  ken2 = list(ken)
  print('Case #' + repr(casenum) + ': ' + solveDWar(naomi,ken), solveWar(naomi,ken2), file=fout)

fin.close()
fout.close()
print(time.clock())