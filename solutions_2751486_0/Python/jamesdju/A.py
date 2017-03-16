import re
vows = set(["a","i","u","e","o"])

tc = int(raw_input())

for c in xrange(tc):
	word, n = raw_input().split()
	count = 0
	rgx = r'[^aieou]'
	for i in xrange(len(word)-int(n)+1):
		for j in xrange(i+int(n), len(word)+1):
			sub = word[i:j]
			rr = rgx + '{' + n + '}'
			#print sub, rr
			if re.search(rr, sub):
				count += 1

	print "Case #%d: %d" % (c+1, count)