
casos = int(raw_input())

def conta(a, k):
	return (((2*a+1) + (2*a+1+(k-1)*4)) * k)/2

for caso in range(0, casos):
	r, t = map(int, raw_input().split())
	
	ini, fim = 0, 10000000000000000
	
	resp = -1
	while ini <= fim:
		mid = (ini+fim)/2
		if conta(r, mid) > t:
			fim = mid - 1
		else:
			ini = mid + 1
			resp = mid
	print 'Case #%d: %d' % (caso+1, resp)
		
	
	
