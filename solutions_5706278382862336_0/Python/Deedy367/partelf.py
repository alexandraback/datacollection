import sys
from IPython.core.debugger import Tracer
from fractions import gcd



def recurse_find(num, den):
  if num == 0:
    return sys.maxint
  gcdd = gcd(num, den)
  if not gcdd == 0:
    num = num/gcdd
    den = den/gcdd
  if num == 1 and den == 1:
    return 0
  return min(recurse_find((num-1)/2, den/2), recurse_find((num+1)/2, den/2)) + 1

def find(num, den):
 return msb(den) - msb(num)


def msb(num):
  msb = 0
  while not num >> msb == 0:
    msb += 1
  return msb


def partelf(f):
  soln = ''
  cases = int(f.readline())
  for case in xrange(cases):
    input_case = f.readline().split('/')
    input_case = [int(x) for x in input_case]
    gcdd = gcd(input_case[0], input_case[1])
    num = input_case[0]/gcdd
    den = input_case[1]/gcdd
    if not den & (den - 1) == 0:
      soln += 'Case #{0}: impossible\n'.format(case+1)
    else:
      sol = find(num, den)
      soln += 'Case #{0}: {1}\n'.format(case+1, sol)
  return soln

def writeOutput(file, soln):
  file.write(soln)
  file.close()

if __name__ == '__main__':
  f = open(sys.argv[1])
  soln = partelf(f)
  f.close()
  g = open("output.txt", "w")
  writeOutput(g, soln)

