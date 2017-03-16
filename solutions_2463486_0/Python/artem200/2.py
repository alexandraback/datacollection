from math import *

def pal(a):
	S = str(a)
	return (S == S[::-1])

def good(a):
	k = int(sqrt(a))
	return (k * k == a and pal(k) and pal(a))

n = int(input())
for i in range (n):
	a, b = map(int, input().split())
	ans = 0
	for j in range(a, b + 1):
		if (good(j)):
			ans += 1
	print("Case #", i + 1, ": ", ans, sep = '')