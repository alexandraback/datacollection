ex = [("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand"),
("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","there are twenty six factorial possibilities"),
("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up")]

M = {}
M['z']='q'
M['q']='z'

for a,b in ex:
	for p,q in zip(a,b):
		M[p]=q
	

z = input()
for testcase in range(1,z+1):
	print "Case #%d:" % testcase,
	t = raw_input()
	print ''.join(map(lambda x: x if x not in M else M[x], t))
