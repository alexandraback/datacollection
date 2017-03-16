import sys
import math

def main():
  infd = open(sys.argv[1])
  outfd = open(sys.argv[1] + '.out', 'w')
  T = int(infd.readline())
  for case in range(1, T+1):
    R,C,W = map(int, infd.readline().split())
    outfd.write('Case #' + str(case) + ': ')
    outfd.write(str(solve(R,C,W)) + '\n')
  infd.close()
  outfd.close()

def solve(r,c,w):
  pts = 0
  for i in range(r-1):
    pts += int(math.floor(float(c) / w))
  if c % w == 0:
   pts += int(math.floor(float(c) / w)) + (w - 1) 
  else:
    pts += int(math.floor(float(c) / w)) + w
  return pts

main()
