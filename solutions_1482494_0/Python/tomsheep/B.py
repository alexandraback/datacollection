import sys

def readLine():
  return sys.stdin.readline()

def readLineAsInt():
  return int(readLine())

def readLineAsArray():
  return readLine().split()

def readLineAsIntArray():
  return [int(x) for x in readLineAsArray()]

def my_cmp(E1, E2):
  return cmp(E1[1], E2[1])

def find_min_1(ll):
  min = None
  for i in range(len(ll)):
    if min is None or min > ll[i][0]:
      min = ll[i][0]
  return min

def case(N, ll):
  ll.sort(my_cmp)
  #print ll
  got = 0
  times = 0
  min_1 = find_min_1(ll)
  for i in range(N):
    rate_2_need = ll[i][1]
    if got >= rate_2_need:
      times += 1
      got += 2
      #print "####", times, got
    else:
      if got < min_1:
        return None
      else:
        times += rate_2_need - got
        got = rate_2_need
        times += 1
        got += 2
        #print "&&&&&", times, got
  return times

#print case(2, [[0,1],[0,2]])  

T = readLineAsInt()
for i in range(T):
  N = readLineAsInt()
  ll = []
  for j in range(N):
    ll.append(readLineAsIntArray())

  ret = case(N, ll)
  if ret is None:
    print "Case #%d: Too Bad" % (i + 1)
  else:
    print "Case #%d: %d" % (i + 1, ret)
