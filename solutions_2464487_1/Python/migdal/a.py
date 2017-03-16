import sys
test=int(raw_input())
i=0
while test >0:
  i=i+1
  inp=raw_input()
  lis=inp.split()
  r=int(lis[0])
  t=int(lis[1])
  lo=1
  hi=t
  ans=1
  while lo<=hi:
    mid=(hi+lo)/2
    cost=2*mid*r+mid*(2*mid-1)
    if cost<=t:
      if ans<mid:
        ans=mid
      lo=mid+1
    else:
      hi=mid-1
  out="Case #"+str(i)+": "+str(ans)
  print out
  test=test-1
  
sys.exit(0)
