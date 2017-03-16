import sys
V = [
		[0,0,0],
		[0,0,-1],
		[0,-1,-1],
		[0,-1,-2],
		[0,-2,-2]
		]
def Work():
	L = raw_input().split()
	n = int(L[0])
	s = int(L[1])
	p = int(L[2])
	score = L[3:]
	cnt = 0
	for i in xrange(n):
		tot = int(score[i])
		bSuc = 0
		if tot >= 3 * p :
			bSuc = 1
		elif (tot == 3*p-1 or tot == 3*p-2) and p-1>=0:
			bSuc = 1
		elif (tot == 3 * p - 3 or tot == 3 * p - 4) and p-2>=0:
			bSuc = 2
		else:
			pass
		if bSuc == 1:
			cnt = cnt + 1
		elif bSuc == 2 and s > 0:
			cnt = cnt + 1
			s = s - 1
		else: pass
	return cnt

n = int(raw_input())
for i in xrange(n):
	print 'Case #%d: %d' % ((i+1), Work())
