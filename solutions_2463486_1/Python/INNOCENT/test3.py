#!/usr/bin/python3
from bisect import *
import sys

def good(s):
	s = str(int(s) ** 2)
	return s == s[::-1]

ans = set()

def dfs(s):
	if len(s) > 50:
		return
	dfs("0" + s + "0")
	for i in range(1, 10):
		t = str(i) + s + str(i)
		if good(t):
			ans.add(int(t) ** 2)
			dfs(t)
ans.add(1)
ans.add(4)
ans.add(9)
dfs("")
dfs("0")
dfs("1")
dfs("2")
dfs("3")
ans = sorted(list(ans))
args = sys.stdin.read().split()
T = int(args[0])
args = args[1:]
for ca in range(1, T + 1):
	a = int(args[0])
	b = int(args[1])
	args = args[2:]
	l = 0
	while a > ans[l] : l += 1
	print("Case #{}: {}".format(ca, len([x for x in ans if a <= x and x <= b])))
