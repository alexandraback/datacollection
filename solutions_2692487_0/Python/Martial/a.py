import sys
sys.setrecursionlimit(10000)

for case_index in range(1, 1+input()):

  sys.stderr.write(str(case_index)+' ')
  A,N=map(int,raw_input().split())
  s=map(int,raw_input().split())
  s.sort()
  if A==1:
    res = N
  else:
    while s and s[0]<A:
      A+=s[0]
      s.pop(0)
      N -= 1
    res = N
    for k in range(1,N+1):
      A += A-1
      while s and s[0]<A:
        A += s[0]
        s.pop(0)
      r = k+len(s)
      if r < res:
        res = r
      
  print 'Case #%s: %s'%(case_index,res)

sys.stderr.write('\n')

