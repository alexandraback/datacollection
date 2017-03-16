def one_test():
	s = input()
	ans = s.count('+-') + s.count('-+')
	if (ans % 2 == 0) != (s[0] == '+'):
		ans += 1
	return ans

t = int(input())

for i in range(1, t + 1):
	print("Case #{}: {}".format(i, one_test()))
