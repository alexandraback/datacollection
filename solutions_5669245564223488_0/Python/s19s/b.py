import itertools,sys, multiprocessing
def check(s):
  # print s
  now = s[0]
  D = set(now)
  for i in s:
    if i == now:
      continue
    else:
      if i in D:
        return False
      else:
        D.add(i)
        now = i
  return True

def cut(s):
  now = s[0]
  D = set(now)
  tmp = [now]
  for i in s:
    if i == now:
      continue
    else:
      tmp.append(i)
      now = i
  return ''.join(tmp)

def jj(cars):
  ans = 0
  for i in itertools.permutations(cars):
    if check("".join(i)):
      ans += 1
  return ans

pool = multiprocessing.Pool(3)
T = raw_input()
jobs = []
for t in range(int(T)):
  print >> sys.stderr, t
  N = int(raw_input())
  cars = map(cut, raw_input().split())
  
  jobs.append( pool.apply_async(jj, args = (cars,)) )

for t, ans in enumerate(jobs):
  print 'Case #%d: %d' % (t+1, ans.get())
