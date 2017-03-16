# reverse mappings
d = {}
s1 = "yeqz ejp mysljylc kd kxveddknmc re jsicpdrysi"
s2 = "aozq our language is impossible to understand"

s3 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
s4 = "there are twenty six factorial possibilities"

s5 = "de kr kd eoya kw aej tysr re ujdr lkgc jv"
s6 = "so it is okay if you want to just give up"
for ch in range(len(s2)):
	d[s1[ch]] = s2[ch]

for ch in range(len(s3)):
	d[s3[ch]] = s4[ch]

for ch in range(len(s5)):
	d[s5[ch]] = s6[ch]
#print len(d)
#print d
#for i in range(26):
#	print chr(i+ord('a')),
#	print d[chr(i+ord('a'))]
f = open("A.in")
i = 1
f.readline()
for line in f:
	buffer = ""
	for ch in line:
		if ch in d:
			buffer += d[ch]
		else:
			buffer += ch
	print "Case #"+ str(i) + ": " + buffer,
	i += 1