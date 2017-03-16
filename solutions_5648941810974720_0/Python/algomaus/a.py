#! /usr/bin/env python

def parse(lines):
  n = int(lines[0])
  words = []
  for i in range(n):
    words.append(lines[i+1])
  return words
  
def solve(word):
  occs = {}
  for c in word:
    if c in occs.keys():
      occs[c] = occs[c] + 1
    else:
      occs[c] = 1
      
  
  nums = []
  
  # search for zero
  while 'Z' in occs.keys() and 'E' in occs.keys() and 'R' in occs.keys() and 'O' in occs.keys() and occs['Z'] > 0 and occs['E'] > 0 and occs['R'] > 0 and occs['O'] > 0:
    occs['Z'] = occs['Z'] - 1
    occs['E'] = occs['E'] - 1
    occs['R'] = occs['R'] - 1
    occs['O'] = occs['O'] - 1
    nums.append(0)
    
  # search for six
  while 'S' in occs.keys() and 'I' in occs.keys() and 'X' in occs.keys() and occs['S'] > 0 and occs['I'] > 0 and occs['X'] > 0:
    occs['S'] = occs['S'] - 1
    occs['I'] = occs['I'] - 1
    occs['X'] = occs['X'] - 1
    nums.append(6)
    
  # search for eight
  while 'E' in occs.keys() and 'I' in occs.keys() and 'G' in occs.keys() and 'H' in occs.keys() and 'T' in occs.keys() and occs['E'] > 0 and occs['I'] > 0 and occs['G'] > 0 and occs['H'] > 0 and occs['T'] > 0:
    occs['E'] = occs['E'] - 1
    occs['I'] = occs['I'] - 1
    occs['G'] = occs['G'] - 1
    occs['H'] = occs['H'] - 1
    occs['T'] = occs['T'] - 1
    nums.append(8)
    
  # search for two
  while 'T' in occs.keys() and 'W' in occs.keys() and 'O' in occs.keys() and occs['T'] > 0 and occs['W'] > 0 and occs['O'] > 0:
    occs['T'] = occs['T'] - 1
    occs['W'] = occs['W'] - 1
    occs['O'] = occs['O'] - 1
    nums.append(2)
    
  # search for three
  while 'T' in occs.keys() and 'H' in occs.keys() and 'R' in occs.keys() and 'E' in occs.keys() and occs['T'] > 0 and occs['H'] > 0 and occs['R'] > 0 and occs['E'] > 1:
    occs['T'] = occs['T'] - 1
    occs['H'] = occs['H'] - 1
    occs['R'] = occs['R'] - 1
    occs['E'] = occs['E'] - 1
    occs['E'] = occs['E'] - 1
    nums.append(3)
    
  # search for seven
  while 'S' in occs.keys() and 'E' in occs.keys() and 'V' in occs.keys() and 'N' in occs.keys() and occs['S'] > 0 and occs['E'] > 1 and occs['V'] > 0 and occs['N'] > 0:
    occs['S'] = occs['S'] - 1
    occs['E'] = occs['E'] - 1
    occs['V'] = occs['V'] - 1
    occs['E'] = occs['E'] - 1
    occs['N'] = occs['N'] - 1
    nums.append(7)
    
  # search for five
  while 'F' in occs.keys() and 'I' in occs.keys() and 'V' in occs.keys() and 'E' in occs.keys() and occs['F'] > 0 and occs['I'] > 0 and occs['V'] > 0 and occs['E'] > 0:
    occs['F'] = occs['F'] - 1
    occs['I'] = occs['I'] - 1
    occs['V'] = occs['V'] - 1
    occs['E'] = occs['E'] - 1
    nums.append(5)
    
  # search for four
  while 'F' in occs.keys() and 'O' in occs.keys() and 'U' in occs.keys() and 'R' in occs.keys() and occs['F'] > 0 and occs['O'] > 0 and occs['U'] > 0 and occs['R'] > 0:
    occs['F'] = occs['F'] - 1
    occs['O'] = occs['O'] - 1
    occs['U'] = occs['U'] - 1
    occs['R'] = occs['R'] - 1
    nums.append(4)

  # search for one
  while 'O' in occs.keys() and 'N' in occs.keys() and 'E' in occs.keys() and occs['O'] > 0 and occs['N'] > 0 and occs['E'] > 0:
    occs['O'] = occs['O'] - 1
    occs['N'] = occs['N'] - 1
    occs['E'] = occs['E'] - 1
    nums.append(1)
  # search for nine
  while 'N' in occs.keys() and 'I' in occs.keys() and 'E' in occs.keys() and occs['N'] > 0 and occs['I'] > 0 and occs['N'] > 0 and occs['E'] > 0:
    occs['N'] = occs['N'] - 1
    occs['I'] = occs['I'] - 1
    occs['N'] = occs['N'] - 1
    occs['E'] = occs['E'] - 1
    nums.append(9)
    
  for key in occs:
    if occs[key] > 0:
      print "ERROR"
      print word
      print occs
      print nums
      break
  
  return "".join(str(sorted(nums))).replace(' ','').replace(',','').replace('[','').replace(']','')
    
#with open('A-large.in', 'r') as f:
with open('A-small-attempt2.in', 'r') as f:
  words = parse(f.read().splitlines())
for i in range(len(words)):
  wordSorted = solve(words[i])
  print "Case #" + str(i+1) + ": " + wordSorted
