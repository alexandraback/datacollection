def readint():
	return int(input())
	
def readints():
	return [int(i) for i in input().split()]

def main():
	T = readint()
	
	for t in range(1, T + 1):
		K, C, S = readints()
		if S < K:
			s = "IMPOSSIBLE"
		else:
			s = ' '.join(str(k * K**(C-1) + 1) for k in range(K))
		print("Case #%d: %s" % (t, s))
		
main()
