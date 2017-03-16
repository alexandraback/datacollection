# bullseye.py
import sys

def paintNeeded(n,r):
  a_1 = ((r+((2*1)-1))**2) - ((r+((2*1)-2))**2)
  a_n = ((r+((2*n)-1))**2) - ((r+((2*n)-2))**2)
  return (n*(a_1+a_n))/2

if __name__ == '__main__':
  T = int(sys.stdin.readline().strip())

  for i in range(T):
    line = sys.stdin.readline().strip()
    r = int(line.split()[0]) # cm
    t = int(line.split()[1]) # mm
    max_rings = 10**10 # magic number!
    x = max_rings
    y = 1
    while x - y > 1:
      z = paintNeeded(((x-y)//2)+y,r)
      if z > t: x = ((x-y)//2)+y
      elif z < t: y = ((x-y)//2)+y
      else: 
        y = ((x-y)//2)+y
        break
    '''
    count = 1
    while paintNeeded(count,r) <= t:
      count+=1
    '''
    print "Case #%d: %d" % (i+1,y)
