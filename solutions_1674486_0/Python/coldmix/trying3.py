
def iterative_dfs(graph, start, path=[]):
  '''iterative depth first search from start'''
  q=[start]
  while q:
    v=q.pop(0)
    path=path+[v]
    q=graph[v]+q
  return path



file = open("inputnew.txt")
t = file.readline()
out = open("outputnew.txt","w")
for i in range(0,int(t)):
	graph = {}
	l = file.readline().split()
	n=int(l[0])
	for node in range(1,n+1):
		value  = [int(ele) for ele in file.readline().split()[1:]]
		graph[node] = value
	print graph
	for ele in graph:
		ans = iterative_dfs(graph, ele)
		if len(ans) > len(set(ans)):
			k =  "Yes"
		else:
			k =  "No"
		if k=="Yes":
			break
	out.write("Case #"+str(i+1)+": "+k)
	out.write("\n")
out.close()
file.close()


