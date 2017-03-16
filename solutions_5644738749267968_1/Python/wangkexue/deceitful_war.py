import sys
from collections import deque

def war(naomi, ken):
  naomi.sort()
  ken.sort()
  ken = deque(ken)
  p = 0
  for x in naomi:
    if x > ken[-1]:
      p += 1
      ken.popleft()
    else:
      var = next((y for y in ken if y > x), None)
      if var:
        ken.remove(var)
      else:
        p += 1
        ken.popleft()
  return str(p)

'''The value of Told_naomi is not important
   The behavior of two players is the key
'''
def dwar(naomi, ken):
  naomi.sort()
  # diff to war. cauz we need to scan ken from max to min
  # ken[-1] is min, ken[0] is max
  ken.sort()
  ken.reverse()
  ken = deque(ken)
  p = 0
  for x in naomi:
    # if naomi's block is less than ken's min block
    # then naomi can't score, so she will told a weight less
    # then the ken's max block, let ken use his max block 
    if x < ken[-1]:
      if len(ken) == 1:
        break
      ken.popleft()
    # if naomi's block is bigger than ken's min block
    # then naomi must score
    # she told ken a value bigger than ken's max block
    # then ken will use his min block
    # naomi use her min block bigger than ken's min block
    else:
      var = next((y for y in ken if y < x), None)
      p += 1
      ken.remove(var)
  return str(p)



numcases = int(sys.stdin.readline())
for casenum in range(1,numcases+1):
  blocks = []
  sys.stdin.readline()
  for i in range(0,2):
    blocks.append([float(x) for x in sys.stdin.readline().split()])
  print 'Case #' + repr(casenum) + ': ' + dwar(blocks[0], blocks[1]) + ' ' + war(blocks[0], blocks[1])



  '''
  def solve(naomi, ken):
  naomi.sort()
  ken.sort()
  print naomi
  print ken
  fold = next((i for i, x in enumerate(naomi) if x > ken[-1]), None)
  if fold and fold != 0:
    naomi = naomi[fold:] + naomi[0:fold]
  print naomi
  print [x for x, y in zip(naomi, ken) if x > y]
  return str(len([x for x, y in zip(naomi, ken) if x > y]))
  '''