# qualb.py

#f = open('test', 'r')
f = open('B-small-attempt0.in', 'r')

T = int(f.readline()) 

def valid(lawn, N, M):
 
  if N==0 or M==0:
    return 'YES'
  
  low = lawn[0][0]
  minx = 0
  miny = 0
  # find min
  for x in range(M):
    for y in range(N):
      if lawn[y][x] < low:
	low = lawn[y][x]
	minx = x
	miny = y
	
  if all(lawn[miny][x] == low for x in range(M)):
    del lawn[miny]
    return valid(lawn, N-1, M)
  elif all(lawn[y][minx] == low for y in range(N)):
    for y in range(N):
      del lawn[y][minx]
    return valid(lawn, N, M-1)
  else:
    return 'NO'

for t in range(1, T+1):
  N, M = [int(num) for num in f.readline().split()]
  
  lawn = []
  for i in range(N):
    lawn.append([int(num) for num in f.readline().split()])
    
  print "Case #" + str(t) + ": " + valid(lawn, N, M)
  
