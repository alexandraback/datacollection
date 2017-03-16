##### BRUTE FORCE #####
attempt = "B-large"

import time
time.clock()

# C - cost of farm,
# F - increace of cookierate
# X = win condition

def solve(C, F, X):
  cookierate = 2
  time = 0
  while (time + C / cookierate + X / (cookierate + F)) < (time + X / cookierate):
    time = time + C / cookierate
    cookierate = cookierate + F
  return str(time + X / cookierate)


fin = open(attempt + ".in", 'r')
fout = open(attempt + ".out",'w')

numcases = int(fin.readline())

for casenum in range(1,numcases+1):
  C, F, X = (float(n) for n in fin.readline().split())
  print('Case #' + str(casenum) + ': ' + solve(C, F, X), file=fout)

fin.close()
fout.close()
print(time.clock())