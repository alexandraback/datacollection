for case in range(1, int(input()) + 1):
	s = input()
	cnt = {chr(i) : s.count(chr(i)) for i in range(ord('A'), ord('Z') + 1)}
	ans = [0] * 10
	words = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
	only = ['Z', 'O', 'W', 'H', 'U', 'F', 'X', 'S', 'G', '$']
	for i in range(0, 10, 2):
		ans[i] = cnt[only[i]]
		for j in words[i]: 
			cnt[j] -= ans[i]
	for i in range(1, 9, 2):
		ans[i] = cnt[only[i]]
		for j in words[i]: 
			cnt[j] -= ans[i]
	ans[9] = cnt['I']
	print("Case #%d: %s" % (case, ''.join([str(i) * ans[i] for i in range(10)])))