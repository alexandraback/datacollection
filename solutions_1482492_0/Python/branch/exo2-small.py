import os
import sys
import math

def solveCases(cases):
  elemL = cases[0].split()
  dist = float(elemL[0])
  nbDistAdv = int(elemL[1])
  nbAcc = int(elemL[2])
  posAdv = []
  for line in cases[1:(1+nbDistAdv)]:
    spl = line.split()
    posAdv.append((float(spl[0]),float(spl[1])))
  elemAcc = cases[-1].split()
  print len(posAdv), dist, posAdv[0][1], posAdv[0][0]
  acc = []
  sol = []
  for elem in elemAcc:
    acc.append(float(elem))
  for accel in acc:
    sol.append(solveCase(accel,dist,posAdv))
  return sol

def solveCase(acc,dist,pos):
  # We check if the last position of the other car is past the line
  if pos[-1][1] > dist and len(pos) > 1:
    speed = (pos[-1][1]-pos[-2][1])/(pos[-1][0]-pos[-2][0])
    arrivalTime = pos[-2][0] + (dist - pos[-2][1])/speed
    pos[-1] = (arrivalTime,dist)
  if len(pos) == 1:
    return math.sqrt(dist/(0.5*acc))
  if len(pos) == 2:
    if math.sqrt(dist/(0.5*acc)) < pos[1][0]:
      return pos[1][0]
    else:
      return math.sqrt(dist/(0.5*acc))
  if len(pos) == 3:
    posOurCar = 0.5*acc*pos[1][0]*pos[1][0]
    if posOurCar > pos[1][1]:
      timeTot = math.sqrt(dist/(0.5*acc))
      timeF = math.sqrt(pos[1][1]/(0.5*acc))
      if pos[1][0] + timeTot - timeF > pos[2][0]:
        return (pos[1][0] + timeTot - timeF)
      else:
        return pos[2][0]
    else:
      posOurCar = 0.5*acc*pos[2][0]*pos[2][0]
      if posOurCar > pos[2][1]:
        return pos[2][0]
      else:
        return math.sqrt(dist/(0.5*acc))

def solve(pathI,pathOut):
  counter = 1
  fI = file(pathI,'rU')
  fO = file(pathOut,'w')
  lines = fI.readlines()
  nbCases = int(lines[0])
  line = 1
  for case in range(nbCases):
    elem = lines[line].split()
    nbAdv = int(elem[-2])
    endLine = 1 + nbAdv + line + 1
    answs = solveCases(lines[line:endLine])
    line = endLine
    fO.write('Case #')
    fO.write(str(counter))
    fO.write(':\n')
    for elements in answs:
      fO.write(str(elements))
      fO.write('\n')
    counter+=1
  fI.close()
  fO.close()



def main():
  args = sys.argv[1:]
  solve(args[0],args[1])


main()

