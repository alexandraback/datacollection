import sys

f = open(sys.argv[1], 'r')
T = int(f.readline())

def main(inherits):
	for inherit in inherits:
		if len(inherit) > 1:
			i = 0
			parents = [c for c in inherit]
			while i<len(parents):
				visit = parents[i:]
				for c in visit:
					parents.extend(inherits[c-1])
					i += 1
					if len(parents) != len(set(parents)):
						return 'Yes'
	return 'No'
	
for case_no in xrange(1, T + 1):
	N = int(f.readline())
	inherits = []
	for i in xrange(N):
		inherits.append(map(int, f.readline()[:-1].split(' '))[1:])
			
	ans = main(inherits)
	print("Case #%d: %s" % (case_no, ans))
