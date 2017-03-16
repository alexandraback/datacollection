#! /usr/bin/env python

def parse(lines):
  n = int(lines[0])
  words = []
  for i in range(n):
    words.append(lines[i+1])
  return words
  
def solve(word):
  smaller = []
  larger = []
  actWord = ""
  actWord = actWord + word[0]
  last = word[0]
  
  
  for i in range(len(word) - 1):
    if word[i+1] < last:
      actWord = actWord + word[i+1]
    else:
      actWord = word[i+1] + actWord
      last = word[i+1]
  
  return actWord
  
  #return ''.join(sorted(word))
    
#with open('B-large.in', 'r') as f:
with open('A-small-attempt0.in', 'r') as f:
  words = parse(f.read().splitlines())
for i in range(len(words)):
  wordSorted = solve(words[i])
  print "Case #" + str(i+1) + ": " + wordSorted
