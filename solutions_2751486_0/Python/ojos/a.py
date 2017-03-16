vowels = ['a', 'e', 'i', 'o', 'u']
NNN = int(raw_input())
for nnn in xrange(1, NNN+1):
  print "Case #%d:" % (nnn),
  I = [x for x in raw_input().split()]
  name = I[0]
  n = int(I[1])
  numsub = [0] * len(name)

  for i in xrange(n-1, len(name)):
    if i > 0: numsub[i] = numsub[i-1]
    flag = False
    for j in xrange(i-n+1, i+1):
      if name[j] in vowels:
        flag = True
        break
    if not flag:
      numsub[i] += i-n+2
      if i > 0: numsub[i] -= numsub[i-1]

  print sum(numsub[n-1:])

