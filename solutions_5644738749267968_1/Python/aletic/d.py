n = int(raw_input())

def play_opt(o_block, mblocks):
  for b in mblocks: #assume sorted
    if b > o_block:
      i = mblocks.index(b)
      return mblocks.pop(i)
  return mblocks.pop(0)

for test in xrange(1,n+1):
  blocks = int(raw_input())
  naomi = sorted(map(float, raw_input().split()))
  ken = sorted(map(float, raw_input().split()))
  a1 = a2 = 0
  
  k= ken[:]
  for i in xrange(blocks):
    x = naomi[i]
    y = play_opt(x, k)
    if x > y:
      a2 += 1
      
  best = 0
  for offset in xrange(1, blocks+ 1):
    count = sum(naomi[(offset + i) % blocks] > ken[i] for i in xrange(blocks))
    best = max(best, count)
  a1 = best
  
  #print naomi
  #print ken
  #for a,b in zip(naomi,ken):
  #  if a > b:
  #    a1+=1
  print 'Case #{}: {} {}'.format(test, a1, a2)