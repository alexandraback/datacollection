import sys, math

debug = False

def solve(cur, vals):
	total = len(vals)
	best = total
	changes = 0
	remaining = total
	for val in vals:
		if cur > val:
			if debug:
				print '     %d + %d = %d with %d %d' % (cur, val, cur + val, changes, remaining)
			cur += val
			nbest = changes + remaining - 1
			if best > nbest:
				best = nbest
		elif val < (cur * 2 -1):
			changes += 1
			prev = cur
			cur += cur - 1
			cur += val
			if debug:
				print '-    %d + %d + %d = %d with %d %d' % (prev, prev-1, val, cur, changes, remaining)
		else:
			if debug:
				print math.log((float(val) - 1) / (cur - 1)) / math.log(2)
			nchanges = int(math.ceil(math.log((float(val) - 1) / (cur - 1)) / math.log(2)))
			prev = cur
			cur = cur * (2 ** nchanges) - (2**nchanges) + 1
			if cur == val:
				cur += cur - 1
				nchanges += 1
			if nchanges >= remaining:
				if debug:
					print "=    Cheaper to delete from %d (%d v %d)" % (val, nchanges, remaining)
				changes += remaining
				break
			changes += nchanges
			if debug:
				print '=    %d * %d - %d + %d = %d with %d %d' % (prev, 2**nchanges, 2**nchanges - 1, val, cur + val, changes, remaining)
			cur += val
			nbest = changes + remaining - 1
			if best > nbest:
				best = nbest
		remaining -= 1
	if best < changes:
		changes = best
	return changes

cases = int(sys.stdin.readline())

for case in xrange(1, cases + 1):
	cur = int(sys.stdin.readline().split()[0])
	vals = [int(val) for val in sys.stdin.readline().split()]
	vals.sort()
	changes = 0
	if cur == 1:
		changes = len(vals)
	else:
		debug = False
		changes = solve(cur, vals)
###		debug = True
###		if changes > 0:
###			print cur, len(vals), vals
###			changes = solve(cur, vals)
	print "Case #%d: %d" % (case, changes)
	if debug:
		print
