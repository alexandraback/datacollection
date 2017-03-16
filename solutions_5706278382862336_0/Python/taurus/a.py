from fractions import Fraction
import sys

d = [[]]

def precompute():
  d = [[None for i in range(40)] for j in range(40)]

def main():
  testcases = int(input())
  for caseNr in range(1, testcases+1):
    f = Fraction(input())
    print("Case #%i: %s" % (caseNr, prittySolution(solve(f,0))))

def solve(f,i):
  # if d[f.numerator][f.denominator] == None:
  if i > 40:
    return -1
  if f >= 0.5:
    if check(f*2-1,i+1):
      return i+1
    else:
      return -1
  else:
    return solve(f*2,i+1)

def check(f,i):
  # print(f,i)
  if i > 40:
    return False
  if f == 1 or f == 0:
    return True
  if f >= 0.5:
    return check(f*2-1,i+1)
  else:
    return check(f*2,i+1)


def prittySolution(sol):
  if sol == -1:
    return 'impossible'
  else:
    return sol

if __name__ == "__main__":
  # precompute()
  main()
