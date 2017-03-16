#!/usr/bin/env python
import random

def gen_num(s, p):
	res = 0
	for i in s:
		res = res*p + i
	return res


def calc_div(num):
	bound = 1000000
	for i in range(2, min(num, bound)):
		if num % i == 0:
			return i
	return -1

def verify(s=[], divs=[]):
	nums = [gen_num(s, i) for i in range(2, 11)] 
	for num in nums:
		div = calc_div(num)
		if (div == -1):
			return False
		divs.append(div)
	return True

def gen_ans(l):
	while True:
		s = [0 for i in range(l)]
		s[0] = 1
		s[-1] = 1
		for i in range(1, l-1):
			s[i] = random.randint(0, 1)
		divs = []
		if (verify(s=s, divs=divs)):
			ss = ''.join([str(i) for i in s])
			ans = [ss]
			ans.extend(divs)
			return tuple(ans)
				

def solve(n, f):
	cnt = 0
	s = set()
	res = []
	while cnt < f:
		ans = gen_ans(n)
		num = ans[0]
		if num not in s:
			s.add(num)
			cnt += 1
			res.append(ans)

	for i in res:
		print ' '.join([str(_) for _ in i]) 


if __name__ == "__main__":
	cas = input()
	for i in range(1, cas+1):
			print "Case #%d:" % i
			n, f = map(int, raw_input().split())
			solve(n, f)
