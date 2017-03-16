from __future__ import print_function
import sys
import math

def main():
	t = int(sys.stdin.readline())
	for case in range(1, t+1):
		sys.stderr.write('processing case %d\n' % case)
		process_case(case)
	sys.stderr.write('Finished!\n')

def process_case(case):
	a, b, k = map(int, sys.stdin.readline().split())
	wins = 0
	for x in xrange(a):
		for y in xrange(b):
			if x & y < k:
				wins += 1
	sys.stdout.write('Case #%d: %d\n' % (case, wins))

# def process_case(case):
# 	a, b, k = map(int, sys.stdin.readline().split())
# 	wins = 0
# 	if k >= a or k >= b:
# 		mi = min([a,b,k])
# 		ma = max([a,b,k])
# 		wins = mi**2 + ma - mi
# 		sys.stdout.write('Case #%d: %d\n' % (case, wins))
# 		return

# 	wins += k**2
# 	shift = int(math.log(k, 2)) + 1
# 	a = a >> shift
# 	b = b >> shift


# 	mi = min(int(log(a, 2)) + 1, int(log(b, 2)) + 1)
# 	extra_wins = 2**(mi+1)

# 	ma = max(int(log(a, 2)) + 1, int(log(b, 2)) + 1)

# 	sys.stdout.write('Case #%d: %d\n' % (case, 0))

if __name__ == '__main__':
	main()
