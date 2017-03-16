import string, re

def modfact(n, modulo=1000000007):
	result = 1
	for i in range(1, n+1):
		result = (result * i) % modulo
	return result

T = int(input())
for I in range(1, T+1):
	N = int(input())
	cars = input().split(" ")
	
	starts, ends, mids = [], [], []
	for i in range(0, 26):
		starts.append([])
		ends.append([])
		mids.append([])
	
	for char in string.ascii_lowercase:
		startonly = "^%s+[^%s]+$" % (char, char)
		bothends = "^%s+$" % (char)
		endonly = "^[^%s]+%s+$" % (char, char)
		
#		print(startonly + " " + bothends + " " + endonly)
		
		for i in range(0, len(cars)):
			cars[i] = re.sub(r'([a-z])\1+', r'\1', cars[i])
			s = cars[i]
			if re.match(bothends, s):
				mids[ord(char) - ord('a')].append(i)
			elif re.match(startonly, s):
				starts[ord(char) - ord('a')].append(i)
			elif re.match(endonly, s):
				ends[ord(char) - ord('a')].append(i)

#	print("Starts: %s" % starts)
#	print("Ends: %s" % ends)
#	print("Mids: %s" % mids)
	
	insideChars = set()
	possible = True
	for s in cars:
		if len(s) < 2:
			continue
		tmp = s[1:-1].replace(s[0], '').replace(s[-1],'')
		if len(tmp) > 0:
			for c in tmp:
				if c in insideChars:
					possible = False
				insideChars.add(c)
	for s in cars:
		count = [0]*26
		for i in range(0, len(s)):
			count[ord(s[i])-ord('a')] += 1
			if count[ord(s[i])-ord('a')] > 1:
				possible = False
				break
	
	rem = set(range(0, N))
	for i in range(0, 26):
		if len(starts[i]) > 1:
			possible = False
		if len(ends[i]) > 1:
			possible = False
		for n in mids[i]:
			rem.remove(n)
	for i in insideChars:
		if len(starts[ord(i)-ord('a')]) or len(ends[ord(i)-ord('a')]) or len(mids[ord(i)-ord('a')]) > 0:
			possible = False
			break
			
	if possible:
		combs = []
		while (len(rem) > 0):
			st = next(iter(rem))
			rem.remove(st)
			comb = cars[st]
			# to the left
			while len(ends[ord(comb[0]) - ord('a')]) > 0:
				val = ends[ord(comb[0]) - ord('a')][0]
				comb = cars[val] + comb
				if (not (val in rem)):
					possible = False
					break
				rem.remove(val)
			if not possible:
				break
			# to the right
			while len(starts[ord(comb[-1]) - ord('a')]) > 0:
				val = starts[ord(comb[-1]) - ord('a')][0]
				comb += cars[val]
				if (not (val in rem)):
					possible = False
					break
				rem.remove(val)
			combs.append(comb)
		
		if not possible:
			result = 0
		else:
			result = 1
		for ch in string.ascii_lowercase:
			free = True
			for c in combs:
				if ch in c:
					free = False
#			print("%s --> %d (%s)" % (ch, len(mids[ord(ch)-ord('a')]), free))
			result *= modfact(len(mids[ord(ch)-ord('a')]))
			if free and len(mids[ord(ch)-ord('a')]) > 0:
				combs.append(ch*len(mids[ord(ch)-ord('a')]))
#		print("Combs: %s" % combs)
		
		result *= modfact(len(combs))

		print("Case #%d: %d" % (I,result))
	else:
		print("Case #%d: %d" % (I,0))