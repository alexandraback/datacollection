found = {}
par = {}
queue = [1]
index = 0
found[1] = 1
 
def get_rev(x):
  return int(str(x)[::-1])

def get_ans(x):
  global found
  global queue
  global index
  global par
  while x not in found:
    cur = queue[index]
    index += 1
    for item in [cur+1, get_rev(cur)]:
      if item not in found:
        found[item] = found[cur] + 1
        par[item] = cur
        queue.append(item)
        if item == get_rev(cur) and cur > get_rev(cur):
          print cur, get_rev(cur), found[cur]
  return found[x]

def get_ans2(x):
  cur = 1
  ans = 1
  while cur != x:
    next1 = get_rev(cur)
    next2 = get_rev(cur + 1)
    if (next1 <= x and (next1 > next2 or next2 > x) and next1 > cur):
      print cur
      cur = next1
    else:
      cur = cur+1
    ans += 1
  return ans

def get_ans3(x):
  if x <= 10:
    return x
  cur = 10
  ans = 10
  while cur != x:
#    for power in range(0, len(str(cur))/2):
#      for mul in range(1, 10):
#        pos = cur + mul*pow(10, power)
#        next1 = get_rev(pos)
#        if next1 <= x and next1 > cur and next1 > pos:
#          next_cur = next1
#          add = (pos - cur) + 1
#    cur = next_cur
#    ans += add
    if len(str(cur)) == len(str(x)):
      delta = int(str(x)[0:len(str(cur))/2])
#for power in range(0, len(str(cur))/2):
#       add = int(str(x)[power])*pow(10, power)
#       delta += add
      if get_rev(cur+get_rev(delta)) > x:
        delta = int(str(x)[0:len(str(cur))/2]) - 1
      delta = get_rev(delta)
      ans += delta
      cur += delta
      if cur < get_rev(cur):
        cur = get_rev(cur)
        ans += 1
      ans += (x - cur)
      cur = x
    else:
      next_add = pow(10, len(str(cur))/2) - 1
      ans += next_add + 1
      cur = get_rev(cur + next_add)
      next_cur = pow(10, len(str(cur)))
      ans += (next_cur - cur)
      cur = next_cur
  return ans
#cur = 2000
#get_ans(cur)
#while par[cur] != 1:
#  if par[cur] != cur - 1:
#    print par[cur]
#  cur = par[cur]
#
#import sys
#for x in range(1, 1000001):
#  if get_ans(x) != get_ans3(x):
#    print x, get_ans(x), get_ans3(x)
#  else:
#    print "hit {0}".format(x)
#    pass
#print x

import fileinput
inp = []
for line in fileinput.input():
  inp.append(int(line))
for kase in range(1, inp[0]+1):
  print "Case #{0}: {1}".format(kase, get_ans3(inp[kase]))
