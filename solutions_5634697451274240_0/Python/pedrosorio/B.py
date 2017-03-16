from collections import deque

def eff_len(tup):
	for i in xrange(len(tup)-1, -1, -1):
		if not tup[i]:
			return i+1	
	return 0

def get_tuple(arr, n = None):
	if n is None:
		n = eff_len(arr)
	return tuple(arr[:n])	


def solve_simple(tup):
	if len(tup) == 0:
		return 0
	ct = 1
	for i in range(1, len(tup)):
		if tup[i] != tup[i-1]:
			ct += 1
	return ct

def solve(s):
	arr = [c == '+' for c in s]
	return solve_simple(get_tuple(arr))

T = int(raw_input())
for case in range(1, T+1):
	s = raw_input().strip()
	print "Case #{}: {}".format(case, str(solve(s)))

# bunch of test code for BFS
def get_flipped_tup(tup, n):
	return get_tuple([not(tup[n-i-1]) for i in range(n)] + list(tup[n:]))

def to_bin(tup):
	return ''.join(map(str, map(int, tup)))

def from_num(n):
	arr = []
	while n > 0:
		arr.append(n & 1 == 1)
		n >>= 1
	return get_tuple(arr)

def q_solve(tup, backtrack, visited):
	#print tup
	if len(tup) == 0:
		return 0
	visited.add(tup)
	q = deque([(tup, 0)])
	while q: 
		tup, mov = q.popleft() 
		mov += 1
		for flip in range(1, len(tup)+1):
			tup2 = get_flipped_tup(tup, flip)
			if tup2 in visited:
				continue
			#print flip, tup2
			if len(tup2) == 0:
				#print to_bin(tup)
				while tup in backtrack:
					tup = backtrack[tup]
					#print to_bin(tup)
				return mov 
			visited.add(tup2)
			backtrack[tup2] = tup
			q.append((tup2, mov))
