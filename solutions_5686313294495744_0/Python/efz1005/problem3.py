from itertools import combinations

def diff(first, second):
    #second = set(second)
    return [item for item in first if item not in second]

def check_solution(firsts, seconds, actual, fake):
	f_a = [f[0] for f in actual]
	s_a = [s[1] for s in actual]
	for f in fake:
		if firsts.count(f[0]) == 1 or seconds.count(f[1]) == 1:
			return False
		elif f[0] not in f_a or f[1] not in s_a:
			return False
	return True

T = input()

for qw in xrange(1, T + 1):
	print "Case #%d:" % qw,

	N = input()

	titles = []
	firsts = []
	seconds = []

	for i in xrange(N):
		t = raw_input().split(" ")
		titles.append(t)
		firsts.append(t[0])
		seconds.append(t[1])

	if len(set(firsts)) == len(firsts) or len(set(seconds)) == len(seconds):
		print "0"
		continue

	ok = False
	for i in xrange(len(firsts), -1, -1):
		if ok: 
			break
		for c in combinations(titles, i):
			if check_solution(firsts, seconds, diff(titles, c), c):
				print str(i)
				ok = True
				break
	if ok:
		continue
