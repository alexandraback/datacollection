MAX_RESULT = 1000000000
MAX_FARMS = 100000

def CheckTime(farmCost, farmGain, reqCookies, buildFarms):
  result = 0
  for i in xrange(0, buildFarms):
    result += farmCost / (2.0 + (farmGain * i))
  result += (reqCookies / (2.0 + (farmGain * buildFarms)))
  return result

def Solve():
  (farmCost, farmGain, reqCookies) = map(float, raw_input().split(' '))
  bestResult = MAX_RESULT
  (fromSearch, toSearch) = (0, MAX_FARMS)
  while toSearch-fromSearch >= 3:
    left = (2*fromSearch + toSearch) / 3
    right = (fromSearch + 2*toSearch) / 3
    
    leftRes = CheckTime(farmCost, farmGain, reqCookies, left)
    rightRes = CheckTime(farmCost, farmGain, reqCookies, right)
    
    if leftRes < rightRes: toSearch = right
    else: fromSearch = left

  results = [CheckTime(farmCost, farmGain, reqCookies, x) for x in [fromSearch, fromSearch+1, fromSearch+2]]
  print min(results)

if __name__ == '__main__':
  q = int(raw_input())
  for i in xrange(1, q+1):
    print "Case #%d:" % (i),
    Solve()
