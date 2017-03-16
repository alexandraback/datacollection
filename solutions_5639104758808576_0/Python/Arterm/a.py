t = int(input())
for i in range(1, t + 1):
	s = input().split(' ')[1]
	ans = 0
	t = 0
	for j in range(len(s)):
		c = int(s[j])
		if t < j and c != 0:
			ans += (j - t)
			t = j
		t += c
	print("Case #" + str(i) + ": " + str(ans))
