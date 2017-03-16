import sys
N = int(sys.stdin.readline().strip())
def decide(ll):
	if len(ll) == 0:
		return 0
	lll = []
	if ll[-1] == -1:
		for number in ll[:-1]:
			lll.append(-number)
		return 1+decide(lll)
	else:
		return decide(ll[:-1])


for qw in range(1,N+1):
	s = sys.stdin.readline().strip()
	ll = []
	for char in s:
		if char == '-':
			ll.append(-1)
		else:
			ll.append(1)

	print("Case #%d: %d"%(qw,decide(ll)))