def good_path(chests,path,start_keys):
	keys = start_keys[:]
	for p in path:
		ti,c = chests[p]
		if not ti in keys:
			return False
		keys.remove(ti)
		keys.extend(c)
	return True

def search(closed,dict,chests,cur_keys,n):
	if closed in dict:
		return dict[closed]
	else:
		r = dict[closed] = _search(closed,dict,chests,cur_keys,n)
		return r

def _search(closed,dict,chests,cur_keys,n):
	if n == 0:
		return []
	for i in range(n):
		o = ord(closed[i])
		ti,c = chests[o]
		if cur_keys[ti] > 0:
			cur_keys[ti] -= 1
			for key in c:
				cur_keys[key] += 1
			s = search(closed[:i]+closed[i+1:],dict,chests,cur_keys,n-1)
			cur_keys[ti] += 1
			for key in c:
				cur_keys[key] -= 1
			if s != None:
				return [o] + s
	return None

def solve():
	k,n = map(eval,raw_input().split())
	keys = map(eval,raw_input().split())
	chests = []
	for i in range(n):
		c = map(eval,raw_input().split())
		ti = c[0]
		ki = c[1]
		c = c[2:]
		chests.append((ti,c))
	start_keys = [0]*200
	for key in keys:
		start_keys[key] += 1
	p = search(''.join(map(chr,range(n))),{},chests,start_keys,n)
	if p == None:
		return 'IMPOSSIBLE'
	else:
		#print good_path(chests,p,keys)
		return ' '.join(map(lambda x:str(x+1),p))
	
n_cases = input()
for case in range(1,n_cases+1):
	print 'Case #'+`case`+': '+solve()