import sys

def solve(c, f, x):
  income = 2.0
  time = 0.0
  #best_time = 0.0
  while(1):
    t = c / income
    end_time = time + x / income
    income += f
    time += t
    build_time =  time + x / income
    if end_time <= build_time:
      return "%.7f" %end_time


numcases = int(sys.stdin.readline())
for casenum in range(1,numcases+1):
    c, f, x = [float(x) for x in sys.stdin.readline().split()]
    print 'Case #' + repr(casenum) + ': ' + solve(c,f,x)