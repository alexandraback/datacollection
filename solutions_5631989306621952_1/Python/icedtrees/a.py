import sys
sys.setrecursionlimit(2000)
def solution(s):
	if len(s) <= 1:
		return s
	largest = max(s)
	i = s[::-1].index(largest)
	i = len(s) - i - 1
	return s[i] + solution(s[:i]) + s[i+1:]

t = int(raw_input())
for c in range(1,t+1):
	ss = raw_input()
	result = solution(ss)
	print "Case #{}: {}".format(c, result)

