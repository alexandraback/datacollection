import sys

def gen_order(ours, theirs):
  ret = []
  i = 0
  j = 0

  while (i < len(ours)) and (j < len(theirs)):
    if ours[i] < theirs[j]:
      i += 1
      ret.append('0')
    else:
      j += 1
      ret.append('1')

  while i < len(ours):
    ret.append('0')
    i += 1

  while j < len(theirs):
    ret.append('1')
    j += 1

  return ''.join(ret)

def war(order):
  score = 0
  theirs = 0
  for b in reversed(order):
    if b == '0':
      if theirs == 0:
        score += 1
      else:
        theirs -= 1
    else:
      theirs += 1
  return score

def better(order):
  score = 0
  theirs = 0
  for b in order:
    if b == '1':
      theirs += 1
    elif theirs > 0:
      theirs -= 1
      score += 1
  return score

T = int(sys.stdin.readline())

for i in range(1, T+1):
    N = int(sys.stdin.readline())
    ours = sorted(sys.stdin.readline()[:-1].split(' '))
    theirs = sorted(sys.stdin.readline()[:-1].split(' '))
    order = gen_order(ours, theirs)
    print "Case #{}: {} {}".format(i, better(order), war(order))
