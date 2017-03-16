def one_test():
	n, k = map(int, input().split())
	assert n % 2 == 0
	assert k <= 1 << (n // 2 - 2)
	ret = ['']
	for i in range(k):
		half = ('1{:0' + str(n // 2 - 2) + 'b}1').format(i)
		cur = ' '.join([half + half] + [str(int(half, base)) for base in range(2, 11)])
		ret.append(cur)
	return '\n'.join(ret)

t = int(input())

for i in range(1, t + 1):
	print("Case #{}: {}".format(i, one_test()))
