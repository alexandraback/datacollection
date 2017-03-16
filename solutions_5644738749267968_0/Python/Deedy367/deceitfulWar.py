import sys
from IPython.core.debugger import Tracer;

def optimal_play(her, his):
  herscore = 0
  for her_block in her:
    # Tracer()()
    if his[0] > her_block:
      for his_block in reversed(his):
        if his_block > her_block:
          his.remove(his_block)
          break
    else:
      herscore += 1
      del his[len(his)-1]
  return herscore

def deceit_play(her, his):
  her.reverse()
  his.reverse()
  herscore = 0
  for her_block in her:
    if her_block < his[0]:
      del his[len(his)-1]
    else:
      del his[0]
      herscore+=1
  return herscore

def deceitfulWar(f):
  soln = ''
  cases = int(f.readline())
  for case in xrange(cases):
    num_blocks = int(f.readline())
    naomi_blocks = f.readline().split(' ')
    naomi_blocks = [float(x) for x in naomi_blocks]
    naomi_blocks.sort(reverse=True)
    ken_blocks = f.readline().split(' ')
    ken_blocks = [float(x) for x in ken_blocks]
    ken_blocks.sort(reverse=True)
    op = optimal_play(naomi_blocks, list(ken_blocks))
    dp = deceit_play(naomi_blocks, list(ken_blocks))
    print '{0} {1}'.format(dp, op)
    soln += 'Case #{0}: {1} {2}\n'.format(case+1, dp, op)
  return soln

def writeOutput(file, soln):
  file.write(soln)
  file.close()

if __name__ == '__main__':
  f = open(sys.argv[1])
  soln = deceitfulWar(f)
  f.close()
  g = open("output.txt", "w")
  writeOutput(g, soln)

