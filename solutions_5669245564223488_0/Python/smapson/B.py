from collections import defaultdict

n = int(raw_input())
factorial = [1]
N = 1000000007
for i in range(1,101):
  newelement = i*factorial[-1]
  newelement %= N
  factorial.append(newelement)

for testcase in range(n):
  m = int(raw_input())
  trains = raw_input().split()
  trash = set()
  finished = 0
  ab = []
  frontback = set()
  fronttrain = set()
  backtrain = set()
  aa = defaultdict(int)
  for train in trains:
    # ab case
    if train[0] != train[-1]:
      j = 0
      while train[j] == train[0]:
        j+=1
      k = len(train) - 1
      while train[k] == train[-1]:
        k-=1
      l = j
      while l <= k:
        if train[l] in trash:
          finished = 1
        removed = l
        trash.add(train[removed])
        while train[l] == train[removed]:
          l+=1
      ab.append([train[0], train[-1]])
      frontback.add(train[0])
      frontback.add(train[-1])
      if train[0] in fronttrain:
        finished = 1
      if train[-1] in backtrain:
        finished = 1
      fronttrain.add(train[0])
      backtrain.add(train[-1])
    # aa case
    if train[0] == train[-1]:
      if train[0] in trash:
        finished = 1
      for i in train:
        if i != train[0]:
          finished = 1
      aa[train[0]] += 1

  for letter in frontback:
    if letter in trash:
      finished = 1
  
  onetrain = []
  starter = 0
  back = [x[1] for x in ab]
  for train in ab:
    if train[0] in back:
      continue
    starter = train
  if starter == 0 and ab:
    finished = 1


  if ab:
    onetrain.append(ab[0])
    ab.remove(ab[0])
  
  if finished == 0:
   now = 0
   while ab:
    happened = 0
    for train in ab:
      if train[0] == onetrain[now][1]:
        ab.remove(train)
        onetrain[now][1] = train[1]
        happened = 1
      if train[1] == onetrain[now][0]:
        ab.remove(train)
        onetrain[now][0] = train[0]
        happened = 1
    if happened == 0:
      if ab:
        onetrain.append(ab[0])
        ab.remove(ab[0])
        now += 1
  
  for letter in aa:
    if letter not in frontback:
      onetrain.append(letter)

  if finished == 1:
    answer=0
    print "Case #%s: %s"%(testcase+1, answer)
  
  else:
    answer=factorial[len(onetrain)]
    for x in aa:
      answer *= factorial[aa[x]]
      answer %= N
    print "Case #%s: %s"%(testcase+1, answer)
