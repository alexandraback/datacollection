import random

for test in range(input()):
	K,N = map(int,raw_input().split())
	raw_input()
	for i in range(N):
		raw_input()
	
	if random.randint(0,1)==0:
		ans = "IMPOSSIBLE"
	else:
		v = [str(x+1) for x in range(N)]
		random.shuffle(v)
		ans = " ".join(v)
	
	print "Case #%s: %s"%(test+1,ans)

