# A-small
i = open("A-small-attempt0.in", "r")
o = open("A-small.out", "w")

T = int(i.readline())
vowels = ['a', 'e', 'i', 'o', 'u']

def isn(s, n):
	strs = [s]
	for vowel in vowels:
		newstrs = []
		for x in strs:
			newstrs += x.split(vowel)
		strs = newstrs
	for x in strs:
		if len(x) >= n:
			return True
	return False

for c in range(1, T + 1):
	L, n = i.readline().replace('\n','').split()
	n = int(n)
	
	nvalue = 0
	for p in range(len(L)):
		for q in range(len(L)+1):
			subs = L[p:q]
			#print subs
			if subs != "" and isn(subs, n):
				nvalue += 1	
				
	o.write("Case #{0}: {1}\n".format(c, nvalue))

i.close()
o.close()