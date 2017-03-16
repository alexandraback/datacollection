from collections import Counter

t = int(raw_input())
for c in range(1,t+1):
	n = int(raw_input())
	paper = [map(int, raw_input().split()) for _ in range(2*n-1)]
	result = []
	count = Counter(paper[i][j] for i in range(len(paper)) for j in range(len(paper[0])))
	result = sorted([k for k, v in count.iteritems() if v % 2 != 0])
	result = ' '.join(map(str, result))
	print "Case #{}: {}".format(c, result)

