from math import sqrt

iFile = open("A-small-attempt1.in","r")
oFile = open("output.txt","w")

cases = int(iFile.readline().strip())

for case in range(cases):
  
  line = iFile.readline().strip().split()
  r = int(line[0])
  t = int(line[1])
  
  n = (sqrt(4*r**2-4*r+8*t+1) - 2*r + 1) / 4.0
  
  n = int(n)
  realN = n+2
  for i in range(n-1,n+3):
    if i*(2*r+2*i-1) > t:
      realN = i-1
      break
  
  if realN == n-2:
    print "below bounds"
  
  if realN == n+2:
    print "above bounds"

  output = str(realN)
  
  oFile.write("Case #"+str(case+1)+": "+output+"\n")
