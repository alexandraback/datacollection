#!/usr/bin/python

def reach(pos, nextmove, moves):
  while True:
    if pos[0] == 0 and pos[1] == 0:
      return moves
    if pos[1] == 0 or (abs(pos[0]) < abs(pos[1]) and pos[0] != 0):
      if abs(pos[0]) >= nextmove:
        if pos[0] > 0:
          nextdelta = -nextmove
          direction = 'E'
        else:
          nextdelta = nextmove
          direction = 'W'
      else:
        if pos[0] > 0:
          nextdelta = nextmove
          direction = 'W'
        else:
          nextdelta = -nextmove
          direction = 'E'
      pos = [pos[0]+nextdelta, pos[1]]
      nextmove = nextmove+1
      moves = direction + moves
    else:
      if abs(pos[1]) >= nextmove:
        if pos[1] > 0:
          nextdelta = -nextmove
          direction = 'N'
        else:
          nextdelta = nextmove
          direction = 'S'
      else:
        if pos[1] > 0:
          nextdelta = nextmove
          direction = 'S'
        else:
          nextdelta = -nextmove
          direction = 'N'
      pos = [pos[0], pos[1]+nextdelta]
      nextmove = nextmove+1
      moves = direction + moves

if __name__ == "__main__":
  for t in xrange(1, int(raw_input())+1):
    pos = [int(x) for x in raw_input().split()]
    moves = reach((pos[0], pos[1]), 1, '')
    print "Case #%d: %s" % (t, moves[::-1])
