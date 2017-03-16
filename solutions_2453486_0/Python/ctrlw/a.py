#!/usr/bin/python
import sys, math, re

def has_won(c, field):
  win = c * 4
  tmp = field.replace("T", c)
  for i in range(4):
    # Horizontal
    if tmp[i * 4: (i+1) * 4] == win:
      return True
    # Vertical
    if tmp[i::4] == win:
      return True
  # Diagonal
  if tmp[0::5] == win:
    return True
  if tmp[3:15:3] == win:
    return True
  return False
  
  

T = int(sys.stdin.readline())
for t in range(T):
  field = ""
  for i in range(5):
    line = sys.stdin.readline().strip()
    field += line
  #print field
  
  s = "Draw"
  if has_won("X", field):
    s = "X won"
  elif has_won("O", field):
    s = "O won"
  elif field.find(".") >= 0:
    s = "Game has not completed"
  
  print "Case #%d: %s" % (t + 1, s)
