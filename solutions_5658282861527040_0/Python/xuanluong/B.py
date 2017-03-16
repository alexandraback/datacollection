
def solve():
	T = int(raw_input())
	for te in range(T):
		s = raw_input().split()
		A = int(s[0])
		B = int(s[1])
		K = int(s[2])
		#A = B = K = 1000
		i = 0
		co = 0
		while i < A:
			j = 0
			while j < B:
				C = i & j
				if C < K:
					co += 1
					#print i,j, C
				j += 1
			i += 1
		print "Case #%d: %d" % (te+1,co)


if __name__ == "__main__":
	solve()
