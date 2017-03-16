# coding: cp932
import sys
import math

def C(n, k):
	if n == 0: return 1
	if k == 0: return 1
	if k == n: return 1

	val = 1
	for i in range(k):
		val *= (n-i)
	for i in range(1, k+1):
		val /= i
	return val

f   = file(sys.argv[1])
out = file(sys.argv[1][:-3] + '.out', 'w')

caseCnt = int(f.readline())



for case in range(1, caseCnt+1):
	N = int(f.readline())
	tr = []
	
	W = []
	
	for i in range(N):
		d, n, w, e, s, dd, dp, ds = map(int, f.readline().split())
		tr += [(d, n, w, e, s, dd, dp, ds)]
	tr.sort(lambda l,r:cmp(l[0], r[0]))
	
	attack = 0
	#D = 0
	while 1:
		d = tr[0][0]
		
		if len(tr) > 1:
			for i in range(len(tr)):
				if tr[i][0] > d: break
			
			rm = tr[:i]
			tr = tr[i:]
		else:
			rm = [tr[0]]
			tr = []
		
		for i, t in enumerate(rm):
			t = list(t)
			try:
				
				for w in W:
					if w[0] > t[2]: raise StopIteration()
					if w[1] >= t[2] and w[2] >= t[4]:
						t[2] = w[1]
						if t[2] >= t[3]: break
				else:
					raise StopIteration()
						
			except StopIteration:
				attack += 1
				#print 'suc', d, i, t
				pass
			else:
				pass
				#print 'suc', i, t
				#attack += 1
				
		for i, t in enumerate(rm):
			
			W += [(t[2], t[3], t[4])]
			W.sort(lambda l,r: cmp(l[0], r[0]))
				
				
		#print D
		#for t in rm:
		#	print '\t', t
		
		for t in rm:
			if t[1] <= 1: continue
			t = list(t)
			t[0] += t[5]
			t[1] -= 1
			t[2] += t[6]
			t[3] += t[6]
			t[4] += t[7]
			
			t = tuple(t)
			for j in range(len(tr)):
				if tr[j][0]>t[0]:
					tr = tr[:j] + [t] + tr[j:]
					break
			else:
				tr += [t]
		if not tr: break
	#print 'a', attack
	print>>out, 'Case #%d:'%case, attack