# coding: utf-8
import sys

def search(graph,flag,p):
	if flags[p]==True:
		return True
	flags[p] = True
	result = False
	for i in range(len(graph[p])):
		result |= search(graph,flag,graph[p][i]-1)
	return result

if __name__=='__main__':
	T = int(sys.stdin.readline())
	for tc in range(T):
		N = int(sys.stdin.readline())
		graph = []
		for n in range(N):
			temp = [int(it) for it in sys.stdin.readline().split()]
			graph.append(temp[1:])
		
#		print('[graph]')
#		for n in range(N):
#			print('{0}: {1}'.format(n+1,graph[n]))
		
		ans = False
		for n in range(N):
			flags = [False]*N
			ans |= search(graph,flags,n)
		
		if ans==True:
			print('Case #{0}: Yes'.format(tc+1))
		else:
			print('Case #{0}: No'.format(tc+1))
