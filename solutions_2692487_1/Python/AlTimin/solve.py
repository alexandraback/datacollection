#!/usr/bin/python3

from sys import stdin

def check(a, t):
	answer = 0
	for i in t:
		while i >= a:
			answer += 1
			if a == 1:
				return 10 ** 100
			a += a - 1
		a += i
	return answer
			
def solve(tn):
	a, n = map(int, stdin.readline().split())
	t = sorted(map(int, stdin.readline().split()))
	answer = n
	for i in range(n + 1):
		answer = min(answer, check(a, t[:i]) + n - i)
	print('Case #%d: %d' % (tn, answer))

T = int(stdin.readline())
for i in range(T):
	solve(i + 1)
