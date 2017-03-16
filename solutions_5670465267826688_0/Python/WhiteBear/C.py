import math

qmultDict = {
  ('1','1'): '1',
  ('1','i'): 'i',
  ('1','j'): 'j',
  ('1','k'): 'k',
  ('1','-1'): '-1',
  ('1','-i'): '-i',
  ('1','-j'): '-j',
  ('1','-k'): '-k',
  ('i','1'): 'i',
  ('i','i'): '-1',
  ('i','j'): 'k',
  ('i','k'): '-j',
  ('i','-1'): '-i',
  ('i','-i'): '1',
  ('i','-j'): '-k',
  ('i','-k'): 'j',
  ('j','1'): 'j',
  ('j','i'): '-k',
  ('j','j'): '-1',
  ('j','k'): 'i',
  ('j','-1'): '-j',
  ('j','-i'): 'k',
  ('j','-j'): '1',
  ('j','-k'): '-i',
  ('k','1'): 'k',
  ('k','i'): 'j',
  ('k','j'): '-i',
  ('k','k'): '-1',
  ('k','-1'): '-k',
  ('k','-i'): '-j',
  ('k','-j'): 'i',
  ('k','-k'): '1',
  ('-1','1'): '-1',
  ('-1','i'): '-i',
  ('-1','j'): '-j',
  ('-1','k'): '-k',
  ('-1','-1'): '1',
  ('-1','-i'): 'i',
  ('-1','-j'): 'j',
  ('-1','-k'): 'k',
  ('-i','1'): '-i',
  ('-i','i'): '1',
  ('-i','j'): '-k',
  ('-i','k'): 'j',
  ('-i','-1'): 'i',
  ('-i','-i'): '-1',
  ('-i','-j'): 'k',
  ('-i','-k'): '-j',
  ('-j','1'): '-j',
  ('-j','i'): 'k',
  ('-j','j'): '1',
  ('-j','k'): '-i',
  ('-j','-1'): 'j',
  ('-j','-i'): '-k',
  ('-j','-j'): '-1',
  ('-j','-k'): 'i',
  ('-k','1'): '-k',
  ('-k','i'): '-j',
  ('-k','j'): 'i',
  ('-k','k'): '1',
  ('-k','-1'): 'k',
  ('-k','-i'): 'j',
  ('-k','-j'): '-i',
  ('-k','-k'): '-1',
}

def qmult(a, b):
  return qmultDict[(a,b)]






#f = open('smallC.txt', 'r')
f = open('C-small-attempt3.in', 'r')
T = int(f.readline())

for testCase in range(1, T+1):
  (L, X) = map(int, f.readline().split())
  s = f.readline().strip()


  nMax = min(X,4) * L
  #print nMax
  s = s * nMax

  fromLeft = '1'
  leftIdx = -1
  for i in range(nMax):
    fromLeft = qmult(fromLeft, s[i])
    if (fromLeft == 'i'):
      leftIdx = i
      break

  if leftIdx == -1:
      print "Case #%d: NO" % testCase
      continue

  LProd = range(4)
  LProd[0] = '1'
  LProd[1] = '1'
  for i in range(L):
    LProd[1] = qmult(LProd[1], s[i])
  for i in range(2,4):
    LProd[i] = qmult(LProd[i-1], LProd[1])

  #print LProd
  totalProd = LProd[X % 4]
  if totalProd != '-1':
      print "Case #%d: NO" % testCase
      continue

  fromRight = '1'
  rightIdx = -1
  count = 0
  for i in range(nMax-1, -1, -1):
    count += 1
    fromRight = qmult(s[i], fromRight)
    if ((fromRight == 'k') and (leftIdx + count <= X*L)):
      print "Case #%d: YES" % testCase
      rightIdx = i
      break

      #print "Case #%d: YES, leftIdx = %s, rightIdx = %s, totalProd = %s" % (testCase, leftIdx, rightIdx, totalProd)
  if rightIdx == -1:
      print "Case #%d: NO" % testCase
      continue


  

      
  
  