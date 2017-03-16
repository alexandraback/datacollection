attempt = "D-large"

import time
time.clock()

def solve(omsize, maxdim, mindim):
  win = 'RICHARD' # if there is at least one choice that ensures victory for Richard
  lose = 'GABRIEL' # if Gabriel will win no matter what Richard chooses

  if omsize >= 7:
    return win
  if (maxdim * mindim) % omsize != 0:
    return win
  if maxdim < omsize:
    return win
  if mindim < (omsize + 1) // 2:
    return win
  if omsize in [1,2,3]:
    return lose
  if omsize == 4 and mindim == 2:
    return win
  if omsize == 5 and mindim == 3 and maxdim == 5:
    return win
  if omsize == 6 and mindim == 3:
    return win
  return lose

def main():
  fin = open(attempt + ".in", 'r')
  fout = open(attempt + ".out",'w')

  numcases = int(fin.readline())

  for casenum in range(1,numcases+1):
    x, r, c = map(int, fin.readline().split())
    fout.write('Case #' + repr(casenum) + ': ' + solve(x, max(r,c), min(r,c)) + "\n")

  fin.close()
  fout.close()

main()
print(time.clock())