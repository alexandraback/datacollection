import math
from decimal import *

getcontext().prec = 100

openfile = open("B-small-attempt2.in", 'r')
#openfile = open("n.txt", 'r')
d = openfile.read().splitlines()
n = int(d[0])

linId = 1
for tcNum in range(0,n):
  s = int(d[linId])
  linId = linId + 1
  li = []
  for i in range(2*s-1):
    li.append([int(_) for _ in d[linId].split()])
    linId = linId + 1

  ll = []
  for _ in li:
    for __ in _:
      ll.append(__)
  nn = set(ll)
  
  pos = []
  for _ in nn:
    cntr = 0
    for __ in ll:
      if(_ == __):
        cntr = cntr + 1
    if(cntr%2 == 1):
      pos.append(_)  
  
  if(0):
    c = []
    for i in range(s):
      k = [_[i] for _ in li]
      for _ in pos:
        cntr = 0
        for __ in k:
          if(__ == _):
            cntr = cntr + 1
        if(cntr%2 == 1):
          c.append(str(_))
    if(len(c) != s):
      print linId
      print tcNum
      print c
      print pos
  else:
    pos.sort()
    c = [str(_) for _ in pos]
  
  assert(len(c) == s)
  print 'Case #' + str(tcNum+1) + ": " + ' '.join(c)
      

if(0):
  linId = 1
  for tcNum in range(0,n):
    s = [ord(_) for _ in d[linId]]
    linId = linId + 1

    ss = [s[0]]
    s = s[1:]
    
    while(len(s) > 0):
      if(s[0] >= ss[0]):
        sss = [s[0]]
        for _ in ss:
          sss.append(_)
        ss = sss
      else:
        ss.append(s[0])
      s = s[1:]

    st = ''
    for _ in ss:
      st = st + chr(_)
    print 'Case #' + str(tcNum+1) + ": " + st
  
if(0):
  #https://code.google.com/codejam/contest/8234486/dashboard#s=p2&a=3
  #https://www.topcoder.com/community/data-science/data-science-tutorials/maximum-flow-section-1/
  #https://www.topcoder.com/community/data-science/data-science-tutorials/introduction-to-graphs-and-their-data-structures-section-1/
  linId = 1
  for tcNum in range(0,n):
    s = int(d[linId])
    linId = linId + 1
    en = set(d[linId].split())
    fr = set(d[linId+1].split())
    linId = linId + 2
    linId0 = linId
    en0 = en.difference(fr)
    fr0 = fr.difference(en)

    intr = en.intersection(fr)
    ww = []
    linId = linId0
    for _ in range(2, s):
      li = set(d[linId].split())
      li = li.difference(intr)
      ww.append(li)
      linId = linId + 1

    frontier = [[len(intr), '', fr, en]]
    while(1):
      frontier.sort(reverse=True)
      f = frontier.pop()
      l = len(f[1])
      if(l == len(ww)):
        break
      f2 = f[2].union(ww[l])
      f3 = f[3].union(ww[l])
      frontier.append([len(f[3].intersection(f2)), f[1] + '0', f2, f[3]])
      frontier.append([len(f[2].intersection(f3)), f[1] + '1', f[2], f3])
    print 'Case #' + str(tcNum+1) + ": " + str(f[0])


if(0):
  cc = [['<', 0, -1], ['>', 0, 1], ['^', -1, 0], ['v', 1, 0]]

  linId = 1
  for tcNum in range(0,n):
    n = d[linId].split()
    r = int(n[0])
    c = int(n[1])
    linId = linId + 1
    aa = []
    arrows = []
    er = 0
    for i in range(r):
      aa.append(d[linId])
      for _ in cc:
        ind = -1
        while(1):
          ind = d[linId].find(_[0], ind + 1)
          if(ind == -1):
            break
          arrows.append([d[linId][ind], i, ind])
      linId = linId + 1
      
    changes = 0
    for k in arrows:
      pos = [k[1], k[2]]
      for _ in cc:
        if(_[0] == k[0]):
          ch = _[1:]
      er = 0
      while(1):
        pos[0] = pos[0] + ch[0]
        pos[1] = pos[1] + ch[1]
        if((pos[0] < 0) | (pos[1] < 0) | (pos[0] > r-1) | (pos[1] > c-1)):
          er = 1
          break
        if(aa[pos[0]][pos[1]] != '.'):
          break
      if(er == 1):
        changes = changes + 1
        for xx in cc:
          pos = [k[1], k[2]]
          ch = xx[1:]
          while(1):
            pos[0] = pos[0] + ch[0]
            pos[1] = pos[1] + ch[1]
            if((pos[0] < 0) | (pos[1] < 0) | (pos[0] > r-1) | (pos[1] > c-1)):
              break
            if(aa[pos[0]][pos[1]] != '.'):
              er = 0
              break
      if(er == 1):
        break
    if(er == 1):
      print 'Case #' + str(tcNum+1) + ": " + "IMPOSSIBLE"
    else:
      print 'Case #' + str(tcNum+1) + ": " + str(changes)

