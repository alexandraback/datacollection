def solve(N,z,A):
	perm = permutations(N,list(range(N)),0,[])
	mini = -1
	for i in perm:
		t = test(N,z,A,i)
		#print("test: "+str(i)+"="+str(t))
		if t!=-1 and (mini == -1 or t<mini):
			mini = t
	return mini

def permutations(N,A,x,r):
	if x==N:
		r.append(A)
	for i in range(x, N):
		B = [j for j in A] 
		B[x], B[i] = A[i], B[x]
		permutations(N,B,x+1,r)
	return r
	


def test(N,z,A,O):
	path = []
	path.append(O[0])
	res = str(z[path[0]])
	for i in O[1:]:
		while not A[path[len(path)-1]][i]:
			path.pop()
			if len(path)==0:
				return -1
		path.append(i)
		res+=str(z[i])
	return int(res)

for T in range(int(input())):
	N,M = map(int, input().split())
	z = [0]*N
	for i in range(N):
		z[i] = int(input())
	A = [[False]*N for i in range(N)]
	for i in range(M):
		a,b = map(int, input().split())
		A[a-1][b-1] = True
		A[b-1][a-1] = True
	print ("Case #"+str(T+1)+": "+ str(solve(N,z,A)))