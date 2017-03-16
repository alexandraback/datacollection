
row = ['1', 'i', 'j', 'k']
match = {
         '1':dict(zip(row, [(1,'1'), (1,'i'), (1,'j'), (1,'k')])),
         'i':dict(zip(row, [(1,'i'), (-1,'1'), (1,'k'), (-1, 'j')])),
         'j':dict(zip(row, [(1,'j'), (-1,'k'), (-1,'1'), (1,'i')])),
         'k':dict(zip(row, [(1,'k'), (1,'j'), (-1,'i'), (-1,'1')]))
        }

def mult(a, b):
   neg = a[0] * b[0]
   res = match[a[1]][b[1]]
   return neg*res[0], res[1]

def calcResult(s):
   res = (1, '1')
   for x in s:
      res = mult(res, (1, x))
   return res

def solve():
   bounds = tuple(int(v) for v in raw_input().split())
   startString = raw_input()
   startString *= bounds[1]
   print len(startString)
   
   validPrefixes = set()
   runningPrefix = (1, '1')
   for i in range(len(startString)):
      runningPrefix = mult(runningPrefix, (1, startString[i]))
      if runningPrefix == (1, 'i'):
         validPrefixes.add(i+1)

   validSuffixes = set()
   runningSuffix = (1, '1')
   for i in range(len(startString)-1, 0, -1):
      runningSuffix = mult((1, startString[i]), runningSuffix)
      if runningSuffix == (1, 'k'):
         validSuffixes.add(i)

   for i in range(len(startString)):
      if i in validPrefixes:
         runningPrefix = (1, '1')
         for j in range(i, len(startString)):
            runningPrefix = mult(runningPrefix, (1, startString[j]))
            if j+1 in validSuffixes:
               if (1, 'j') == runningPrefix:
                  return True
   return False

numCases = int(raw_input())
for curCase in range(1, numCases+1):
   print 'Case #'+str(curCase)+': '+('YES' if solve() else 'NO')
