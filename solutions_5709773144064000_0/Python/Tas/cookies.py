import sys


def calc_next(C, F, X, last_speed, last_time_to_start):
  speed = last_speed + F
  time_to_start = last_time_to_start + (C / last_speed)
  time = time_to_start + X / speed
  return time, time_to_start, speed

def get_best_time(C,F,X):
  speed = 2.0
  time_to_start = 0.0
  time = X / speed
  best_time = time
  nFarms = 0
  while True:
    time, time_to_start, speed = calc_next(C, F, X, speed, time_to_start)
    #print time, best_time
    if time < best_time: #- 1e-10:
      nFarms += 1
      best_time = time
    else:
      return best_time, nFarms 
  
def proc_case():
  C, F, X = [ float(x) for x in sys.stdin.readline().split()]
  #print C, F, X, 
  btime, nf = get_best_time(C, F, X)
  print btime

def main():
  T = int(sys.stdin.readline())
  for caseNo in xrange(T):
    print "Case #" + str(caseNo + 1) + ":",
    proc_case()

if __name__ == "__main__":
  main()