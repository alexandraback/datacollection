
def solution(r,c,w):
	if r!=1:
		return solution(1,c,w) + (r-1) * (c/w)
	elif c > 2*w:
		tmp = c / w - 1
		return solution(1,c - tmp * w, w) + tmp
	elif c > w:
		return w + 1
	else:
		return w

t=input()
for i in xrange(t):
	[r,c,w]=[int(x) for x in raw_input().split(' ')]
	print 'Case #{}: {}'.format(i+1, solution(r,c,w))