from gmpy import is_prime

p = [2]
def make_list():
	for i in xrange(3, 100000, 2):
		if is_prime(i):
			p.append(i)

def exam(s, base):
	n = int(s, base)
	return is_prime(n) == 0

def get_div(s, base):
	n = int(s, base)
	for pp in p:
		if n % pp == 0:
			return pp
	return 0
	

make_list()
t = input()
for cs in xrange(1, t+1):
	n, j = map(int, raw_input().split())
	print 'Case #%d:' % cs
	go = 0
	i = 0
	for go in xrange(2**(n-2), 2**(n-1)):
		s = bin(go)[2:] + '1'
		ans = [s]
		for bs in xrange(2, 11):
			if exam(s, bs):
				ans.append(str(get_div(s, bs)))
		if '0' in ans or len(ans) != 10:
			continue
		print ' '.join(ans)
		i += 1
		if i == j:
			break
	
			
			
			
	
