def solve(r,t):
	
	def tot(n):
		return n*(2*r+1)+4*(n*(n-1))/2

	low = 1
	high = t
	while high>low:
		mid = (low+high)/2
		s = tot(mid)
		if s > t:
			high = mid
		elif s < t:
			low = mid+1
		else:
			return mid

	return low-1


fin = open('input.txt')
fout = open('output.txt','w')

get = lambda: map(int,fin.readline().split())

cases, = get()
for case in range(1,cases+1):
	fout.write('Case #%d: %d\n' % (case,solve(*get())))