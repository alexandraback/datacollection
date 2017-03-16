import sys
import itertools

test = (1, 2, 3, 5, 4)
first = (1, 100, 3, 5, 7)
second = (1, 8000, 12, 8, 12)
T, R, N, M, K = first

#all_begins = itertools.product(range(2, M+1), N)

def sol2(products):
	pass

def sol1(products):
	highest3 = 0
	highest5 = 0
	num3s = 0
	num5s = 0
	num2s = 0
	has2 = False

	for p in products:
		while p % (3 ** (highest3+1)) == 0:
			highest3 += 1
		while p % (5 ** (highest5+1)) == 0:
			highest5 += 1
		if p % 2 == 0 and p % 4 != 0:
			has2 = True
		while p % 2 == 0 and p != 0:
			p = p / 2
			num2s += 1

	#print highest3, highest5, num2s
	out = ""
	for i in range(highest3):
		out += "3"
	for i in range(highest5):
		out += "5"
	if has2:
		out += "2"
	remaining = N - highest3 - highest5 - (1 if has2 else 0)
	if remaining != 0:
		num4s = min(remaining, int(2.0 * num2s / (3 * (remaining + (1 if has2 else 0)))))
		for i in range(num4s):
			out += "4"
		for i in range(remaining - num4s):
			out += "2"
	return out



sys.stdin.readline()
sys.stdin.readline()
print "Case #1:"

for i in range(R):
	products = [int(x) for x in sys.stdin.readline().split()]
	
	print sol1(products)