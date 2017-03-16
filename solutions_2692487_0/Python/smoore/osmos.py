# osmos.py
import sys

def game_complete(A,motes):
  curr_a = A
  for mote in motes:
    if curr_a <= mote: break
    curr_a += mote
  else: return True
  return False

if __name__ == '__main__':
  T = int(sys.stdin.readline().strip())
  for t in range(T):
    line = sys.stdin.readline().strip()
    A = int(line.split()[0])
    N = int(line.split()[1])
    motes_line = sys.stdin.readline().strip()
    motes = sorted([int(x) for x in motes_line.split()])
    #print str(A) + ": " + str(motes)
    ops_per_i = []
    for i in range(len(motes)):
      # let i be the number of motes to drop off the end
      temp_motes = motes[:N-i]
      ops = 0
      curr_a = A
      for mote in temp_motes:
        if curr_a > mote: curr_a += mote
        else:
          while curr_a <= mote:
            curr_a += curr_a-1
            ops+=1
            if ops>N: break # edge cases
          curr_a += mote
      ops_per_i.append(ops+i)
      if ops+i == 0: break
    print "Case #%d: %d" % (t+1,min(ops_per_i+[N])) # max moves is N