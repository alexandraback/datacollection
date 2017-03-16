vowels = ['a', 'e', 'i', 'o', 'u']
NNN = int(raw_input())
for nnn in xrange(1, NNN+1):
  print "Case #%d:" % (nnn),
  I = [x for x in raw_input().split()]
  name = I[0]
  n = int(I[1])
  numsub = [0] * len(name)

  last_matched, last_checked = -1, -1
  for i in xrange(n-1, len(name)):
    if i > 0: numsub[i] = numsub[i-1]
    if last_matched <= i-n:
      flag = False
      for j in xrange(i, last_checked, -1):
        if name[j] in vowels:
          flag = True
          last_matched = j
          break
      if not flag:
        numsub[i] += i-n+2
        if i > 0: numsub[i] -= numsub[i-1]
      last_checked = i

  print sum(numsub[n-1:])

