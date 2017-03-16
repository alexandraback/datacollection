import sys

def banana(foo, target):
  res = 0
  for i in range(len(foo) - len(target) + 1):
    if target == foo[i:i + len(target)]:
      res += 1
  return res

f = open(sys.argv[1], 'r')

T = int(f.readline())
for t in range(1, T + 1):
  print('Case #{0}:'.format(t), end = ' ')
  testcase = f.readline().split()
  K, L, S = int(testcase[0]), int(testcase[1]), int(testcase[2])
  keys = f.readline()
  if keys[len(keys) - 1] == '\n':
    keys = keys[:len(keys) - 1]
  keySet = {x for x in keys}
  target = f.readline()
  if target[len(target) - 1] == '\n':
    target = target[:len(target) - 1]
  targetSet = {x for x in target}
  
  if not targetSet.issubset(keySet):
    print('0.0')
  else:
    maxb = 0
    sumb = 0
    index = []
    for i in range(S):
      index.append(0)

    while True:
      teststr = ""
      for i in range(S):
        teststr = teststr + keys[index[i]]
      ba = banana(teststr, target)
      if ba > maxb:
        maxb = ba
      sumb += ba

      fin = True
      for i in range(S):
        if index[i] + 1 <= K - 1:
          index[i] += 1
          for j in range(i):
            index[j] = 0
          fin = False
          break
      if fin:
        break
    ave = sumb / (K ** S)
    print(maxb - ave)
