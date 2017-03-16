
def fact(n):
  ans = 1
  for i in range(1, n+1):
    ans *= i
  return ans

def toTrips(strs):
  trips = []
  for s in strs:
    if len(s) == 1:
      need = True
      for t in trips:
        if t[0] == s:
          need = False
      if need:
        trips.append( (s, fact(strs.count(s))) )
    else:
      trips.append( (s, 1) )
  return trips

def connect(trips):
  r = []
  n = len(trips)
  used = [False] * n
  for i in range(n):
    if used[i]:
      continue
    used[i] = True
    (s, cnt) = trips[i]
    j = 0
    while j < n:
      if used[j]:
        pass
      elif s[-1] == trips[j][0][0]:
        used[j] = True
        s = s + trips[j][0][1:]
        cnt *= trips[j][1]
        j = -1
      elif s[0] == trips[j][0][-1]:
        used[j] = True
        s = trips[j][0][:-1] + s
        cnt *= trips[j][1]
        j = -1
      j = j + 1
    r.append( (s, cnt) )
  return r

def checkVaild(trips):
  has = [False] * 256
  for i in trips:
    for c in i[0]:
      index = ord(c)
      if has[index]:
        return False
      has[index] = True
  return True

def doit():
  n = int( raw_input() )
  line = raw_input().strip()
  strs = []
  for s in line.split():
    r = ""
    last = ""
    for c in s:
      if c != last:
        last = c
        r = r + c
    strs.append(r)

  strs.sort(key = lambda x : len(x))

  # print strs
  trips = toTrips(strs)
  # print trips
  trips = connect(trips)
  # print "connect: " + str(trips)

  if not checkVaild(trips):
    return 0

  ans = 1
  for t in trips:
    ans *= t[1]
  return ans * fact( len(trips) )

t = int( raw_input() )
for i in range(1, t + 1):
  ans = "Case #%d: %d" % (i, doit())
  print ans
