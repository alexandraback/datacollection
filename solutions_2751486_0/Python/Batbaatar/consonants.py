def calc(txt, n):
	ans = 0
	for i in range(len(txt) - n + 1):
		for j in range(i + n, len(txt) + 1):
			s = txt[i:j]
			for g in range(n - 1, len(s)):
				c = 0
				for h in range(n):
					if(not (s[g - h] in ['a', 'e', 'i', 'o', 'u'])):
						c += 1
				if(c >= n):
					ans += 1
					break
	return ans

def solve(txt, n):
	return calc(txt, n)

T = input()

for i in range(T):
	line = raw_input().split()
	print "Case #" + str(i + 1) + ": " + str(solve(line[0], int(line[1])))
