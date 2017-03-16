# 9:49
T = int(raw_input())

def solve(pk):
  count = 0
  back = len(pk)-1
  while 1:
    i=0
    while i<len(pk) and pk[i]==0:
      i+=1
    if i==len(pk):
      return count
    if i!=0:
      for j in range(i):
        pk[j]=1
      count += 1
    while back >=0 and pk[back]==0:
      back-=1
    pk_ = pk[:back+1]
    pk_.reverse()
    pk_ = map(lambda ii: 1-ii, pk_)
    pk[:back+1] = pk_
    count += 1
    # print count, i, back, pk

for i in xrange(1, T+1):
  # pk = raw_input()
  pk = map(lambda c: 0 if c=='+' else 1, raw_input())
  print "Case #{}: {}".format(i, solve(pk))
