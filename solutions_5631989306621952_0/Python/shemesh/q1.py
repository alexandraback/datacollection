def func(S):
	out_s = ''
	for c in S:
		if len(out_s) == 0:
			out_s += c
		elif ord(c)>=ord(out_s[0]):
			out_s = c + out_s
		else:
			out_s += c

	return out_s

	
T = int(raw_input())
for i in range(T):
	S = raw_input()
	print 'Case #%d: %s' % (i+1, func(S))