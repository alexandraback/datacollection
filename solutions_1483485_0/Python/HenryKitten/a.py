original = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv"
translated = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up"

m = {}
m['q'] = 'z'
m['z'] = 'q'
for i in range(len(original)):
	m[original[i]] = translated[i]
#print len(m)
#print sorted(m.keys())
#print sorted(m.values())

#print m
n =  raw_input()
for t in range(1,int(n)+1):
	print "Case #" + str(t) + ":",
	line = raw_input()

	trans_line = ""
	for x in line:
		trans_line += m[x]	
	print trans_line
