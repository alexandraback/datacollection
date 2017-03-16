import math

fin = open('in1.txt','r')
fout = open('out1.txt','w')

T = int(fin.readline().strip())

#initial guess
def guess(r,t):
  return (math.sqrt((2*r-1)**2 + 4*2*t)-(2*r-1))/4.0

#correct for numerical error when things are big
def adjust(s,r,t):
  if (s*(2*r+1)+2*s*(s-1) <= t):
    while (s*(2*r+1)+2*s*(s-1) <= t):
      s = s + 1
    return s - 1
  else:
    while (s*(2*r+1)+2*s*(s-1) > t):
      s = s - 1
    return s

for idx, line in enumerate(fin):
  r,t = [long(a) for a in line.strip().split(' ')]
  s = long(math.floor(guess(float(r),float(t))))
  s = adjust(s,r,t)
  out = "Case #" + str(idx+1) + ": " + str(s) + "\n"
  fout.write(out)

fin.close()
fout.close()
