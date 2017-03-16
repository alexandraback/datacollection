from itertools import permutations
from math import factorial
from sys import exit

def is_valid(s):
	last = None
	old = []
	for ch in s:
		if last is not None:
			if ch != last:
				if ch in old:
					return False
		old.append(ch)
		last = ch
	return True


def ref_solve(N, ts):
	count = 0
	for p in permutations(range(N)):
		s = ''.join([ts[i] for i in p])
		if is_valid(s):
			count += 1
	return count


def is_next(s, pch):
	if s[0] != pch:
		return False
	in_start = True
	for ch in s:
		if in_start:
			if ch != pch:
				in_start = False
		else:
			if ch == pch:
				return False
	return True


def solve(N, ts, chs_ts, idxs, first_ch, cache):
	key = tuple(idxs)
	if cache.has_key(key):
		return cache[key]
	res = solve_(N, ts, chs_ts, idxs, first_ch, cache)
	cache[key] = res
	# if len(idxs) <= 4:
	# 	ref_ts = [ts[i] for i in idxs]
	# 	ref_res = ref_solve(len(idxs), ref_ts)
	# 	if res != ref_res:
	# 		print 'ERROR!!'
	# 		print ref_ts
	# 		print ref_res
	# 		print res
	# 		exit(1)

	return res



def solve_(N, ts, chs_ts, idxs, first_ch, cache):
	if not idxs:
		return 1

	candidates = []
	if first_ch is not None:
		for i in range(len(idxs)):
			idx = idxs[i]
			t = ts[idx]
			if t[0] == first_ch:
				candidates.append(i)
	if not candidates:
		candidates = range(len(idxs))

	# print idxs, first_ch, candidates

	count = 0
	for i in candidates:
		idx_first = idxs[i]
		idxs_rest = idxs[0:i] + idxs[i+1:]
		first = ts[idx_first]
		ch = first[-1]
		rep_count = 0
		next = None
		left = []
		impossible = False
		for i_t in idxs_rest:
			t = ts[i_t]
			chs_t = chs_ts[i_t]
			if chs_t == {ch}:
				rep_count += 1
			elif is_next(t, ch):
				if next is None:
					next = t
				else:
					impossible = True
					break
			elif chs_ts[idx_first] & chs_ts[i_t]:
				impossible = True
				break
			else:
				left.append(i_t)

		if next:
			next_first_ch = next[-1]
		else:
			next_first_ch = first

		if not impossible:
			loc_count = factorial(rep_count) * solve(len(left), ts, chs_ts, left, next_first_ch, cache)
		else:
			loc_count = 0

		count += loc_count


		# print idxs, ' - ', i, ' => ', loc_count, ' - ', rep_count, ' - ', next, ' - ', left, ' - ', impossible

	return count









################################################################################


def read_ints(f):
	return [int(w) for w in f.readline().strip().split()]

def read_int(f):
	return int(f.readline().strip())


from sys import argv, setrecursionlimit

# setrecursionlimit(2200)

f = open(argv[1])

T = read_int(f);

for tcn in range(1, T+1):
	N = read_int(f)
	ts = f.readline().strip().split()
	cache = {}
	res = solve(N, ts, [set(t) for t in ts], range(N), None, cache)
	# res = ref_solve(N, ts)
	print 'Case #%s: %s' % (tcn, res)
