T = int(raw_input())

for t in range(T):
	K,C,S = map(int,raw_input().split())
	print "Case #" + str(t+1) + ":",
	div = K**(C-1)
	ret = 1
	while ret <= K**C:
		if ret + div <= K**C: print ret,
		else: print ret
		ret += div
