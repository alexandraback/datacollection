found = {}
queue = [1]
index = 0
found[1] = 1

def get_rev(x):
  return int(str(x)[::-1])

def get_ans(x):
  global found
  global queue
  global index
  while x not in found:
    cur = queue[index]
    index += 1
    for item in [cur+1, get_rev(cur)]:
      if item not in found:
        found[item] = found[cur] + 1
        queue.append(item)
        if item == get_rev(cur) and cur > get_rev(cur):
          print cur, get_rev(cur), found[cur]
  return found[x]

def get_ans2(x):
  cur = 1
  ans = 1
  while cur != x:
    found = False
    for power in range(0, 16): 
      next1 = get_rev(cur)
      next2 = get_rev(cur + pow(10, power))
      if (next1 <= x and (next1 > next2 or next2 > x) and next1 > cur):
        cur = next2
        found = True
        break
      print cur
    if found:
      cur = get_rev(cur)
    else:
      cur = cur+1
    ans += 1
  return ans

import fileinput
inp = []
for line in fileinput.input():
  inp.append(int(line))
for kase in range(1, inp[0]+1):
  print "Case #{0}: {1}".format(kase, get_ans(inp[kase]))
#if x > 1 and get_ans(x) != get_ans(x-1) + 1:
#    pass
#print x, get_ans(x)
