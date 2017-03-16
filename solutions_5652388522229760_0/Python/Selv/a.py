t = int(raw_input())


def test():
	n = int(raw_input())
	if n == 0:
		print 'INSOMNIA'
		return
	S = set()
	cur = 0
	while len(S) != 10:
		cur += n
		for i in list(str(cur)):
			S.add(i)
	
	print cur


for i in range(1,t+1):
	print 'Case #%d:'%i,
	test()
