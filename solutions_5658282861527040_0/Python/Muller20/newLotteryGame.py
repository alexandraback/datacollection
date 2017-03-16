'''
	codejam 2014
	new lottery game
'''

def solve(a, b, k):
	count = 0
	for i in range(a):
		for j in range(b):
			if i&j < k:
				count += 1
	return count
	
if __name__=='__main__':
	test = int(input())
	for t in range(test):
		a, b, k = [int(x) for x in input().split()]		
		sol = solve( a, b, k )
		print("Case #" + str(t+1) + ": " + str(sol) )
