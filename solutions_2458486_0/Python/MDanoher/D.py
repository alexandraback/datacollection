
keys_owned = [0] * 201
opened_with = [0] * 201
opened = [False] * 201
contained_keys = [ [] ] * 201

seen = {}

def search(chest, leftToOpen, totalChests, path):
	if leftToOpen == 0:
		return [chest]
	if tuple(sorted(path)) in seen:
		return None
	seen[tuple(sorted(path))] = True
	
	for c in range(1,totalChests+1):
		if not opened[c] and keys_owned[opened_with[c]] > 0:
			keys_owned[opened_with[c]] -= 1
			opened[c] = True
			for key in contained_keys[c]:
				keys_owned[key] += 1
			
			result = search(c, leftToOpen-1, totalChests, path+[c])
			if result:
				return [chest] + result
			
			keys_owned[opened_with[c]] += 1
			opened[c] = False
			for key in contained_keys[c]:
				keys_owned[key] -= 1
	
	return None

def case():
	k,n = map(int,input().split())
	
	for i in range(201):
		keys_owned[i] = 0
		opened[i] = False
	
	for key in map(int,input().split()):
		keys_owned[key] += 1
	
	for chest in range(1,n+1):
		contents = list(map(int,input().split()))
		opened_with[chest] = contents[0]
		contained_keys[chest] = contents[2:]
	
	seen.clear()
	
	result = search(0, n, n, [])
	
	if result:
		return " ".join(map(str,result[1:]))
	else:
		return "IMPOSSIBLE"


for t in range(1,int(input())+1):
	print ( "Case #%d: %s" % (t,case()) )

