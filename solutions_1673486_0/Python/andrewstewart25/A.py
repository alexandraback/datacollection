import sys,operator
data = sys.stdin.readlines()
c=1
i=1

def enter(A,B,probs):
  return 1 + B + 1

def keep(A,B,probs):
  x = reduce(operator.mul,probs)
  print x
  return (B-A+1)*x+(B-A+1+B+1)*(1-x)

def backspace(A,B,probs):
  num = enter(A,B,probs)
  x = reduce(operator.mul,probs)
  z = (B-A+1)*x+(B-A+1+B+1)*(1-x)
  if (z<num):num = z 
  probs = probs[::-1]
  for i in xrange(len(probs)):
    x/=probs[i]
    z = (B - A + (i+1)*2 + 1)*x + (B-A + (i+1)*2 + 1 + B + 1) * (1-x)
    if z<num:num = z
  return num
  
while (i<len(data)):
  A,B = map(int,data[i].strip().split(' '))
  i+=1
  probs = map(float,data[i].strip().split(' '))
  print "Case #%s: %.10f"%(c,backspace(A,B,probs))
  c+=1
  i+=1