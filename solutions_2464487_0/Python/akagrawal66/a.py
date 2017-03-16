def areaforn(r, n):
  return (n)*(4*r+4*(n-1)+2)/2

def solve(fIn, testNum):
  line = fIn.readline()
  (r,t) = (int(x) for x in line.split())
  n = 32
  ans = False
  low = 1
  high = n
  mid = (low+high)/2

  a = areaforn(r, n)
  if a<t : 
    print "error"

  a = areaforn(r, mid)
  while not ans:
    if a < t:
      if areaforn(r, mid+1) > t:
        ans = True
        break
      low = mid
      mid = (low+high)/2
      a = areaforn(r, mid)
    else:
      if a > t:
        if areaforn(r, mid-1) < t:
          mid -= 1
          ans = True
          break
        high = mid
        mid = (low+high)/2
        a = areaforn(r, mid)
      else:
        ans = True
        break

  return str(mid)

def main(file):
  fIn = open(file)
  fOut = open(file+'.out', "w")

  line = fIn.readline()
  numTest = int(line)
  for i in range(numTest):
    print "test", i+1
    fOut.write('Case #' + str(i+1) + ': ' + str(solve(fIn, i+1)) + '\n')

  fIn.close()
  fOut.close()
  return

main("A-small-attempt0.in")
