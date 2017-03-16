import sys

INF=10**40

for case_index in range(1, 1+input()):

  sys.stderr.write(str(case_index)+' ')
  r,t = map(int,raw_input().split())
  left, right = 1, INF
  while right-left>1:
    n = (right+left)//2
    if n*(2*r+1)+2*n*(n-1)<=t:
      left = n
    else:
      right = n
  res = left
  print 'Case #%s: %s'%(case_index,res)

sys.stderr.write('\n')

