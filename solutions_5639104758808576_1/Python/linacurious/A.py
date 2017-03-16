attempt = "A-large"

import time
time.clock()

def solve(maxshy,audience):
  standing = 0
  friends = 0
  for shylvl in range(maxshy+1):
    if standing >= shylvl:
      standing += int(audience[shylvl])
    else:
      friends += (shylvl - standing)
      standing += (shylvl - standing) + int(audience[shylvl])
  return str(friends)

def main():
  fin = open(attempt + ".in", 'r')
  fout = open(attempt + ".out",'w')

  numcases = int(fin.readline())

  for casenum in range(1,numcases+1):
    maxshy, audience = fin.readline().split()
    maxshy = int(maxshy)
    fout.write('Case #' + repr(casenum) + ': ' + solve(maxshy, audience) + "\n")

  fin.close()
  fout.close()

main()
print(time.clock())