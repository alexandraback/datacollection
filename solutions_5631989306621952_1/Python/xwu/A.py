import sys


def calc():
	s = raw_input()
	ans = s[0]
	for c in s[1:]:
		i = 0
		while i < len(ans) and c == ans[i]:
			i += 1
		if i >= len(ans):
			ans += c
		elif c > ans[i]:
			ans = c + ans
		else:
			ans = ans + c
	return ans


def main():
	T = input()
	for t in range(T):
		ans = calc()
		print 'Case #%d: %s'%(t+1, ans)


if __name__ == '__main__':
	main()
