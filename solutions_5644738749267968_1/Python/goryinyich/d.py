import sys

def play(nao, ken):
	used = [False] * len(nao)
	ans = 0
	for k in ken:
		i = 0
		while i < len(nao) and (used[i] or nao[i] < k):
			i += 1
		if i == len(nao):
			return ans
		used[i] = True
		ans += 1
	return ans

tc = int(sys.stdin.readline())
for t in range(tc):
	n = int(sys.stdin.readline())
	naomi = [float(s) for s in sys.stdin.readline().split()]
	ken = [float(s) for s in sys.stdin.readline().split()]
	naomi = sorted(naomi)
	ken = sorted(ken)
	print 'Case #%d: %d %d' % (t+1, play(naomi, ken), n-play(ken, naomi) )
