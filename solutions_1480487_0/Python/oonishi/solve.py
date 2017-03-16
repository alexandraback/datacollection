# coding: shift-jis



def solve(s):
	N = len(s)
	S = sum(s)
	A = float(S)*2/N
	
	T = [1]*N
	for i in range(len(s)):
		if s[i] > A:
			T[i] = 0
			
	N = sum(T)
	S2 = sum(map(lambda x,y: x*y, s, T))
	
	def func(i):
		if T[i] == 0:
			return 0.0
		x = s[i]
		x = ((S+S2)/N-x)/S*100
		return x
	#ret = map(lambda x: (S*2/N-x)/S*100, s)
	ret = map(func, range(len(s)))
	#for i in range(len(ret)):
	#	if ret[i]<0:
	#		return [100.0]*i + [0.0] + [100.0]*(N-i-1)
	return ret

if __name__=='__main__':
	import sys
	f = file(sys.argv[1])
	caseCnt = int(f.readline())
	for case in range(1, caseCnt+1):
		a = f.readline().split()
		N = int(a[0])
		s = map(float, a[1:])
		
		answer = solve(s)
		res = '%0.6f'%answer[0]
		for r in answer[1:]:
			res += ' %0.6f'%r
		print "Case #%d:"%case, res
	