if(0):
  linId = 1
  for tcNum in range(0,n):
    n = int(d[linId])
    linId = linId + 1
    m = int(d[linId])
    linId = linId + 1
    mmm = []
    for _ in range(m):
      x = d[linId].split()
      linId = linId + 1
      mm = []
      for i in range(1,len(x),2):
        mm.append([int(x[i])-1, int(x[i+1])])
      mmm.append(mm)

    sel = [0 for _ in range(n)]
    while(1):
      ff = 0
      for i in range(m):
        sat = 0
        where1 = -1
        where0 = -1
        for _ in mmm[i]:
          if(_[1] == sel[_[0]]):
            sat = 1
          if(_[1] == 1):
            where1 = _[0]
          if(_[1] == 0):
            where0 = _[0]
        if(sat == 0):
          if(where1 >= 0):
            sel[where1] = 1
            ff = 1
            break
          if(where0 >= 0):
            ff = -1
            break
      if(ff <= 0):
        break
    if(ff == -1):
      print 'Case #' + str(tcNum+1) + ": " + "IMPOSSIBLE"
    else:
      sel = [str(_) for _ in sel]
      print 'Case #' + str(tcNum+1) + ": " + ' '.join(sel)
          

if(0):
  vv = Decimal(3)+Decimal(5).sqrt()
  for tcNum in range(0,n):
    a = int(d[tcNum+1])
    ll = vv ** Decimal(a)
    prod = str(int(ll) % 1000)
    while(len(prod) != 3):
      prod = '0' + prod
    print 'Case #' + str(tcNum+1) + ": " + prod
  

if(0):
  linId = 1
  for tcNum in range(0,n):
    a = int(d[linId])
    linId = linId + 1
    m = []
    for i in range(a):
      m.append([int(_) for _ in d[linId].split()])
      linId = linId + 1

    intersects = 0
    for i1 in range(a):
      for i2 in range(i1+1, a):
        diff = [m[i1][0] - m[i2][0], m[i1][1] - m[i2][1]]
        if(not(((diff[0] > 0) & (diff[1] > 0)) | ((diff[0] < 0) & (diff[1] < 0)))):
          intersects = intersects + 1
    print 'Case #' + str(tcNum+1) + ": " + str(intersects)

if(0):
  # King
  linId = 1
  for tcNum in range(0,n):
    a =d[linId].split()
    r = int(a[0])
    c = int(a[1])
    mm = []
    for _ in range(r):
      linId = linId + 1
      mm.append([ii for ii in d[linId]])
      if('K' in d[linId]):
        curr = [_, d[linId].find('K')]
    linId = linId + 1

    changes = [[1,1], [-1,-1], [1,0], [0,1], [1,-1], [-1,1], [-1,0], [0,-1]]
    n = 0
    while(1):
      n = n + 1
      f = 0
      for _ in changes:
        currX = [_[0]+curr[0], _[1]+curr[1]]
        if((currX[0] >= 0) & (currX[1] >= 0) & (currX[0] < r) & (currX[1] < c)):
          if(mm[currX[0]][currX[1]] == '.'):
            f = 1
            mm[currX[0]][currX[1]] = 'K'
            mm[curr[0]][curr[1]] = '#'
            curr = currX
            break
      if(f == 0):
        break
    if(n%2 == 0):
      win = 'B'
    else:
      win = 'A'
    print 'Case #' + str(tcNum+1) + ": " + win
    
    

if(0):
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