import sys
sys.setrecursionlimit(10000)


for case_index in range(1, 1+input()):

  sys.stderr.write(str(case_index)+' ')
  n=input()
  state = [0]*n
  hasParent=[False]*n
  a=[]
  for i in range(n):
    l=map(int,raw_input().split())
    l.pop(0)
    for j in range(len(l)):
      l[j]-=1
      hasParent[l[j]]=True
    a.append(l)
  res="No"
  def dfs(root):
    global res
    state[root]=1
    for j in a[root]:
      if state[j]==2:
        res="Yes"
      if state[j]==0:
        dfs(j)
    state[root]=2
  
  for i in range(n):
    if not hasParent[i]:
      state = [0]*n
      dfs(i)


  print 'Case #%s: %s'%(case_index,res)

sys.stderr.write('\n')

