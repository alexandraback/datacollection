def kth_bit(s, k): return (1 if s & (1<<k) > 0 else 0)

def canUnlock(boxes, c_keys):
	global cache
	if cache.has_key(boxes): return cache[boxes]
	if boxes == 0:
		cache[boxes] = []
		return cache[boxes]
	cache[boxes] = None
	for i in range(n):
		if kth_bit(boxes, i) == 0: continue
		if c_keys[types[i]] == 0: continue
		c_keys[types[i]] -= 1
		# open i^th box
		for k in ks[i]: c_keys[k] += 1
		o = canUnlock(boxes & ~(1<<i), c_keys)
		if o is not None:
			o.append(i)
			cache[boxes] = o
			return cache[boxes]
		c_keys[types[i]] += 1
		# close i^th box
		for k in ks[i]: c_keys[k] -= 1
	return cache[boxes]

t = input()
for case_no in range(1, t+1):
	n, = map(int, raw_input().split()[1:])
	init_keys =  map(int, raw_input().split())
	cache = {}
	ks = []
	types = []
	for i in range(n):
		inp =  map(int, raw_input().split())
		t_i = inp[0]
		ks.append(inp[2:])
		types.append(t_i)
 	o = canUnlock((1<<n)-1, map(lambda x: init_keys.count(x), range(201)))
	print 'Case #%d:'  % case_no,
	if o is None:
		print 'IMPOSSIBLE'
	else:
		print ' '.join(map(lambda x: str(x+1), o[::-1]))