#!/usr/bin/python


def lastiCorrect(p, l):
  x = 1
  for i in range(0, l):
    x = x * p[i]

  return x

def getExpectedKeys(num_typed, total_len, p):
  keystrokes = []
  give_up = total_len + 2
  keystrokes.append(give_up)

  for i in range(0, num_typed + 1):
    # Press backspace i times
    pCorrect = lastiCorrect(p, num_typed -i)
    expected =  pCorrect * (i + (total_len - num_typed + i) + 1) \
               + (1 - pCorrect) * (i + (total_len - num_typed + i) + 2 + total_len)
    keystrokes.append(expected)
 
  return min(keystrokes)
    

f = open("A-small")
num = int(f.readline())

for i in range(0, num):
  line = f.readline().rstrip()
  words = line.split(None)
  num_typed = int(words[0])
  total_len = int(words[1])

  line = f.readline()
  p = [float(x) for x in line.split(None)]

  output = 'Case #' + str(i+1) + ': '

  output += "%.6f" % getExpectedKeys(num_typed, total_len, p)
  print output

