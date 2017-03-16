
def vowel(c):
    return c in ["a","e","i","o","u"]

ntest = int(raw_input())
for itc in range(ntest):
  print 'Case #%d:' % (itc+1),
  name, n = raw_input().split()
  n = int(n)
  
  count = 0
  min_indexes = []
  last_consec = -1
  for i, c in enumerate(name):
    if vowel(c):
        last_consec = -1
    else:
        if last_consec<0:
            last_consec = i
        if i-last_consec+1 >= n:
           min_indexes.append(i-n+1)
  #print min_indexes
  
  res = 0
  cur_index = -1
  cur_min = -1
  for i in range(len(name)):
    if i > cur_min:
      cur_index+=1
      if cur_index>len(min_indexes)-1:
          break
      cur_min = min_indexes[cur_index]
    res += len(name)-cur_min-n+1

  print res
      

