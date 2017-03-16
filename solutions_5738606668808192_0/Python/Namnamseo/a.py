N=16
J=50

def binstr(x, N):
	return ''.join([str((x//(2**k))%2) for k in range(N)][::-1])

print("Case #1:")
for i in range(J):
	tmp = (2**(N//2-1))+1+i*2
	ts = binstr(tmp, N//2)
	print(ts + ts + ' ' + ' '.join([str(int(ts, i)) for i in range(2,11)]))