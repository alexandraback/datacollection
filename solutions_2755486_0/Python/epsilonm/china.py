from heapq import *

def getattacks(day, num, left, right, strength, dday, dpos, dstrength):
  for i in xrange(num):
    yield (day, left, right, strength)
    day += dday
    left += dpos
    right += dpos
    strength += dstrength

def nextattack(attacks):
  return merge(*attacks)

def do(num, tribes):
  wall = [0]*1000000

  success = 0
  attacks = [getattacks(*tribe) for tribe in tribes]
  prev_day = -1
  updates = {}

  for day, left, right, strength in nextattack(attacks):
    if prev_day != day:
      prev_day = day
      for pos in updates:
        wall[pos] = updates[pos]  
      updates = {}
    attack = False
    for i in xrange(left*2, 2*right+1):
      if wall[i+200] < strength:
        attack = True
        if i+200 not in updates:
          updates[i+200] = strength
        else:
          updates[i+200] = max(strength, updates[i+200])
    if attack:
      success +=1

  return success

  

cases = int(raw_input())

for case in xrange(1, cases+1):
  num = int(raw_input())
  
  res = do(num, [map(int, raw_input().split(' ')) for i in xrange(num)])
  print 'Case #%d: %d' %(case, res)