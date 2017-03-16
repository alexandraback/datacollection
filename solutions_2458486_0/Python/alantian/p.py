
from collections import defaultdict

def rl():
	return map(int,raw_input().split())

T = []
K = []
n = 0
O = []

f = [] # id to take

def go():
	global T,K,n,O
	global f

	#print 'T',T
	#print 'K',K
	#print 'n',n
	#print 'O',O

	maxs = 1<<n
	f = [-1] * maxs
	# f[s] , in 's' 0 => not exist   1 => exist (to take)
	# -1 for no way to choose
	f[0] = 0
	for s in range(1,maxs):
#		num = [0] * 50 # key id range
		num = defaultdict(int)
		for v in O: num[v] += 1
		for i in range(n):
			if (1<<i)&s == 0:
				for v in K[i]: num[v] += 1
				num[ T[i] ] -= 1
		f[s] = -1
		#print s,'num',num

		if min(num.values()) < 0: # bad state
			continue

		for i in range(n):
			if ((1<<i)&s) != 0:
				ns = s ^ (1<<i)
				#print i,num[T[i]],f[ns]
				if num[T[i]] > 0 and f[ns] != -1:
					f[s] = i
					break

	#print 'f:'
	#for i in range(maxs): print 'f[%d]=%d'%(i,f[i])

	if f[maxs-1] == -1:
		return []

	s = maxs-1
	l = []
	while s != 0:
		c = f[s]
		l = l + [c+1] # output start from 1
		s = s^(1<<c)
	return l


def main():
	global T,K,n,O

	C = int(raw_input())
	for case in range(1,C+1):
		_,n = rl()
		O = rl()
		T = []
		K = []
		for i in range(n):
			l = rl()
			T.append(l[0])
			K.append(l[2:])

		ans = go()
		print 'Case #%d:'%case,
		print ' '.join( map(str,ans) ) if ans !=[] else 'IMPOSSIBLE'


if __name__ == '__main__':
	main()