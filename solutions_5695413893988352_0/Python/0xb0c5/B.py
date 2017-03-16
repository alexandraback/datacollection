def fill((c,j)):
	diff = 0
	c = list(c)
	j = list(j)
	result = []
	for i in range(len(c)):
		if c[i] == '?' and j[i] == '?':
			c[i] = '0'
			j[i] = '0'
		
		if c[i] == '?':
			c[i] = j[i] if j[i] != '?' else '0'
		
		if j[i] == '?':
			j[i] = c[i] if c[i] != '?' else '0'
		
		if j[i] != c[i]:
			c = ''.join(c)
			j = ''.join(j)
			if int(c[i]) > int(j[i]):
				return (c.replace('?','0'), j.replace('?','9'))
			else:
				return (c.replace('?','9'), j.replace('?','0'))
		
	return (''.join(c),''.join(j))
			
def badness((c,j)):
	c = int(c)
	j = int(j)
	diff = abs(c-j)
	return (diff, c, j)
			
def solve(c,j):
	to_try = [(c,j)]
	
	for i in range(len(c)):
		c_prefix = c[:i]
		c_suffix = c[i+1:]
		j_prefix = j[:i]
		j_suffix = j[i+1:]
	
		if c[i] == '?' and j[i] == '?':
			to_try.append((c_prefix + '1' + c_suffix, j_prefix + '0' + j_suffix))
			to_try.append((c_prefix + '0' + c_suffix, j_prefix + '1' + j_suffix))
		elif c[i] == '?':
			if int(j[i]) > 0:
				to_try.append((c_prefix + str(int(j[i])-1) + c_suffix, j))
			if int(j[i]) < 9:
				to_try.append((c_prefix + str(int(j[i])+1) + c_suffix, j))
		elif j[i] == '?':
			if int(c[i]) > 0:
				to_try.append((c, j_prefix + str(int(c[i])-1) + j_suffix))
			if int(c[i]) < 9:
				to_try.append((c, j_prefix + str(int(c[i])+1) + j_suffix))
	# print to_try
	results = map(fill, to_try)
	c,j = min(results, key=badness)
	return c + ' ' + j
				
def all_possibilities(s):
	if '?' in s:
		idx = s.index('?')
		for digit in range(10):
			for p in all_possibilities(s[idx+1:]):
				yield s[:idx] + str(digit) + p
	else:
		yield s
				
def naive(c,j):
	to_try = []
	for p in all_possibilities(c + ',' + j):
		to_try.append(p.split(','))
	
	c,j = min(to_try, key=badness)
	return c + ' ' + j
				
n_cases = input()
for i in range(1,n_cases+1):
	c,j = raw_input().split(' ')
	print 'Case #%d:' % i,
	#n = naive(c,j)
	s = solve(c,j)
	print s