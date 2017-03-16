from collections import deque

d = {(0,0):('','')}

q = deque([(0,0,1,('',''))])
while q and len(d) < 201*201:
  x,y,v,prev=q.popleft()
  a = [0,0,0,0]
  a[0] = (x+v, y, 'E')
  a[1] = (x-v, y, 'W')
  a[2] = (x, y-v, 'S')
  a[3] = (x, y+v, 'N')

  for (xx,yy,dist) in a:
    past = (prev, dist)
    cond = (xx, yy) not in d
    if (-100 <= xx <= 100) and (-100 <= yy <= 100) and cond:
      d[(xx,yy)] = past
      q.append((xx,yy,v+1, past))

def make(val):
  first, char = val
  while char:
    yield char
    if first == '': break
    first, char = first

dd = {}
for key in d:
  val = d[key]
  s = ''.join(list(make(val))[::-1])
  dd[key] = s




def do(x, y):
  return dd[(x,y)]


cases = int(raw_input())

for case in xrange(1, cases+1):
  x,y = map(int, raw_input().split(' '))
  res = do(x, y)
  print 'Case #%d: %s' %(case, res)