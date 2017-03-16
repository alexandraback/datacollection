
t = int(raw_input())

def factorial(n):
  ans = 1
  for i in xrange(2, n + 1):
    ans *= i
    ans %= 1000000007
  return ans

def occurs(trains, ch):
  indexes = []
  for i in xrange(len(trains)):
    if ch in trains[i]:
      indexes.append(i)
  return indexes

def analyze_one(train):
  if len(train) <= 1:
    return True
  prev = train[0]
  reduced = prev
  found = [False for i in xrange(26)]
  found[ord(train[0]) - 97] = True
  for c in train[1:]:
    if prev == c:
      continue
    if found[ord(c) - 97]:
      return False
    else:
      found[ord(c) - 97] = True
      prev = c
      reduced = reduced + c  

  return True

def analyze(train, ch):
  if len(train) <= 1:
    return [1]

  prev = train[0]
  reduced = prev
  found = [False for i in xrange(26)]
  found[ord(train[0]) - 97] = True
  for c in train[1:]:
    if prev == c:
      continue
    if found[ord(c) - 97]:
      return [-1]
    else:
      found[ord(c) - 97] = True
      prev = c
      reduced = reduced + c

  if reduced == ch:
    return [1]

  if reduced[0] == ch:
    return [2, reduced]

  if reduced[len(reduced) - 1] == ch:
    return [3, reduced]

  return [-1]

def solve(trains):
  count = 1
  for j in xrange(26):
    c = chr(j + 97)
    indexes = occurs(trains, c)
    if len(indexes) > 1:
      header = ""
      tail = ""
      restricted = 0
      for k in xrange(len(indexes) - 1, -1, -1):
        results = analyze(trains.pop(indexes[k]), c)
        if results[0] == -1:
          return 0
        if results[0] == 1:
          continue
        if results[0] == 2:
          if tail == "":
            tail = results[1]
            restricted += 1
          else:
            return 0
        if results[0] == 3:
          if header == "":
            header = results[1]
            restricted += 1
          else:
            return 0

      count *= factorial(len(indexes) - restricted)
      count %= 1000000007
      if restricted > 0:
        trains.append(header + tail)
      else:
        trains.append(c)
  for t in trains:
    if not analyze_one(t):
      return 0

  count *= factorial(len(trains))
  count %= 1000000007

  return count

for i in xrange(t):
  n = int(raw_input())
  trains = raw_input().split(" ")
  print "Case #" + str(i + 1) + ":", solve(trains)



