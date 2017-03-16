
def s(r, nrings):
  return ((r+2*nrings)*(r+2*nrings-1) - r*(r-1))//2

def bsearch(r, t, mn, mx):
  #print('bsearch',mn,mx)
  if mn+1 == mx:
    return mn
  half = (mn+mx)//2
  res = s(r, half)
  if res > t:
    return bsearch(r, t, mn, half)
  else: # res <= t
    return bsearch(r, t, half, mx)


T = int(input())
for x in range(1,T+1):
  ln = input().split()
  r = int(ln[0])
  t = int(ln[1])
  
  mx = 1
  while s(r, mx) <= t:
    mx *= 2
  
  print('Case #' + str(x) + ': ' + str(bsearch(r,t,mx//2,mx)))
