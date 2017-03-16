import sys
def triangle(n):
	return n*(n-1)/2

def paint_needed(rings, radius):
	return rings*2*radius + triangle(rings*2)

def binary_search(start, end, radius, paint):
	best_so_far = 0
	while start <= end:
		mid = (start+end)/2
		if paint_needed(mid, radius) <= paint:
			best_so_far = mid
			start = mid+1
		else:
			end = mid-1
	return best_so_far

data = open(sys.argv[1]).readlines()
tests = int(data[0])
data.pop(0)
for i in xrange(tests):
	radius, paint = map(int, data[i].split())
	print "Case #" + str(i+1) + ": " + str(binary_search(0, paint, radius, paint))
