for t in xrange(1, int(raw_input()) + 1):
	s = raw_input()
	o = s[0]
	for ch in s[1:]:
		if ord(ch) < ord(o[0]):
			o = o + ch
		else:
			o = ch + o
	print "Case #{}: {}".format(t, o)