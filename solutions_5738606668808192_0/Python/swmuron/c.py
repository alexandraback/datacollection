
import sys

import math


storedDivisors = dict()

def findDivisorNaive(p):
  if (p in storedDivisors):
    return storedDivisors[p]

  maxI = math.sqrt(p)
  i = 2
  while (p % i <> 0 and i <= maxI):
    i += 1

  if (maxI < i):
    i = None
  storedDivisors[p] = i
  return i


def checkIt(s):
  ans = [s]
  for i in range(2,11):
    n = int(s,i)
    d = findDivisorNaive(n)
    ans.append(str(d))
    if (d == None or d == 0):
      print(s+'('+str(n)+') failed @ base '+str(i)+' d returned was '+str(d))
      return None
    print str(i)+'base found divisor for '+str(n)+' = '+str(d)
  print(s+' success '+str(len(ans)))
  return ans

# actually process the solution file

with open(sys.argv[1]) as f:
  fLines = f.read().splitlines()

  vals = fLines[1].split(' ')

  n = int(vals[0])
  maxJ = int(vals[1])
  with open("ans_"+sys.argv[1],'w') as outFile:
    #for n in range(2,16):
    outFile.write('Case #1:\n')
    jFound = 0

    # look for up to maxJ
    nPow = int(math.pow(2,n-2))

    for i in range(0, nPow):
      if (n == 2):
        s = '11'
      else:
        s = '1'+bin(i)[2:].zfill(n-2)+'1'
      print 'checking s='+s
      r = checkIt(s)
      if (r <> None):
        joinS = ' '.join(r)
        outFile.write(joinS+'\n')
        jFound += 1
        if (jFound >= maxJ):
          break

    outFile.close()
