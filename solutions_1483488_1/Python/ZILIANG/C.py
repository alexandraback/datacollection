
table = [set() for i in range(2000000+10)]

for i in range(1, 2000000+1):
	s = str(i)
	for cut in range(1, len(s)):
		new_s = s[cut:] + s[:cut]
		new_i = int(new_s)
		table[i].add(new_i)


T = input()
for t in range(T):
	A, B = map(int, raw_input().split())
	ans = 0
	for i in range(A, B):
		s = table[i]
		for num in s:
			if num > i and num <= B:
				ans += 1		
	print 'Case #%d: %d' % (t+1, ans)
