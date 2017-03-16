#!/usr/bin/python -tt

import sys

def count(line, n):
  counter = 0
  for i in line: 
    if i >= n:
      counter = counter + 1
  return counter

def compute(N, S, p, line): 
  if p == 0:
    return count(line, 0)
  if p == 1:
    return count(line, 1)
  minScore = p-2 + p-2 + p
  safeScore = p-1 + p-1 + p
  #print minScore
  #print safeScore
  safeWin = count(line, safeScore)
  allWin = count(line, minScore)
  needSurprising = allWin - safeWin
  #print needSurprising
  totalWin = safeWin + min(needSurprising, S)
  
  return totalWin

def main():
  f = open("B-small-attempt0.in", 'rU')
  lines = f.readline()
  
  output = open('output', 'w')
  for i in range(int(lines)):
    line = map(int, f.readline().split(" "))
    N = line.pop(0)
    S = line.pop(0)
    p = line.pop(0)
    out = compute(N, S, p, line)
    #print out
    output.write("Case #"+str(i+1)+': '+str(out)+'\n')
    #print "Case #",print str(i+1), out, 
  f.close()
  output.close()
  
if __name__ == '__main__':
  main()

