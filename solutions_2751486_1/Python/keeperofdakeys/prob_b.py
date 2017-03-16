#!/usr/bin/env python2

vowels = {'a', 'e', 'i', 'o', 'u'}

def last_const(string, y, num_conseq_n_right):
  for x in xrange(y, -1, -1):
    if num_conseq_n_right[x] == 1:
      return x + 1
  return 0

count = int(raw_input())

for x in xrange(1,count+1):
  items = raw_input().split(" ")
  string = items[0]
  num_n = int(items[1])

  num_poss = 0

  num_conseq_n_right = [0]*len(string)
  if string[-1] not in vowels:
    num_conseq_n_right[-1] = 1
  else:
    num_conseq_n_right[-1] = 0
  for y in xrange(len(string)-2, -1, -1):
    if string[y] not in vowels:
      num_conseq_n_right[y] = num_conseq_n_right[y+1] + 1
    else:
      num_conseq_n_right[y] = 0

  last_consid = -1
  for y in xrange(0, len(num_conseq_n_right)):
    if num_conseq_n_right[y] >= num_n:
      if last_consid == -1:
        l = y + 1
      else:
        l = y - last_consid 
      r =  (len(num_conseq_n_right) - (y + num_n) + 1)
      num_poss += l * r
      last_consid = y

  print "Case #" + str(x) + ": " + str(num_poss)
