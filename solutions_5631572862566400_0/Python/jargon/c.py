import sys

fav = []
rfav = []

def f(left, first=None, start=None, lst=None):
	# try each in left as starting
	lo = left.copy()
	best = 0
	mod = 0
	ff = first
	scad = [s for s in start if s in lo] if start is not None else lo
	for s in scad:
		print >> sys.stderr, ' start {}'.format(s+1)
		if first is None:
			ff = s

		left = lo.copy()
		left.remove(s)
		cur = s
		last = l2 = lst
		while True:
			# try adding fave
			if fav[cur] in left:
				l2 = last
				last = cur
				cur = fav[cur]
				left.remove(cur)
				print >> sys.stderr,  '  got {}'.format(cur+1)
				continue
			# see if fave is already there
			if last == fav[cur]:
				print >> sys.stderr,  '  already there, trying next'
				mod = f(left, ff, rfav[cur], cur)
				print >> sys.stderr,  ' done, best was {}'.format(mod)
				break
			# otherwise we're done
			if fav[cur] != last and fav[cur] != ff:
				print >> sys.stderr,  "  can't use! l {} c {} ff {} f[l] {}".format(last+1,cur+1,ff+1,fav[cur]+1)
				mod = -99999999
			print >> sys.stderr,  ' done chain'
			break

		val = mod + len(lo) - len(left)
		best = max(val, best)
	return best


for t in xrange(1, int(raw_input()) + 1):
	n = int(raw_input())
	fav = map(lambda x: int(x) - 1, raw_input().split())
	rfav = [[] for i in xrange(n)]
	for i in xrange(n):
		rfav[fav[i]].append(i)
	print >> sys.stderr,  'f', fav, 'rf', rfav
	print "Case #{}: {}".format(t, f(set(xrange(n))))
