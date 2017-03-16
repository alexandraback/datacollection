def solve():
  #f = open("in.txt", 'r')
  f = open("C-small-attempt0.in", 'r')
  #f = open("C-large.in", 'r')
  T = int(f.readline())
  for t in range(1,T+1):
    print "Case #%d:" %t,
    N = int(f.readline())
    dd = dict([])
    for n in range(N):
      s = [int(k) for k in f.readline().split()]
      d = s[0]
      for i in range(s[1]):
        if d+i*s[5] in dd:
          dd[d+i*s[5]].append((s[2]+i*s[6], s[3]+i*s[6], s[4]+i*s[7]))
        else:
          dd[d+i*s[5]] = [(s[2]+i*s[6], s[3]+i*s[6], s[4]+i*s[7])]
    delta = 100
    wall = [0]*1001
    keys = sorted(dd.keys())
    nbA = 0
    for k in keys:
      l = dd[k]
      if len(l) == 1:
        attack = False
        (w,e,s) = l[0]
        for m in range(w,e):
          if wall[delta+m]<s:
            attack = True
            #print (k, w, e),
            break
        if attack:
          nbA +=1
        for m in range(w,e):
          if wall[delta+m]<s:
            wall[delta+m] = s
      else:
        for (w,e,s) in l:
          attack = False
          for m in range(w,e):
            if wall[delta+m]<s:
              attack = True
              #print (k, w, e),
              break
          if attack:
            nbA +=1
        for (w,e,s) in l:
          for m in range(w,e):
            if wall[delta+m]<s:
              wall[delta+m] = s
    print nbA
    

solve()
