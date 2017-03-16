t = int(raw_input())
hash = [ 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q', ]

for T in range(t):
	s = str(raw_input())
	s2 = ""
	
	for i in range(len(s)):
		if s[i]==' ':
			s2 += s[i]
		else:
			s2 += hash[ord(s[i])-ord('a')]
	
	print "Case #" + str(T+1) + ": " + s2
	