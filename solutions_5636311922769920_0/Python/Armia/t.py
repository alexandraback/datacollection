openfile = open("D-small-attempt0.in", 'r')
d = openfile.read().splitlines()
n = int(d[0])

for tcNum in range(0,n):
  needed = []
  nn = d[tcNum+1].split()
  k = int(nn[0])
  c = int(nn[1])
  s = int(nn[2])
  
  m = [_ for _ in range(k)]
  while(1):
    mm = 0
    for _ in range(c):
      mm = mm + m.pop() * (k**_)
      if(len(m) == 0):
        break
    needed.append(mm+1)
    if(len(m) == 0):
      break
  needed.sort()
  needed = [str(_) for _ in needed]
  if(len(needed) > s):
    needed = ['IMPOSSIBLE']
  print 'Case #' + str(tcNum+1) + ": " + ' '.join(needed)

if(0):
  nBits = 32
  numCoins = 500

  primes = [3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
  dic = []
  for b in range(2,11):
    dic.append([])
    for p in primes:
      dic[b-2].append([int((b**_)%p) for _ in range(nBits)])
    
  curr = [False for _ in range(nBits)]
  curr[0] = True
  curr[-1] = True

  print 'Case #1:'

  cntr = 0
  while(1):
    fp = []
    for b in range(2,11):
      f = 0
      for c in range(len(primes)):
        rem = 0
        for _ in range(nBits):
          if(curr[_] == True):
            rem = rem + dic[b-2][c][_]
        rem = rem % primes[c]
        if(rem == 0):
          f = 1
          fp.append(str(primes[c]))
          break
      if(f == 0):
        break
    if(f == 1):
      mc = ''
      for _ in range(nBits):
        if(curr[-1-_]==True):
          mc = mc + '1'
        elif(curr[-1-_]==False):
          mc = mc + '0'
      print mc + ' ' + ' '.join(fp)
      cntr = cntr + 1
      if(cntr == numCoins):
        break
    f = 0
    for _ in range(1,nBits-1):
      curr[_] = not(curr[_])
      if(curr[_] == True):
        f = 1
        break
    assert(f == 1)


if(0):
  for tcNum in range(0,n):
    c = d[tcNum+1]
    a = []
    for _ in c:
      if(_ == '+'):
        a.append(True)
      else:
        a.append(False)

    steps = 0
    while(1):
      f = 1
      for _ in a:
        if(_ == False):
          f = 0
          break
      if(f == 1):
        break

      steps = steps + 1
      a[0] = not(a[0])
      for _ in range(1,len(a)):
        if(a[_] != a[0]):
          a[_] = not(a[_])
        else:
          break
    print 'Case #' + str(tcNum+1) + ": " + str(steps)

if(0):
  for tcNum in range(0,n):
    c = int(d[tcNum+1])
    x = c
    cntr = 1
    st = [0 for _ in range(10)]
    if(c != 0):
      while(1):
        x = c * cntr
        for _ in str(x):
          st[int(_)] = 1
        f = 1
        for _ in range(10):
          if(st[_] == 0):
            f = 0
            break
        if(f == 1):
          break
        cntr = cntr + 1
    if(x == 0):
      print 'Case #' + str(tcNum+1) + ": INSOMNIA"
    else:
      print 'Case #' + str(tcNum+1) + ": " + str(x)

if(0):
  for _ in range(0,n):
    c = int(d[_*3+1])
    itms = [int(__) for __ in d[_*3+3].split(' ')]
    for a in range(0, len(itms)):
      for b in range(a+1, len(itms)):
        if(itms[a] + itms[b] == c):
          print 'Case #' + str(_+1) + ": " + str(a+1) + " " + str(b+1)
          break
if(0):
  st = [ord('a'), ord('d'), ord('g'), ord('j'), ord('m'), ord('p'), ord('t'), ord('w')]
  for tcNum in range(0,n):
    msg = d[tcNum+1].lower()
    dcd = ''
    for _ in msg:
      ch = _
      repeat = 1
      if(_ == ' '):
        ch = '0'
        repeat = 1
      else:
        a = -1
        for __ in range(len(st)):
          if(ord(_) >= st[__]):
            a = a + 1
          else:
            break
        ch = str(a+2)
        repeat = ord(_) - st[a] + 1
      if(len(dcd) > 0):
        if(dcd[-1] == ch):
          dcd =dcd + ' '
      for i in range(repeat):
        dcd = dcd + ch
    print 'Case #' + str(tcNum+1) + ": " + dcd