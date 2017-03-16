data = open('a.txt', 'r').read().split('\n')

(T,) = map(int, data.pop(0).split(' '))

def solve(t):
	(A, N) = map(int, data.pop(0))
	otherMotes = map(int, data.pop(0))
	otherMotes = otherMotes.sort()
	return 0

for t in range(T):
   print 'Case #' + str(t+1) + ': ' + str(solve(t))