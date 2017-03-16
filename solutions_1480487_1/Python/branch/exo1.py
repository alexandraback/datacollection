import os
import sys


def solveCase(case):
  scores = case.split()
  scores = scores[1:]
  scores = [int(i) for i in scores]
  x = sum(scores)
  sol = ''
  nbSafe = 0
  scoreSafe = 0
  for i in scores:
    dist = (2*float(x)/len(scores))-i
    perc = 100*float(dist)/x
    if perc <= 0:
      nbSafe+=1
      scoreSafe += i

  for i in scores:
    dist = ((float(x-scoreSafe)+float(x))/(len(scores)-nbSafe))-i
    perc = 100*float(dist)/x
    if perc >= 0:
      sol += '%.6f' % (perc) + ' '
    else:
      sol += '0.000000' + ' ' 
  return sol
    
    


def solve(pathI,pathOut):
  counter = 1
  fI = file(pathI,'rU')
  fO = file(pathOut,'w')
  lines = fI.readlines()
  for line in lines[1:]:
    sol = solveCase(line)
    fO.write('Case #')
    fO.write(str(counter))
    fO.write(': ')
    fO.write(sol)
    fO.write('\n')
    counter+=1
  fI.close()
  fO.close()



def main():
  args = sys.argv[1:]
  solve(args[0],args[1])


main()

