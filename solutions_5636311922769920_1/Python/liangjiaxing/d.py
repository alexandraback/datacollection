import itertools
re = int(raw_input())

for cas in range(re):
	print "Case #%d:" % (cas + 1),
	K, C, S = map(int, raw_input().split())
	if S * C < K:
		print "IMPOSSIBLE"
		continue
	i = 0
	while i < K:
		ans = 0
		for _ in range(C):
			ans = ans * K + i
			i += 1
			if i == K:
				break
		print ans + 1,
	print