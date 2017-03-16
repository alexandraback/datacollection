from functools import reduce
from itertools import cycle, islice

def to_number(digits, base):
	return reduce(lambda x, y: x * base + y, digits) + 1

def one_test():
	k, c, s = map(int, input().split())
	need = (k + c - 1) // c
	digs = cycle(range(k))
	ans = [to_number(islice(digs, c), k) for i in range(need)]
	return ' '.join(map(str, ans)) if len(ans) <= s else "IMPOSSIBLE"

t = int(input())

for i in range(1, t + 1):
	print("Case #{}: {}".format(i, one_test()))
