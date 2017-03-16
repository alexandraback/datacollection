import math

numcases = int(raw_input())
for i in range(1, numcases+1):
  a, n = [int(z) for z in raw_input().split()]
  motes = sorted([int(z) for z in raw_input().split()])
  #print a, n, motes
  min_ops = len(motes)
  ops = len(motes)
  
  if a>1:
    for j, m in enumerate(motes):
      #print 'A', j, min_ops, a, m, ops
      if m<a:
        ops-=1
        a+=m
      else:
        pot = math.ceil(math.log(float(m-1)/(a-1), 2))
        if 2**pot == float(m-1)/(a-1):
          pot+=1
        
        a_new = 2**pot*(a-1)+1
        #print a, m, pot, a_new
        a=a_new +m
        ops += int(pot)
        ops-=1
      min_ops=min(min_ops, ops)
      #print j, min_ops, a, ops
  
  
  print 'Case #'+str(i)+': '+str(min_ops)