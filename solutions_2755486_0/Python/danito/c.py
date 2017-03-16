#!/usr/bin/python -tt


def main(tribes):
  total = 0

  wall = []

  attacks = {}

  for tribe in tribes:
    for i in xrange(tribe[1]):
      day = tribe[0] + tribe[5]*i
      s = tribe[4] + tribe[7]*i
      w = tribe[2] + tribe[6]*i
      e = tribe[3] + tribe[6]*i

      attack = [w,e,s] #west, east, strength
      if attacks.get(day): attacks[day].append(attack)
      else: attacks[day]=[attack]

  for k in sorted(attacks):
    for attack in attacks[k]:
      '''
      print attack
      print wall
      '''

      succeed = 0
      w = attack[0]
      e = attack[1]
      s = attack[2]

      #calculate strength of wall at point i
      #for i in range(w,e+1):
      i = w
      while i <= e:
        m = 0
        for j in wall:
          if j[0] <= i <= j[1] and j[2]>m: m=j[2]
        if s > m: succeed = 1
        i = i + 0.5
          
      if succeed == 1: total = total + 1
        
    #reconstruct wall
    for attack in attacks[k]:
      wall.append((attack[0],attack[1],attack[2]))
    
  return total


if __name__ == '__main__':
  import sys
  T = int(sys.stdin.readline())
  for i in xrange(T):
    N = int(sys.stdin.readline())
    tribes = []
    for j in xrange(N):
      di, ni, wi, ei, si, delta_di, delta_pi, delta_si = map(int,sys.stdin.readline().strip().split(" "))
      tribes.append((di, ni, wi, ei, si, delta_di, delta_pi, delta_si))
    res = main(tribes)
    print "Case #%d: %s" % (i + 1, res)



