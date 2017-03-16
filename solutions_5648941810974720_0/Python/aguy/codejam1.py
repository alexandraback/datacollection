import sys
import itertools
import math

sys.setrecursionlimit(10000)

def f(s):
	s.upper()
	l = [0] * 10
	l[0] = s.count('Z')
	l[2] = s.count('W')
	l[4] = s.count('U')
	l[8] = s.count('G')
	l[5] = s.count('F') - l[4]
	l[7] = s.count('V') - l[5]
	l[6] = s.count('X')
	l[1] = s.count('O') - l[0] - l[2] - l[4]
	l[3] = s.count('R') - l[0] - l[4]
	l[9] = s.count('I') - l[5] - l[6] - l[8]
	ans = []
	for i in range(10):
		ans.append(chr(ord('0') + i) * l[i])
	return ''.join(ans)



n = int(input())
for i in range(n):
	x = f(input())
	print("Case #{0}: {1}".format(i+1, x))