import sys
import collections

DIGITS = [ ('ZERO', 'Z', 0), ('SIX', 'X', 6), ('TWO', 'W', 2), ('FOUR', 'U', 4), ('THREE', 'R', 3), ('SEVEN', 'S', 7), ('FIVE', 'F', 5), ('EIGHT', 'G', 8), ('NINE', 'I', 9), ('ONE', 'O', 1) ]

def solve(i):
	l = sys.stdin.readline().strip()
	d = collections.defaultdict(int)
	ans = ''
	for c in l:
		d[c] += 1
	for lets, let, num in DIGITS:
		c = d[let]
		ans += c * str(num)
		for l in lets:
			assert d[l] >= c
			d[l] -= c
	print ''.join(sorted(ans))


		

if __name__ == '__main__':
	c = int(sys.stdin.readline())
	for i in range(c):
		sys.stdout.write('Case #%d: ' % (i+1,))
		solve(i)
