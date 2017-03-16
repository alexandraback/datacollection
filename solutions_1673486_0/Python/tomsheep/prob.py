import sys

def readLine():
  return sys.stdin.readline()

def readLineAsInt():
  return int(readLine())

def readLineAsArray():
  return readLine().split()

def readLineAsIntArray():
  return [int(x) for x in readLineAsArray()]

def readLineAsFloatArray():
  return [float(x) for x in readLineAsArray()]

def s1(cur, total, props, back):
  p_corrent = 1
  for i in range(cur - back):
    p_corrent *= props[i]

  correct = total - cur + 1 + back * 2

  return p_corrent * correct + (1 - p_corrent) * (2 * total - cur + 2 + back * 2)

# enter
def s2(cur, total, props):
  if cur == total:
    p_corrent = 1
    for i in range(cur):
      p_corrent *= props[i]
    return p_corrent * 1 + (1 - p_corrent) * (total + 2)
  else:
    return total + 2

def case(A, B, ll):
  m = None
  for i in range(A + 1):
    tmp = s1(A, B, ll, i)
    #print m, tmp
    if m is None or m > tmp:
      m = tmp

  tmp = s2(A, B, ll)
  #print m, tmp
  if m is None or m > tmp:
    m = tmp

  return m

#print case(2, 5, [0.6, 0.6])
#print case(1, 20, [1])
#print case(3, 4, [1, 0.9, 0.1])

T = readLineAsInt()
for i in range(T):
  A, B = readLineAsIntArray()
  ll = readLineAsFloatArray()
  ret = case(A, B, ll)
  print "Case #%d: %.6f" % (i + 1, ret)




