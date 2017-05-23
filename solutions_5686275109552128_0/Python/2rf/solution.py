from GCJ_helper import work

def one_test():
	n = int(input())
	a = list(map(int, input().split()))
	ret = min((x + sum((y - 1) // x for y in a) for x in range(1, max(a) + 1)))
	print(ret)

work(one_test)
