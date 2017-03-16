INPUT = {
	'data': ('int', 'linearray')
}

UPPER_BOUND = 2 ** 20

from math import log, ceil

pot = [2 ** i for i in xrange(0, 20)]

def main(data):
	data = data[1:]
	print data
	sums = []
	store = {}
	
	for s in xrange(1, UPPER_BOUND):			
		sum = 0
		subset = [];
		bound = 20
		ans = ""
		for i in xrange(0, bound):
			if pot[i] & s:
				sum += data[i]
				subset.append(data[i])
		
		if sum not in sums:
			store[sum] = subset
			sums.append(sum)
		else:
			ans = '\n' + ' '.join(map(str, subset))
			ans += '\n' + ' '.join(map(str, store[sum]))
			return ans
			
	return "Impossible"