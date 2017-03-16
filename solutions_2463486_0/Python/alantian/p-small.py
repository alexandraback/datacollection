
def palin(v):
	s=str(v)
	return s == s[::-1]

def go(a,b):
	ans = 0
	v = 1
	while v*v <= b:
		if v*v>=a and palin(v) and palin(v*v):
			ans += 1
		v += 1
	return ans

def main():
	T = int(raw_input())
	for case in range(1,T+1):
		a,b = map(int,raw_input().split())
		ans = go(a,b)
		print 'Case #%d: %d'%(case,ans)

if __name__ == '__main__':
	main()