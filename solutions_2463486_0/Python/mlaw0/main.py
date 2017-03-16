from sets import Set
import sys

ans = Set()
LEN = 5

def is_pal (num):
  s = str(num)
  for i in range(len(s)):
    if s[i] != s[-(i+1)]:
      return False
  return True

def search (s):
  if len(s) > LEN:
    return
  search("0" + s + "0")
  for i in range(1,10):
    tmp = int(str(i) + s + str(i))
    if is_pal(tmp) and is_pal(tmp*tmp):
      ans.add(tmp*tmp)
      search(str(tmp))

search("")
for i in range(0,10): search(str(i))
sans = [0,1,4,9]
for i in ans: sans.append(i)
sans.sort()

def get_count (a,b):
  l,r = 0,0
  for i in range(len(sans)):
    if a <= sans[i]:
      l = i
      break
  for i in range(len(sans)):
    if b <= sans[i]:
      r = i
      if b == sans[i]: r += 1
      break
  return r-l

data = sys.stdin.read().split()
for i in range(len(data)): data[i] = int(data[i])
T = data[0]
for i in range(1,T+1):
  A,B = data[2*i-1],data[2*i]
  print("Case #" + str(i) + ": " + str(get_count(A,B)))
