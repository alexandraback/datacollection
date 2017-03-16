def good(n):
	if n < 20: return n
	if n%10 == 0:
		return good(n-1)+1
	tot = 0;
	s = str(n)
	l = len(s)
	halfzeroed = s[:l/2] + '0'*(l-l/2-1) + '1'
	#print('at',n)
	#print('half',halfzeroed)
	#print('to',n-int(halfzeroed))
	tot += n-int(halfzeroed)
	n = int(halfzeroed[::-1])
	tot += (halfzeroed != halfzeroed[::-1])
	nnines = len(halfzeroed)-1
	nines = int('9'*nnines)
	#print('at',n)
	#print('nines',nines)
	#print('to',n-nines)
	tot += n-nines
	#print('tot',tot)
	return tot + good(nines)

#print(good(101))
f = open('A-small-attempt1.in').readlines()
for t, n in enumerate(f[1:]):
	print('Case #%d: %d'%(t+1, good(int(n))))
