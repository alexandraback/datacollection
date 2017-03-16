import sys
trans = {'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd',
 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'p': 'r',
 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm'}

# lines = (line for line in sys.stdin)
# for i in range(3):
# 	org = lines.next().split()
# 	dst = lines.next().split()
# 	if(len(org) != len(dst)):
# 		print "Len Not EQU!"
# 		print org
# 		print dst
# 		sys.exit(1)
# 	for w1, w2 in zip(org, dst):
# 		for x, y in zip(w1, w2):
# 			if(x in trans) and (y != trans[x]):
# 				print "Not consistent", x, y, trans[y]
# 				sys.exit(1)
# 			trans[x] = y
# 
# print trans
# print len(trans)
# for i in range(26):
# 	if chr(ord('a') + i) not in trans:
# 		print chr(ord('a') + i), "not in key"
# 	if chr(ord('a') + i) not in trans.values():
# 		print chr(ord('a') + i), "not in values"

trans['q'] = 'z'
trans['z'] = 'q'

f = open('A-small-attempt1.in')
res = open('Asmall.out', 'w')

T = int(f.readline().strip())

for i in range(T):
	q = f.readline()
	a = ''.join([trans[x] if x in trans else x for x in q])
	res.write('Case #%d: %s' % (i + 1, a))

f.close()
res.close()
