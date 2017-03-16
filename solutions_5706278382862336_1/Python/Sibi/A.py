import sys,math,fractions

iFile = open(sys.argv[1],"r")

size = int(iFile.readline().strip())

power = math.pow(2,40)

for i in range(size):

  line = iFile.readline().strip().split("/")
  
  P = int(line[0])
  Q = int(line[1])
  
  divisor = fractions.gcd(P,Q)
  P = P / divisor
  Q = Q / divisor
  
  if power % Q != 0.0:
    output = "impossible"
  else:
    for j in range(1,40):
      if 1/(math.pow(2,j)) <= P/Q:
        level = j
        break
    output = str(level)
        
  
  print("Case #"+str(i+1)+": "+output)
