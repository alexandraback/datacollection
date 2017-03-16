# quala.py

#f = open('test', 'r')
f = open('A-small-attempt1.in', 'r')

T = int(f.readline())

def answer(r, t):
  def paint(n):
    return n*(2*r+2*n-1)
  
  low = 1
  high = 10**18
  
  mid = (low + high)/2
  
  while high - low > 1:
    if paint(mid) <= t:
      low = mid
    else:
      high = mid
    mid = (low + high)/2
  
  if paint(low) <= t and paint(high) > t:
    return low
  else:
    print 'ERROR'

for test in range(1, T+1):
  line = f.readline()
#  print line.split()
  r, t = [int(num) for num in line.split()]
  
  print 'Case #' + str(test) + ': ' + str(answer(r,t))
