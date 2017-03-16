def iterative_dfs(graph, start, path=[]):
  '''iterative depth first search from start'''
  q=[start]
  while q:
      v=q.pop(0)
      if v in path:
          return True
          
      else:
          path=path+[v]
          q=graph[v]+q
          
    
  return False

fil=open('A-small-attempt0.in','r')
a=fil.readline()
i =1
p = open("rever1.in","w")
while i<=int(a):
    y = fil.readline()
    j = 1
    dic = {}
    while j<=int(y):
        z = fil.readline()
        ac = z.split()
        dic[str(j)] = ac[1:]
        j = j+1
    for ele in dic:
        c = iterative_dfs(dic, ele, path=[])
        if c:
            break

    if c:
        p.write("Case #"+str(i)+": Yes"+"\n")
    else:
        p.write("Case #"+str(i)+": No"+"\n")
    i = i+1

p.close()
fil.close()
            
        
    
