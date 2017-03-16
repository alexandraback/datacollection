import sys

def solve(r, c, m):
    if m < 0 or m >= r*c:
	return []
    s = ['.'] * (r * c)
    for j in range(m):
	s[j] = '*'
    s[-1] = 'c'
    if r == 1:
	return s
    if m == r*c - 1:
	return s
    if r == 2:
	if m % 2 == 1 or m > r*c - 4:
	    return []
	s = ['.'] * (r * c)
	for j in range(m/2):
	    s[j] = '*'
	    s[j+c] = '*'
	s[-1] = 'c'
	return s
    if r*c - m in [2, 3, 5, 7]:
	return []
    if m % c == c-1:
	s[m-1] = '.'
	s[m+1] = '*'
    # last 3 rows
    t = c * (r-3)
    if m > t:
	n = m - t
	n1 = n / 3
	n2 = n - 3*n1
	for j in range(c):
	    for k in range(r-3, r):
		s[k*c + j] = '*' if j < n1 else '.'
	for j in range(n2):
	    s[(r-3)*c + n1 + j] = '*'
    s[-1] = 'c'
    return s

def pr(x, r, c, transp):
    if len(x) != r*c:
	print "Impossible"
    elif transp == 0:
	for i in range(r):
	    s = ''
	    for j in range(c):
		s += x[i*c + j]
	    print s
    else: # transpose
	for j in range(c):
	    s = ''
	    for i in range(r):
		s += x[i*c + j]
	    print s

data = sys.stdin.readlines()
n = int(data[0])
for i in range(n):
    r, c, m = map(int, data[i+1].split())
    print "Case #%d:" % (i+1)
    if r <= c:
	pr(solve(r, c, m), r, c, 0)
    else:
	pr(solve(c, r, m), c, r, 1)
    
