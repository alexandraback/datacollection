v = 'aeiou'
c = 'bcdfghjklmnpqrstvwxyz'

def find(s, n):
	result = []
	start = -1
	for i in range(len(s)):
		if start == -1 and  s[i] in c:
			start = i
		elif start != -1 and s[i] not in c:
			if  i-start >= n:
				result +=[[start,i]]
			start = -1
	
	if start != -1 and len(s) - start >= n:
		result += [[start,len(s)]]
	return result

def count(lst, length, n):
	result = 0
	start = 0
	for pair in lst:
		interval = pair[1]-pair[0] - n + 1
		pre = (pair[0] - start) * interval
		suf = (length - pair[1]) * interval
		both = (pair[0] - start) * (length - pair[1])
		result += pre + suf + both
		for i in range(1,interval+1):
			result +=i
		start = pair[1] - n + 1
	return result

def solve(s, n):
	return count(find(s,n), len(s), n)

for i in range(int(raw_input())):
	s , ns = raw_input().split()
	n = int(ns)
	print 'Case #%d: %d' %(i+1, solve(s,n))
