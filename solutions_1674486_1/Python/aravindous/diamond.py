import sys



def dfs(graph, start, path=[]):
  q=[start]
  while q:
    v=q.pop(0)
    if v not in path:
      path=path+[v]
      q=graph[v]+q
    else:
      return True
  return False


def compute():
  n = int(raw_input())
  for test in range(0,n):
    nodes = int(raw_input())
    graph = {}
    for i in range(0,nodes):
      temp = (raw_input()).split(' ')
      count = int(temp[0])
      graph[i+1] = []
      for j in range(0,count):
        graph[i+1].append(int(temp[j+1]))
      #print 'temp is ',temp
    #print 'the graph is ',graph
    ans = False
    for no in range(1,nodes+1):
      if(dfs(graph,no)):
        ans = ans or True
        if ans:
          break
    if ans:
      print "Case #%d: Yes"%(test+1)
    else:
      print "Case #%d: No"%(test+1)


compute()
      





  

