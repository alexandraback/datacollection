import sys
from collections import Counter


def calc():
	N = input()
	c = Counter()
	for i in range(2*N-1):
		v = [int(x) for x in raw_input().split()]
		c.update(v)
	ele = []
	for ch, cnt in c.most_common():
		if cnt % 2 == 1:
			ele.append(ch)
	return ' '.join(map(str, sorted(ele)))


def main():
	T = input()
	for t in range(T):
		ans = calc()
		print 'Case #%d: %s'%(t+1, ans)


if __name__ == '__main__':
	main()
