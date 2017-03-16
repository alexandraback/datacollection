def getrings(r,n):
  if r%2 == 0:
    hv = r/2
    def getar(hval): return 2 * hval ** 2 - hval
    n += getar(hv)
    minv = 1
    maxv = 2
    while getar(maxv) < n:
      maxv *= 2
      minv *= 2
    while maxv - minv > 1:
      cenv = (maxv + minv)/2
      if getar(cenv) <= n: minv = cenv
      else: maxv = cenv
    if getar(maxv) <= n: 
      #print maxv, hv, n
      return maxv - hv
    #print minv, hv, n
    return minv - hv
  if r%2 == 1:
    hv = r/2
    def getar(hval): 
      #print hval, 2 * hval ** 2 + hval
      return 2 * hval ** 2 + hval
    n += getar(hv)
    minv = 1
    maxv = 2
    while getar(maxv) < n:
      maxv *= 2
      minv *= 2
    while maxv - minv > 1:
      cenv = (maxv + minv)/2
      if getar(cenv) <= n: minv = cenv
      else: maxv = cenv
    if getar(maxv) <= n:
      #print maxv, hv, n
      return maxv - hv
    #print minv, hv, n
    return minv - hv

tc = int(raw_input())
for i in range(tc):
  v1,v2 = [int(x) for x in raw_input().split(' ')]
  print "Case #%d: %d" % (i+1,getrings(v1,v2))
