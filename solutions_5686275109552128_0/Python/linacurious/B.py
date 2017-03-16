attempt = "B-small-attempt0"

import time
time.clock()

def solve(plates):
  result = max(plates)
  for i in range(1,max(plates)):
    actions = 0
    for plate in plates:
      actions += (plate-1)//i
    result = min(result, (actions+i))
  return str(result)

def main():
  fin = open(attempt + ".in", 'r')
  fout = open(attempt + ".out",'w')

  numcases = int(fin.readline())

  for casenum in range(1,numcases+1):
    fin.readline()
    plates = list(map(int, fin.readline().split()))
    fout.write('Case #' + repr(casenum) + ': ' + solve(plates) + "\n")

  fin.close()
  fout.close()

main()
print(time.clock())