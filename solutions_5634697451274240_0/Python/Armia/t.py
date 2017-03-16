openfile = open("B-small-attempt0.in", 'r')
d = openfile.read().splitlines()
n = int(d[0])
ind = 0

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