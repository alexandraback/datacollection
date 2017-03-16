from collections import deque
def count1(name, n):
	seen = []
	l = len(name)
	i = 0
	k = 0
	#p = 0
	last = 0
	consec = False
	total = 0
	for c in name:
		if c in 'aeoiu':
			consec = False
			k = 0
		else:
			consec = True
			k = k + 1
			if k>=n:
				cl = i + 2 - n - last
				last = i + 2 - n
				cr = l - i 
				ci = cl*cr
				#print i, last, cl, cr, ci
				#audit = 0
				#for x in range(0, i + 2 - n):
				#	for y in range(i, l):
				#		if not (x,y) in seen:
				#			if good(name[x:y+1], n):
				#				audit = audit + 1
				#			seen.append((x,y))
				#print 'AUDIT:', audit
				total = total + ci
				#total = total + (i + 2 - n - p) * (l - i)
				#p = p + 1
		i = i + 1
	return total

def good(str, n):
	k = 0
	for c in str:
		if c in 'aeoiu':
			k = 0
		else:
			k = k + 1
			if k == n:
				#print str, 'Y'
				return True
	#print str, 'N'
	return False

def count2(name, n):
	l = len(name)
	total = 0
	for i in range(0, l):
		for j in range(i+1, l+1):
			if good(name[i:j], n):
				total = total+1
	return total

k = int(raw_input())
for i in range(0, k):
	name, n = [x for x in raw_input().split()]
	print 'Case #%s: %s' % (i+1, count1(name, int(n)))