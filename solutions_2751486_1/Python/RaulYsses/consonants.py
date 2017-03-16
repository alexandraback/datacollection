V= ('a','e','i','o','u')

def solve_problem(name,n):
	L= len(name)
	i= 0
	j= 0
	k= n-2
	n_value= 0
	while i<L:
		if name[i] not in V:
			j+= 1
			if j==n:
				n_value+= (i-1-k)*(L-1-i)+L-k-1
				k= i
				j= n-1
		else:
			j= 0
		i+= 1
	return str(n_value)

file= open('consonants.in')
input= file.read().split('\n')
file.close()

T= int(input[0])
for i in range(1,T+1):
	j= -1
	while input[i][j]!=' ':
		j-= 1
	n= int(input[i][j+1:])
	name= input[i][:j]
	print 'Case #' + str(i)	+ ': ' + solve_problem(name,n)