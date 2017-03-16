#!/usr/bin/python -u

import sys,re

if len(sys.argv) != 2:
  print "usage: " + sys.argv[0] + " infile"
  sys.exit()
infile = open(sys.argv[1], 'r')

debugprint = 1

def debug(str, lvl=5):
  if debugprint > lvl: print "[DEBUG]", str

def has_x_won(lines):
  if has_won_across(lines, 'X'): return True
  if has_won_down(lines, 'X'): return True
  if has_won_diag(lines, 'X'): return True
  return False

def has_o_won(lines):
  if has_won_across(lines, 'O'): return True
  if has_won_down(lines, 'O'): return True
  if has_won_diag(lines, 'O'): return True
  return False

def is_winning_line(line, c):
  if type(line)==type([]):
    line = ''.join(line)
  if re.match('['+c+'T]{4}',line):
    return True
  return False

def has_won_across(lines, c):
  for line in lines:
    if is_winning_line(line, c):
      return True
  return False

def has_won_down(lines, c):
  for i in range(4):
    line_d = [line[i] for line in lines]
    if is_winning_line(line_d, c):
      return True
  return False

def has_game_completed(lines):
  for line in lines:
    if re.search('\.', line):
      return False
  return True

def has_won_diag(lines, c):
  d1 = [lines[i][i] for i in range(4)]
  if is_winning_line(d1, c): return True
  d2 = [lines[3-i][i] for i in range(4)]
  if is_winning_line(d2, c): return True
  return False

def handleonecase(lines):
  if has_x_won(lines): return 'X won'
  if has_o_won(lines): return 'O won'
  if has_game_completed(lines): return 'Draw'
  return 'Game has not completed'


line = infile.readline().strip()
maxcases = int(line)
casenum = 0

while line:
  casenum = casenum + 1
  if casenum > maxcases: break
  line1 = infile.readline().strip()
  line2 = infile.readline().strip()
  line3 = infile.readline().strip()
  line4 = infile.readline().strip()
  line5 = infile.readline().strip()
  lines = [line1, line2, line3, line4]
  result = handleonecase(lines)
  print "Case #" + str(casenum) + ": " + str(result)




