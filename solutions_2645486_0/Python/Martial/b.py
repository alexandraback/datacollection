import sys

for case_index in range(1, 1+input()):

  sys.stderr.write(str(case_index)+' ')
  e,r,n=map(int,raw_input().split())
  v=map(int,raw_input().split())
  r = min(r,e)
  m=0
  while True:
    x = e+(n-1)*r - m*r -(n-1-m)*e
    if r<=x<=e:
      break
    m += 1
  v.sort()
  res = r*sum(v[:m])+x*v[m]+e*sum(v[m+1:])
  print 'Case #%s: %s'%(case_index,res)

sys.stderr.write('\n')

