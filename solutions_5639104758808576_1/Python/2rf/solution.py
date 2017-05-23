from GCJ_helper import work

def one_test():
	tmp, s = input().split()
	ret = 0
	have = 0
	for i, c in enumerate(s):
		d = ord(c) - ord('0')
		if have < i:
			ret += i - have
			have = i
		have += d
	print(ret)

work(one_test)
