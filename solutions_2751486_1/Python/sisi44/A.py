
def isVo(a):
  return a == "a" or a == "e" or a  =="i" or a =="o" or a=="u"

def solve():
  #f = open("in.txt", 'r')
  #f = open("A-small-attempt1.in", 'r')
  f = open("A-large.in", 'r')
  T = int(f.readline())
  for t in range(1, T+1):
    print "Case #%d:" %t,
    [s, n] = f.readline().split()
    n = int(n)
    debut = -1
    for i in range(len(s)):
      if not isVo(s[i]):
        debut = i
        break
    if debut == -1:
      print 0
      continue
    l = []
    k = debut
    while k < len(s)-1:
      k += 1
      if isVo(s[k]):
        K = k - debut 
        if K >= n:
          l.append((debut, k-1))
        while k < len(s)-1:
          k += 1
          if not isVo(s[k]):
            debut = k
            break
    if not isVo(s[-1]) and len(s)-debut>=n:
      l.append((debut, len(s)-1))
    res = 0
    #gap = 0
    for i in range(len(l)):
      delta = l[i][1]-l[i][0]+1-n
      if i == 0:
        a = l[i][0]-0
      else:
        a = l[i][0]-l[i-1][1]-1+n-1
      if i == len(l) -1:
        b = len(s) - l[i][1]-1
      else:
        b = l[i+1][0]-l[i][1]-1+n-1
      res += (a+1)*(b+1)
      res += (a+1)*delta
      res += (b+1)*delta
      #print a, b, delta
      if delta>= 2:
        res += (delta-1)*(delta-1+1)/2
    for gap in range(1, len(l)):
      for i in range(len(l)-gap):
        deltaL = l[i][1]-l[i][0]+1-n
        deltaR = l[i+gap][1]-l[i+gap][0]+1-n
        if i == 0:
          a = l[i][0]-0
        else:
          a = l[i][0]-l[i-1][1]-1+n-1
        if i+gap == len(l) -1:
          b = len(s) - l[i+gap][1]-1
        else:
          b = l[i+gap+1][0]-l[i+gap][1]-1+n-1
        res += (a+deltaL+1)*(b+deltaR+1)
    print res

solve()    
