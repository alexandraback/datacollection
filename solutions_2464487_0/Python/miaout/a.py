import re

def calc(i, r):
  i = i-1
  return (i+1)*(i)*2 + (2*r+1)*(i+1)

def process_case() :
  r, t = map(int, raw_input().split())

  lower = 0
  upper = 10**18 + 99
  # upper = 10

  while lower<upper:
    mid = (lower+1+upper)/2
    req = calc(mid, r)
    # print [lower, upper, mid, req, t]

    if req<=t:
      lower = mid
    else:
      upper = mid - 1

  # print [lower, upper]
  assert(lower==upper)

  return lower

if __name__ == "__main__" :
  case_num = int(raw_input())
  for i in range(case_num) :
    result = process_case()
    print "Case #%d: %s" % (i+1, result)
