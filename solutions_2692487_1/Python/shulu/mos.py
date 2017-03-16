

count = -1
def cos (s, lst, c):
	global count
	if lst == [] :
		count = c
		return c
	if (count != -1 and c > count):
		return 100000000000
	if lst[0] < s:
		return cos(s+lst[0], lst[1:], c)
	return min(c + len(lst), 1000000000000 if s == 1 else cos(s  + s-1, lst, c+1))

T = int(raw_input())
for i in range(T):
	count = -1
	s = int(raw_input().split()[0])
	lst =sorted( map(int, raw_input().split()))
	print 'Case #%s: %s' % (i+1, cos (s, lst, 0))
